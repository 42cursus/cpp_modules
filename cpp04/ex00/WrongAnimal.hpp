/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:18:41 by abelov            #+#    #+#             */
/*   Updated: 2025/07/24 20:18:41 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip> // for std::setw, std::setfill
#include <sstream> // for std::ostringstream
#include <string>
#include <sys/types.h>

#define FT_DIM  	"\033[2m"       // Dim
#define FT_RED   	"\033[0;31m"
#define FT_GREEN 	"\033[0;32m"    // Green
#define FT_BLUE 	"\033[0;32m"    // Blue
#define FT_CYAN  	"\033[36m"
#define FT_WHITE_B 	"\033[1;38;5;15m"
#define FT_SALMON	"\033[38;5;210m"
#define FT_ORANGE	"\033[38;5;202m"
#define FT_PUMPKIN2		"\033[38;5;208m"
#define FT_SAND_TAN		"\033[38;5;180m"  // sandy beige
#define FT_LIGHT_BROWN	"\033[38;5;137m"  // more subdued brown-orange
#define FT_ASH_ORANGE	"\033[38;5;130m"  // dark muted orange
#define FT_STEEL_BLUE_B	"\033[1;38;5;67m"
#define FT_CADET_BLUE	"\033[38;5;72m"
#define FT_LIGHT_PURPLE	"\033[38;5;135m"
#define FT_HOT_PINK	"\033[38;5;197m"
#define FT_PALE_GREEN	"\033[38;5;114m"
#define FT_PALE_TURQUOISE4_B	"\033[1;38;5;66m"
#define FT_SEA_GREEN2_B	"\033[1;38;5;83m"
#define FT_DARK_SEA_GREEN4_B	"\033[1;38;5;71m"
#define FT_SOFT_GREEN "\033[38;5;108m"   // muted green (greenish gray)
#define FT_OLIVE_GREEN "\033[38;5;100m"  // olive tone
#define FT_DIM_GREEN   "\033[38;5;65m"   // darker, dull green
#define FT_BOLD_R	"\033[1;31m"    // Bold red
#define FT_BOLD_G	"\033[1;32m"    // Bold green
#define FT_BOLD_Y	"\033[1;33m"    // Bold yellow
#define FT_BOLD_C	"\033[1;36m"    // Bold cyan
#define FT_BOLD_W	"\033[1;37m"    // Bold white
#define FT_RST		"\033[0m"       // Reset to default color
#define CLASS_NAME_PADDING 13

// ************************************************************************** //
//                            WrongAnimal Class                               //
// ************************************************************************** //


class WrongAnimal
{
private:
	static const std::string _className;
	static const std::string _classLabel;
protected:
	std::string _type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal& operator=(const WrongAnimal& other);
	virtual ~WrongAnimal();
	void makeSound() const;
	static std::string buildClassLabel(const std::string& classname,
									   const char *colour);
	void setType(const std::string &type);
	std::string getType() const;
	virtual const std::string &getClassLabel() const;
};

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

#endif //WRONG_ANIMAL_HPP
