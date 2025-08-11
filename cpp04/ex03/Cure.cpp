/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:42:37 by abelov            #+#    #+#             */
/*   Updated: 2025/07/26 21:42:38 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/*
** -------------------------------- STATIC VARS -------------------------------
*/
const std::string Cure::_className = "Cure";
const std::string Cure::_classLabel = buildClassLabel(_className,
													  FT_PALE_TURQUOISE4_B);
const std::string Cure::MATERIA_TYPE = "cure";

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

Cure::Cure() : AMateria(MATERIA_TYPE)
{
	std::cout << _classLabel
			  << FT_DIM_GREEN"'default' constructor called" FT_RST << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	_type = MATERIA_TYPE;
	_materia_source = NULL;
	std::cout << _classLabel
			  << FT_DIM_GREEN"'copy' constructor called" << std::endl;
}

/*
** ------------------------------- DESTRUCTOR ---------------------------------
*/

Cure::~Cure()
{
	std::cout << _classLabel
			  << FT_LIGHT_BROWN"destructor" FT_RST << " called" << std::endl;
}


/*
** -------------------------------- OPERATORS ---------------------------------
*/

Cure &Cure::operator=(Cure other)
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

AMateria *Cure::clone() const
{
	AMateria *temp = new Cure(*this);
	temp->setMateriaSource(NULL);
	return temp;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getNameLabel() << "’s wounds *"
			  << std::endl;
}

/*
** -------------------------------- ACCESSORS ---------------------------------
*/
