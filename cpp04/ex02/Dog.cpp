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

Dog::Dog() : Animal(), _brain(new Brain())
{
	this->_type = "Dog";
	std::cout << _classLabel
			  << FT_DIM_GREEN"'default' constructor called" FT_RST << std::endl;

}

Dog::Dog(const Dog& other) : Animal(other), _brain(new Brain(*other._brain))
{
	_type = other._type;
	std::cout << _classLabel
			  << FT_DIM_GREEN"'copy' constructor called" << std::endl;

}

/*
** ------------------------------- DESTRUCTOR ---------------------------------
*/

Dog::~Dog()
{
	delete _brain;
	std::cout << _classLabel
			  << FT_LIGHT_BROWN"destructor" FT_RST << " called" << std::endl;
}

/*
** -------------------------------- OPERATORS ---------------------------------
*/

Dog &Dog::operator=(const Dog &other)
{
	std::cout << _classLabel
			  << "copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		if (!_brain)
			_brain = new Brain();
		*_brain = *other._brain;  // Deep copy
	}
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Dog::makeSound() const
{
	std::cout << _classLabel
			  << "says " << FT_BOLD_Y "Woof, woof!" FT_RST << std::endl;
}

/*
** -------------------------------- ACCESSORS ---------------------------------
*/

Brain *Dog::getBrain() const
{
	return _brain;
}

const std::string &Dog::getClassLabel() const
{
	return _classLabel;
}
