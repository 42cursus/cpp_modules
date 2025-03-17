/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:08:59 by abelov            #+#    #+#             */
/*   Updated: 2025/02/26 00:08:59 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef POINT_HPP
#define POINT_HPP


// ************************************************************************** //
//                                Point Class                                 //
// ************************************************************************** //

# include <ostream>
# include "Fixed.hpp"

# define FT_RED   "\033[0;31m"
# define FT_GREEN "\033[0;32m"
# define FT_CYAN  "\033[36m"
# define FT_RESET "\e[0m"
# define EPSILON 0.000001

class Point
{
private:
	/**
	 * "C++17 §7.1.6.1/5, C++20 §9.2.1/3"
	 * ISO/IEC 14882:1998, Section 7.1.5 "Type specifiers"
	 * 	7.1.5.1 "cv-qualifiers" (C++98): const can appear before or after
	 * 	the type specifier without changing its meaning.
	 * 	https://en.cppreference.com/w/cpp/language/cv
	 */
	const Fixed _x;
	Fixed const _y;

	// C++11 => `Point &operator=(Point const &other) = delete;`
	// Declare but do not define (C++98 idiom for deleted functions)


public:
	Point();
	Point &operator=(Point const &other);
	// https://clang.llvm.org/extra/clang-tidy/checks/readability/avoid-const-params-in-decls.html
	// const values in declarations do not affect the signature of a function, so they should not be put there.
	explicit Point(float [2]);
	Point(float x, float y);
	Point(const Point &other);
	Point(const Fixed& x, const Fixed& y);
	~Point();

	bool operator==(const Point &other) const;
	bool isEqual(const Point &other) const;

	const Fixed &getX() const;
	const Fixed &getY() const;

	float getXFloat() const;
	float getYFloat() const;

};

// https://www.roguebasin.com/index.php?title=Basic_BSP_Dungeon_generation
bool bsp(const Point& a, const Point& b, const Point& c, const Point& point);
float angle(const Point& p, const Point& a, const Point& b);
std::ostream& operator<<( std::ostream & o, Point const & i );

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

#endif //POINT_HPP
