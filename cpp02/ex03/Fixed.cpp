/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:10:32 by abelov            #+#    #+#             */
/*   Updated: 2025/03/10 00:07:32 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include "Fixed.hpp"

/**
 * For a Q24.8 fixed-point number (which is 24 integer bits and 8 frac bits),
 * the smallest possible difference between two distinct numbers is:
 * 	2^(−8)= 1/256 ~ 0.00390625
 * so an appropriate epsilon should be slightly larger than this
 * to account for rounding errors.
 *
 * A safe epsilon could be:
 * 		2^(−7)=1/128=0.0078125f
 * 	or
 * 		2^(−6)=1/64=0.015625f
 * 	depending on the required precision.
 */
const float Fixed::_epsilon = (1.0f / 128); // 2^(−7)
const float Fixed::_float_epsilon = __FLT_EPSILON__; // 1.19209289550781250000000000000000000e-7F

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

Fixed::Fixed() : _val(0)
{}


Fixed::Fixed(const Fixed &other) : _val()
{
	*this = other;
}

Fixed::Fixed(const int value)
{
	this->_val = value << _fracBits;
}

Fixed::Fixed(const float value)
{
	int val = 0;
	if (!std::isnan(value))
	{
		if (std::isinf(value))
			// Clamp to the representable range of int
			val = (value > 0) ? std::numeric_limits<int>::max()
							  : std::numeric_limits<int>::min();
		else
		{
			float d = roundf(value * (1 << _fracBits));
			if (std::isinf(d))
				// Clamp to the representable range of int
				val = (value > 0) ? std::numeric_limits<int>::max()
								  : std::numeric_limits<int>::min();
			else
				val = static_cast<int>(d);
		}
	}
	this->_val = static_cast<int>(val);
}

/*
** ------------------------------- DESTRUCTOR ---------------------------------
*/

Fixed::~Fixed()
{}

/*
** -------------------------------- OVERLOADS ---------------------------------
*/

/**
 * Copy assignment operator
 * @param other (const Fixed &other): other is passed as a const reference to:
 * 	Prevent unnecessary copying.
 * 	Ensure other is not modified inside operator=.
 * @return Fixed&: Returns a reference to the current object (*this)
 * 	to allow assignment chaining (a = b = c).
 */
Fixed &Fixed::operator=(const Fixed &other)
{
//	std::cout << "Copy assignment operator called" << std::endl;
	// Self-Assignment Check
	// Skipping self-assignment prevents unintended side effects like erasing
	// data when dealing with dynamically allocated resources.
	if (this != &other)
		_val = other.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &o, Fixed const &other)
{
	o << other.toFloat();
	return o;
}

//overload of the arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed fix;
	fix._val = (_val + other._val);
	return fix;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed fix;
	fix._val = (_val - other._val);
	return fix;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	float mul = toFloat() * other.toFloat();
	return Fixed(mul);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	float div = floatDivManual(toFloat(),other.toFloat());
	return Fixed(div);
}

Fixed &Fixed::operator++()
{
	this->_val++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--()
{
	this->_val--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

//overload of the comparison operators
bool Fixed::operator>(const Fixed &other) const
{
	return _val > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const
{
	return _val < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const
{
	return _val >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const
{
	return _val <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const
{
	return _val == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const
{
	return _val != other.getRawBits();
}

/*
** --------------------------------- METHODS ----------------------------------
*/

Fixed Fixed::div(const Fixed &other) const
{
	return Fixed(toFloat() / other.toFloat());
}

float Fixed::floatDivManual(const float &a, const float &b)
{
	FloatBits fl1 = {.f = a};
	FloatBits fl2 = {.f = b};

	// Extract components
	int signA = (fl1.u >> 31) & 1;
	int signB = (fl2.u >> 31) & 1;

	// Compute the sign of the result
	int sign = signA ^ signB;

	/* divide by zero??? */
	if (!fl2.l)
	{
		/* return NaN or -NaN */
		fl1.l = sign ? INT_MIN : INT_MAX;
		return (fl1.f); // or just `return (sign ? 0xFFFFFFFF : 0x7FFFFFFF);`
	}

	/* numerator zero??? */
	if (!fl1.l)
		return (0.0f);


	int exponentA = ((fl1.u >> IEEE754_FRACBITS) & 0xFF) - IEEE754_BIAS;
	int exponentB = ((fl2.u >> IEEE754_FRACBITS) & 0xFF) - IEEE754_BIAS;

	// Compute new exponent
	int resultExponent = exponentA - exponentB + (IEEE754_BIAS - 1);

	// 0b10000000 00000000 00000000 - implicit leading 1 (0x00800000)
	// 0b01111111 11111111 11111111 - mask (0x007fffff)
	fl1.l = (fl1.u & 0x7FFFFF) | (IEEE754_IMPLICIT_ONE);
	fl2.l = (fl2.u & 0x7FFFFF) | 0x800000;  // Add implicit 1

	uint32_t quotient = 0;
	int32_t mask = 0x1000000;

	// Perform fixed-point division (long division)
	for (int i = 0; i < 24; i++)
	{
		if (fl1.l >= fl2.l)
		{
			quotient |= mask;
			fl1.l -= fl2.l;
		}
		fl1.l <<= 1;
		mask >>= 1;
	}

	/* round */
	quotient += 1;

	/* normalize down */
	resultExponent++;
	quotient >>= 1;

	quotient &= ~IEEE754_IMPLICIT_ONE;

	// Pack result into IEEE 754 format
	uint32_t resultBits = (sign << 31)
						  | ((resultExponent & 0xFF) << IEEE754_FRACBITS)
						  | (quotient & 0x7FFFFF);

	// Convert back to float
	fl1.l = resultBits;
	return (fl1.f);
}

float Fixed::intToFloatManual(int x)
{
	if (x == 0) return 0.0f; // Zero case (special case)

	float result;
	int float_bits;

	int sign;
	int exponent;
	int mantissa;
	int shift;

	sign = (x < 0) ? INT_MIN : 0;    // Sign bit
	int abs_x = (x < 0) ? -x : x;        // Absolute value

	// Find the position of the highest set bit (index of MSB)
	for (shift = 31; (abs_x & (1U << shift)) == 0; shift--);

	// Compute exponent (bias 127 + shift index)
	exponent = IEEE754_BIAS + shift;

	// Normalize mantissa (remove leading 1, shift left to fill 23-bit space)
	mantissa = (abs_x << (31 - shift)) & INT_MAX; // Align MSB to bit 31
	mantissa = mantissa >> 8; // Drop the implicit leading 1

	float_bits = sign | (exponent << IEEE754_FRACBITS) | mantissa;

	// Assemble IEEE 754 binary representation
	std::memcpy(&result, &float_bits, sizeof(result));
	return (result);
}

int Fixed::floatToIntManual(float f)
{
	uint32_t bits;
	uint32_t sign;
	int exponent;
	int32_t shift; // shift amount for normalization
	uint32_t mantissa;

	std::memcpy(&bits, &f, sizeof(bits));

	sign = (bits >> 31) & 1;
	exponent = (((bits >> IEEE754_FRACBITS) & 0xFF) - IEEE754_BIAS);

	// Extract mantissa (bits 22-0) and restore the implicit leading 1
	// 0b01111111 11111111 11111111 - mask					(0x007fffff)
	// 0b10000000 00000000 00000000 - implicit leading one	(0x00800000)
	mantissa = (bits & 0x007fffff) | 0x800000;

	// Align mantissa to 30-bit position for easier shifting
	mantissa <<= 7;

	// Compute shift: we need to scale the mantissa back to integer range
	shift = -(exponent - 29);

	// If the exponent is too small, shift right to scale down the value
	if (shift > 0)
	{
		if (shift < 31)
			mantissa >>= shift; // Normal case: shift right by the calculated amount
		else
			mantissa = 0; // If shift is too large, result is zero (underflow)
	}
	return (sign ? -mantissa : mantissa);
}

/**
 * Suppose _bits = 8, and _val = 13075.
 * Binary representation:
 * 	00000000 00000000 00110011 00001011  (13075 in decimal)
 * Breaking it down:
 * 	Integer part: 00110011 (51 in decimal)
 * 	Fractional part: 00001011 (decimal 11)
 *
 * Example:
 * 	00000000 00000000 00110011 00010011  // _val (13075)
 * 	00000000 00000000 00000001 00000000  // resolution (256)
 * 	00000000 00000000 00000000 11111111  // mask (255)
 * 	------------------------------------
 * 	00000000 00000000 00000000 00010011  // fractional_part = 19
 * 	and
 * 	00000000 00000000 00000000 00110011  // integer_part = 51
 * @return
 */
float Fixed::toFloat() const
{

	int resolution = (1 << _fracBits);
	int mask = resolution - 1;
	int integer_part = _val >> _fracBits;    // Extract integer part
	int fractional_part = _val & mask;        // Extract lower 8 bits

	float fraction = floatDivManual(intToFloatManual(fractional_part),
									intToFloatManual(resolution));
	return intToFloatSSE(integer_part) + fraction;
}

int Fixed::toInt() const
{
	return (_val >> _fracBits);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

Fixed const &Fixed::min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

Fixed const &Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
}

Fixed Fixed::abs() const
{
	Fixed ret;
	if (this->_val < 0)
		ret._val = -1 * (this->_val);
	else
		ret._val = this->_val;
	return (ret);
}

/*
** -------------------------------- ACCESSORS ---------------------------------
*/

void Fixed::setRawBits(const int raw)
{
	this->_val = raw;
}

int Fixed::getRawBits() const
{
	return _val;
}

float Fixed::getEpsilon()
{
	return _epsilon;
}
