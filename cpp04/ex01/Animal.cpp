/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:30:05 by abelov            #+#    #+#             */
/*   Updated: 2025/07/23 15:30:06 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*
** -------------------------------- STATIC VARS -------------------------------
*/

const std::string Animal::_className = "Animal";
const std::string Animal::_classLabel = buildClassLabel(_className,
														FT_PALE_TURQUOISE4_B);

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

Animal::Animal() : _type("none")
{
	std::cout << _classLabel
			  << FT_DIM_GREEN"'default' constructor called" FT_RST << std::endl;

}

Animal::Animal(const std::string &type) : _type(type)
{
	std::cout << _classLabel
			  << FT_DIM_GREEN"'type' constructor called" << std::endl;
}


Animal::Animal(const Animal &other) : _type(other._type)
{
	std::cout << _classLabel
			  << FT_DIM_GREEN"'copy' constructor called" << std::endl;
}

/*
** ------------------------------- DESTRUCTOR ---------------------------------
*/

Animal::~Animal()
{
	std::cout << _classLabel
			  << FT_LIGHT_BROWN"destructor" FT_RST << " called" << std::endl;
}

/*
** -------------------------------- OPERATORS ---------------------------------
*/

/**
 * Copy assignment operator
 * https://en.cppreference.com/w/cpp/language/as_operator.html
 * @param other
 * @return
 */
Animal& Animal::operator=(const Animal& other)
{
	std::cout << _classLabel
			  << "copy assignment operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Animal::makeSound() const
{
	std::cout << _classLabel
			  << FT_DIM"says .... nothing..." FT_RST << std::endl;
}

std::string Animal::buildClassLabel(const std::string& classname,
									const char *colour)
{
	std::ostringstream oss;
	oss << std::left << std::setw(CLASS_NAME_PADDING) << (classname + ":");

	std::string label = oss.str();
	label.insert(0, colour);
	label.insert(classname.length() + std::strlen(colour), FT_RST);
	return label;
}

/*
** -------------------------------- ACCESSORS ---------------------------------
*/

std::string Animal::getType() const
{
	return _type;
}

void Animal::setType(const std::string &type)
{
	_type = type;
}

const std::string &Animal::getClassLabel() const
{
	return _classLabel;
}
