/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:55:13 by abelov            #+#    #+#             */
/*   Updated: 2025/02/25 23:55:14 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

// ************************************************************************** //
//                                Fixed Class                                 //
// ************************************************************************** //

class Fixed
{
private:
	int					_val;
	static const int	_bits;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);

	// When a const object calls a member function,
	// that function must not modify the object.
	// To enforce this, C++ requires the function to be marked const.
	// The compiler enforces const correctness by not allowing non-const
	// member functions to be called on const objects.
	int getRawBits() const;
	void setRawBits(int raw);
};

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

#endif //FIXED_HPP
