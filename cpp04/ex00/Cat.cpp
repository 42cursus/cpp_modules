/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:29:51 by abelov            #+#    #+#             */
/*   Updated: 2025/07/23 15:29:52 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
** -------------------------------- STATIC VARS -------------------------------
*/

const std::string Cat::_className = "Cat";
const std::string Cat::_classLabel = buildClassLabel(_className,
														FT_PALE_TURQUOISE4_B);

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << _classLabel
			  << FT_DIM_GREEN" 'default' constructor called" FT_RST << std::endl;

}

Cat::Cat(const Cat& other) : Animal(other)
{
	_type = other._type;
	std::cout << _classLabel
			  << FT_DIM_GREEN" 'copy' constructor called" << std::endl;

}

/*
** ------------------------------- DESTRUCTOR ---------------------------------
*/

Cat::~Cat()
{
	std::cout << _classLabel
			  << FT_LIGHT_BROWN" destructor" FT_RST << " called" << std::endl;
}

/*
** -------------------------------- OPERATORS ---------------------------------
*/

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Cat::makeSound() const
{
	std::cout << _classLabel
			  << FT_BOLD_Y "says Meow!" FT_RST << std::endl;
}

/*
** -------------------------------- ACCESSORS ---------------------------------
*/


const std::string &Cat::getClassLabel() const
{
	return _classLabel;
}