/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:54:05 by abelov            #+#    #+#             */
/*   Updated: 2025/07/26 21:54:06 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/*
** -------------------------------- STATIC VARS -------------------------------
*/
const std::string MateriaSource::_className = "MateriaSource";
const std::string MateriaSource::_classLabel = buildClassLabel(_className,
															   FT_PALE_TURQUOISE4_B);

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

MateriaSource::MateriaSource() : IMateriaSource()
{
	for (int i = 0; i < (int) INVENTORY_SIZE; i++) this->_inventory[i] = NULL;
	std::cout << _classLabel
			  << FT_DIM_GREEN"'default' constructor called" FT_RST << std::endl;
}

MateriaSource::MateriaSource(const std::string &name) : _name(name)
{
	for (int i = 0; i < (int) INVENTORY_SIZE; i++) this->_inventory[i] = NULL;
	std::cout << _classLabel
			  << FT_DIM_GREEN"'name' constructor called" FT_RST << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other) : IMateriaSource(other)
{
	for (int i = 0; i < (int) INVENTORY_SIZE; i++)
	{
		if (other._inventory[i])
		{
			this->_inventory[i] = other._inventory[i]->clone();
			this->_inventory[i]->setMateriaSource(this);
		}
		else
			this->_inventory[i] = NULL;
	}
	std::cout << _classLabel
			  << FT_DIM_GREEN"'copy' constructor called" << std::endl;
}

/*
** ------------------------------- DESTRUCTOR ---------------------------------
*/

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < (int) INVENTORY_SIZE; i++)
		if (this->_inventory[i]) delete this->_inventory[i];
	std::cout << _classLabel
			  << FT_LIGHT_BROWN"destructor" FT_RST << " called" << std::endl;
}

/*
** -------------------------------- OPERATORS ---------------------------------
*/

void MateriaSource::swap(MateriaSource &first, MateriaSource &second)
{
	std::swap(first._inventory, second._inventory);
}

MateriaSource &MateriaSource::operator=(MateriaSource other)
{
	MateriaSource::swap(*this, other);
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

// Functions
void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = materia;
			materia->setMateriaSource(this);
			std::cout << "Materia source learned " << materia->getType() << "!"
					  << std::endl;
			return;
		}
	}
	std::cout << "Couldn't learn " << materia->getType()
			  << ", because materia source is full." << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 3; i >= 0; i--)
	{
		if (this->_inventory[i] && this->_inventory[i]->getType() == type)
		{
			std::cout << "Materia source creates " << type << std::endl;
			return this->_inventory[i]->clone();
		}
	}
	std::cout << "Materia source cannot create " << type << ". Not learned."
			  << std::endl;
	return NULL;
}


/*
** -------------------------------- ACCESSORS ---------------------------------
*/

AMateria *const *MateriaSource::getInventory() const
{
	return _inventory;
}

void MateriaSource::setInventory(int idx, AMateria *materia)
{
	_inventory[idx] = materia;
}

const std::string &MateriaSource::getClassLabel() const
{
	return _classLabel;
}

const std::string &MateriaSource::getName() const
{
	return _name;
}

const std::string &MateriaSource::getNameLabel() const
{
	return _nameLabel;
}
