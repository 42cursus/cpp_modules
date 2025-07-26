/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 23:37:47 by abelov            #+#    #+#             */
/*   Updated: 2025/07/24 23:37:48 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*
** -------------------------------- STATIC VARS -------------------------------
*/

const std::string WrongCat::_className = "WrongCat";
const std::string WrongCat::_classLabel = buildClassLabel(_className,
													 FT_PALE_TURQUOISE4_B);

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

WrongCat::WrongCat() : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << _classLabel
			  << FT_DIM_GREEN" 'default' constructor called" FT_RST << std::endl;

}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	_type = other._type;
	std::cout << _classLabel
			  << FT_DIM_GREEN" 'copy' constructor called" << std::endl;

}

/*
** ------------------------------- DESTRUCTOR ---------------------------------
*/

WrongCat::~WrongCat()
{
	std::cout << _classLabel
			  << FT_LIGHT_BROWN" destructor" FT_RST << " called" << std::endl;
}

/*
** -------------------------------- OPERATORS ---------------------------------
*/

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		WrongAnimal::operator=(other);
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongCat::makeSound() const
{
	std::cout << _classLabel
			  << FT_BOLD_Y "says Meow???" FT_RST << std::endl;
}

/*
** -------------------------------- ACCESSORS ---------------------------------
*/

const std::string &WrongCat::getClassLabel() const
{
	return _classLabel;
}
