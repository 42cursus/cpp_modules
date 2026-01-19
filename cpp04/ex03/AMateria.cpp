/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 23:55:17 by abelov            #+#    #+#             */
/*   Updated: 2025/07/24 23:55:17 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/*
** -------------------------------- STATIC VARS -------------------------------
*/

const std::string AMateria::_className = "AMateria";
const std::string AMateria::_classLabel = buildClassLabel(_className,
														  FT_PALE_TURQUOISE4_B);

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

AMateria::AMateria() : _type("")
{
	this->_materia_source = NULL;
	std::cout << _classLabel
			  << FT_DIM_GREEN"'default' constructor called" << std::endl;
}


AMateria::AMateria(const std::string &type) : _type(type)
{
	this->_materia_source = NULL;
	std::cout << _classLabel
			  << FT_DIM_GREEN"'tag' constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other) : _type(other._type)
{
	_materia_source = NULL;
	std::cout << _classLabel
			  << FT_DIM_GREEN"'copy' constructor called" << std::endl;
}

/*
** ------------------------------- DESTRUCTOR ---------------------------------
*/

AMateria::~AMateria()
{
	std::cout << _classLabel
			  << FT_LIGHT_BROWN"destructor" FT_RST << " called" << std::endl;
}

/*
** -------------------------------- OPERATORS ---------------------------------
*/

AMateria &AMateria::operator=(const AMateria &other)
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

std::string AMateria::buildClassLabel(const std::string &classname,
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

std::string const &AMateria::getType() const
{
	return _type;
}

MateriaSource *AMateria::getMateriaSource() const
{
	return _materia_source;
}

void AMateria::setMateriaSource(MateriaSource *materia_source)
{
	_materia_source = materia_source;
}

