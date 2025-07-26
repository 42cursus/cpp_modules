/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:29:51 by abelov            #+#    #+#             */
/*   Updated: 2025/07/26 21:19:38 by abelov           ###   ########.fr       */
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

Cat::Cat() : Animal(), _brain(new Brain())
{
	this->_type = "Cat";
	std::cout << _classLabel
			  << FT_DIM_GREEN"'default' constructor called" FT_RST << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain))
{
	_type = other._type;
	std::cout << _classLabel
			  << FT_DIM_GREEN"'copy' constructor called" << std::endl;
}

/*
** ------------------------------- DESTRUCTOR ---------------------------------
*/

Cat::~Cat()
{
	delete _brain;
	std::cout << _classLabel
			  << FT_LIGHT_BROWN"destructor" FT_RST << " called" << std::endl;
}

#ifdef __clang__
#  pragma clang diagnostic push
#  pragma ide diagnostic ignored "modernize-use-nullptr"
#endif

/*
** -------------------------------- OPERATORS ---------------------------------
*/

Cat &Cat::operator=(const Cat &other)
{
	std::cout << _classLabel
			  << "copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);

		if (_brain)
		{
			delete _brain;
			_brain = NULL;
		}
		if (other._brain)
			_brain = new Brain(*other._brain);  // Deep copy
	}
	return (*this);
}

#ifdef __clang__
#  pragma clang diagnostic pop
#endif


/*
** --------------------------------- METHODS ----------------------------------
*/

void Cat::makeSound() const
{
	std::cout << _classLabel
			  << "says " << FT_BOLD_Y "Meow!" FT_RST << std::endl;
}

/*
** -------------------------------- ACCESSORS ---------------------------------
*/

Brain *Cat::getBrain() const
{
	return _brain;
}

const std::string &Cat::getClassLabel() const
{
	return _classLabel;
}
