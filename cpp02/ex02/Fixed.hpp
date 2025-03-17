/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:10:24 by abelov            #+#    #+#             */
/*   Updated: 2025/02/26 00:10:25 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <cstring>
#include <climits>
#include <iostream>
#include <inttypes.h>
#include <stdint.h>

// ************************************************************************** //
//                                Fixed Class                                 //
// ************************************************************************** //

#define IEEE754_BIAS 127 // 0x80
#define IEEE754_FRACBITS 23
#define IEEE754_IMPLICIT (1 << IEEE754_FRACBITS)

/**
 * A "fixed point Q24.8 format" refers to a binary fixed-point number
 * representation where the data is stored in a 32-bit word with 24 bits
 * dedicated to the integer part and 8 bits representing the fractional part;
 * https://en.wikipedia.org/wiki/Q_(number_format)
 *
 * Notation:
 * 	 "Q" stands for "Quantized" and the "24.8" indicates 24 integer bits
 * 	 and 8 fractional bits.
 *
 * Mathematically:
 * 	Stored Value = (Integer part * 2^nbits) + Fractional part
 */
class Fixed
{
private:
	// _val stores the fixed-point value in a Q24.8 format:
	//	The higher 24 bits store the integer part.
	//	The lower 8 bits store the fractional part.
	int					_val;
	static const int	_fracBits = 8; // _bits remains a compile-time constant.
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &other);
	explicit Fixed(int value);
	explicit Fixed(float value);
	Fixed& operator=(const Fixed& other);

	static float intToFloatX87(int x);
	static float intToFloatSSE(int x);
	static float intToFloatManual(int x);

	static int floatToIntX87(float f);
	static int floatToIntSSE(float f);
	static int floatToIntManual(float f);

	int getRawBits() const;
	void setRawBits(int raw);

	float toFloat() const;
	int toInt() const;

	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	Fixed static const &max(const Fixed &a, const Fixed &b);
	Fixed static const &min(const Fixed &a, const Fixed &b);
	Fixed static &max(Fixed &a, Fixed &b);
	Fixed static &min(Fixed &a, Fixed &b);
};

std::ostream &operator<<(std::ostream &o, Fixed const &num);

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

#endif //FIXED_HPP
