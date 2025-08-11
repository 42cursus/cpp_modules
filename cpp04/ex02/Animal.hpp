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

#include <cstdio>	// IWYU pragma: export
#include <cstdlib>	// IWYU pragma: export
#include <cstring>	// IWYU pragma: export
#include <iostream>	// IWYU pragma: export
#include <iomanip>	// IWYU pragma: export
#include <sstream>	// IWYU pragma: export
#include <string>	// IWYU pragma: export
#include <sys/types.h> // IWYU pragma: export
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
