/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:30:14 by abelov            #+#    #+#             */
/*   Updated: 2025/07/23 15:30:15 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
** -------------------------------- STATIC VARS -------------------------------
*/

const std::string Dog::_className = "Dog";
const std::string Dog::_classLabel = buildClassLabel(_className,
													 FT_PALE_TURQUOISE4_B);

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	std::cout << _classLabel
			  << FT_DIM_GREEN" 'default' constructor called" FT_RST << std::endl;

}

Dog::Dog(const Dog& other) : Animal(other)
{
	_type = other._type;
	std::cout << _classLabel
			  << FT_DIM_GREEN" 'copy' constructor called" << std::endl;

}

/*
** ------------------------------- DESTRUCTOR ---------------------------------
*/

Dog::~Dog()
{
	std::cout << _classLabel
			  << FT_LIGHT_BROWN" destructor" FT_RST << " called" << std::endl;
}

/*
** -------------------------------- OPERATORS ---------------------------------
*/

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Dog::makeSound() const
{
	std::cout << _classLabel
			  << FT_BOLD_Y "says Woof! Woof!" FT_RST << std::endl;
}

/*
** -------------------------------- ACCESSORS ---------------------------------
*/


const std::string &Dog::getClassLabel() const
{
	return _classLabel;
}