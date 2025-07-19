/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:02:26 by abelov            #+#    #+#             */
/*   Updated: 2025/02/26 00:02:27 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

// ************************************************************************** //
//                                Fixed Class                                 //
// ************************************************************************** //

class Fixed
{
private:
	int					_val;
	static const int	_fracBits;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &other);
	explicit Fixed(int value);
	explicit Fixed(float value);
	Fixed& operator=(const Fixed& other);

	// When a const object calls a member function,
	// that function must not modify the object.
	// To enforce this, C++ requires the function to be marked const.
	// The compiler enforces const correctness by not allowing non-const
	// member functions to be called on const objects.
	int getRawBits() const;
	void setRawBits(int raw);

	float toFloat() const;
	int toInt() const;
};

std::ostream &operator << (std::ostream &o, Fixed const &num);

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

#endif //FIXED_HPP
