/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:54:37 by abelov            #+#    #+#             */
/*   Updated: 2025/03/09 22:54:37 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

Point::Point() : _x(), _y() {}
Point::Point(const float x, const float y) : _x(x), _y(y) {}
Point::Point(const Fixed& x, const Fixed& y) : _x(x), _y(y) {}
Point::Point(const Point &other) : _x(other._x), _y(other._y) {}
Point::Point(float mp[2]) : _x(mp[0]), _y(mp[1]) {}

/*
** ------------------------------- DESTRUCTOR ---------------------------------
*/

Point::~Point() {}

/*
** -------------------------------- OVERLOADS ---------------------------------
*/

/**
 * _x and _y are const members cannot be modified after initialization.
 * Once they are set in the constructor, they cannot be reassigned.
 * Assignment operator (operator=) is supposed to modify an existing object,
 * not recreate it.
 * The this->~Point() and placement new approach attempts to reconstruct
 * an object in place, which is dangerous and not standard practice in C++.
 */
Point &Point::operator=(const Point &other)
{
	this->~Point();
	return *new(this) Point(other._x, other._y);
}

bool Point::operator==(const Point &other) const
{
	return (this->getX() == other.getX() && this->getY() == other.getY());
}

/*
** --------------------------------- METHODS ----------------------------------
*/

bool Point::isEqual(const Point &other) const
{
	return (this->getX() == other.getX() && this->getY() == other.getY());
}

/*
** -------------------------------- ACCESSORS ---------------------------------
*/

const Fixed &Point::getX() const
{
	return _x;
}

const Fixed &Point::getY() const
{
	return _y;
}

float Point::getXFloat() const
{
	return _x.toFloat();
}

float Point::getYFloat() const
{
	return _y.toFloat();
}
