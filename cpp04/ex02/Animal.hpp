/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:29:44 by abelov            #+#    #+#             */
/*   Updated: 2025/07/26 21:19:26 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip> // for std::setw, std::setfill
#include <sstream> // for std::ostringstream
#include <string>
#include <sys/types.h>
#include "generic.h"

// ************************************************************************** //
//                               Animal Class                                 //
// ************************************************************************** //

/**
 * C++ Is it correct to call class member variables "attributes"?
 * https://stackoverflow.com/questions/18282330/
 * https://en.wikipedia.org/wiki/Method_%28computer_programming%29
 */
class Animal
{
private:
	static const std::string _className;
	static const std::string _classLabel;
protected:
	std::string _type;
public:
	static std::string buildClassLabel(const std::string& classname,
									   const char *colour);
	Animal();
	explicit Animal(const std::string& type);
	Animal(const Animal &other);
	virtual ~Animal();
	Animal &operator=(const Animal &other);
	void setType(const std::string &type);
	std::string getType() const;
	virtual void makeSound() const = 0; // prevents instantiation of the class

	virtual const std::string &getClassLabel() const;
};

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

#endif //ANIMAL_HPP
