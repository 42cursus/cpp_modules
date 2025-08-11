/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:42:00 by abelov            #+#    #+#             */
/*   Updated: 2025/07/26 21:42:01 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/*
** -------------------------------- STATIC VARS -------------------------------
*/

const std::string Ice::_className = "Ice";
const std::string Ice::_classLabel = buildClassLabel(_className,
													 FT_PALE_TURQUOISE4_B);
const std::string Ice::MATERIA_TYPE = "ice";


/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

Ice::Ice() : AMateria(MATERIA_TYPE)
{
	std::cout << _classLabel
			  << FT_DIM_GREEN"'default' constructor called" FT_RST << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	_type = MATERIA_TYPE;
	std::cout << _classLabel
			  << FT_DIM_GREEN"'copy' constructor called" << std::endl;
}


/*
** ------------------------------- DESTRUCTOR ---------------------------------
*/
Ice::~Ice()
{
	std::cout << _classLabel
			  << FT_LIGHT_BROWN"destructor" FT_RST << " called" << std::endl;
}

/*
** -------------------------------- OPERATORS ---------------------------------
*/


/*
** --------------------------------- METHODS ----------------------------------
*/


AMateria *Ice::clone() const
{
	AMateria *temp = new Ice(*this);
	temp->setMateriaSource(NULL);
	return temp;
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getNameLabel() << " *"
			  << std::endl;
}

/*
** -------------------------------- ACCESSORS ---------------------------------
*/


