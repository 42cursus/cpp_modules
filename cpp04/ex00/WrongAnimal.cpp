/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 23:39:07 by abelov            #+#    #+#             */
/*   Updated: 2025/07/24 23:39:07 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/*
** -------------------------------- STATIC VARS -------------------------------
*/

const std::string WrongAnimal::_className = "WrongAnimal";
const std::string WrongAnimal::_classLabel = buildClassLabel(_className,
														FT_PALE_TURQUOISE4_B);

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

WrongAnimal::WrongAnimal() : _type("none")
{
	std::cout << _classLabel
			  << FT_DIM_GREEN" 'default' constructor called" FT_RST << std::endl;

}

WrongAnimal::WrongAnimal(const std::string &type) : _type(type)
{
	std::cout << _classLabel
			  << FT_DIM_GREEN" 'tag' constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type)
{
	std::cout << _classLabel
			  << FT_DIM_GREEN" 'copy' constructor called" << std::endl;
}

/*
** ------------------------------- DESTRUCTOR ---------------------------------
*/

WrongAnimal::~WrongAnimal()
{
	std::cout << _classLabel
			  << FT_LIGHT_BROWN" destructor" FT_RST << " called" << std::endl;
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
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << _classLabel
			  << " copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;

	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/**
 * https://tvtropes.org/pmwiki/pmwiki.php/Main/SymbolSwearing
 * https://english.stackexchange.com/questions/86838/what-the-is-that-called
 */
void WrongAnimal::makeSound() const
{
	std::cout << _classLabel
			  << FT_DIM"says .... #$@&%!" FT_RST<< std::endl;
}

std::string WrongAnimal::buildClassLabel(const std::string& classname,
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

std::string WrongAnimal::getType() const
{
	return _type;
}

void WrongAnimal::setType(const std::string &type)
{
	_type = type;
}

const std::string &WrongAnimal::getClassLabel() const
{
	return _classLabel;
}
