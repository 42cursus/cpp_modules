/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:10:32 by abelov            #+#    #+#             */
/*   Updated: 2025/02/26 00:10:32 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _val(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_val = value << _fracBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_val = static_cast<int>(roundf(value * (1 << _fracBits)));
}

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
	std::cout << "Copy assignment operator called" << std::endl;
	// Self-Assignment Check
	// Skipping self-assignment prevents unintended side effects like erasing
	// data when dealing with dynamically allocated resources.
	if (this != &other)
		_val = other.getRawBits();
	return *this;
}

void Fixed::setRawBits(const int raw)
{
	this->_val = raw;
}

int Fixed::getRawBits() const
{
	return _val;
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
	int integer_part = _val >> _fracBits; // Extract integer part
	int fractional_part = _val & mask; // Extract lower 8 bits

	float fraction =
		static_cast<float>(fractional_part) / static_cast<float>(resolution);

	// If _val is negative, the fraction must be negative as well
	if (_val < 0) fraction = -fraction;

	return static_cast<float>(integer_part) + fraction;
}

int Fixed::toInt() const
{
	return (_val >> _fracBits);
}

std::ostream &operator<<(std::ostream &o, Fixed const &other)
{
	o << other.toFloat();
	return o;
}

//overload of the arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &num) const
{
	return Fixed(toFloat() * num.toFloat());
}

Fixed Fixed::operator/(const Fixed &num) const
{
	return Fixed(toFloat() / num.toFloat());
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
bool Fixed::operator>(const Fixed &num) const
{
	return _val > num.getRawBits();
}

bool Fixed::operator<(const Fixed &num) const
{
	return _val < num.getRawBits();
}

bool Fixed::operator>=(const Fixed &num) const
{
	return _val >= num.getRawBits();
}

bool Fixed::operator<=(const Fixed &num) const
{
	return _val <= num.getRawBits();
}

bool Fixed::operator==(const Fixed &num) const
{
	return _val == num.getRawBits();
}

bool Fixed::operator!=(const Fixed &num) const
{
	return _val != num.getRawBits();
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
