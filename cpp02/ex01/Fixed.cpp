/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:50:51 by abelov            #+#    #+#             */
/*   Updated: 2025/03/06 14:50:51 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fracBits = 8;

Fixed::Fixed() : _val(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
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
 *
 * @return
 */
float Fixed::toFloat() const
{
	int integer_part = _val >> _fracBits; // Extract integer part
	int fractional_part = _val & ((1 << _fracBits) - 1); // Extract lower 8 bits

	float fraction = static_cast<float>(fractional_part) / (1 << _fracBits);

	// If _val is negative, the fraction must be negative as well
	if (_val < 0) fraction = -fraction;

	return static_cast<float>(integer_part) + fraction;
//	return (static_cast<float>(_val) / (1 << _fracBits));
}

int Fixed::toInt() const
{
	return (_val >> _fracBits);
}

std::ostream &operator<<(std::ostream &o, Fixed const &num)
{
	o << num.toFloat();
	return o;
}
