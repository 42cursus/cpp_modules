
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:53:35 by abelov            #+#    #+#             */
/*   Updated: 2025/07/26 21:53:36 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*
** -------------------------------- STATIC VARS -------------------------------
*/
const std::string Character::_className = "Character";
const std::string Character::_classLabel = buildClassLabel(_className,
														   FT_PALE_TURQUOISE4_B);
const std::string &Character::DEFAULT_NAME = "Anon";
const u_int Character::INVENTORY_SIZE;
AMateria *Character::_floor[50] = {NULL};

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

Character::Character() : _name(DEFAULT_NAME), _inventory()
{
	_nameLabel = buildNameLabel(_name, FT_WHITE_B);
	for (int i = 0; i < (int) INVENTORY_SIZE; i++) this->_inventory[i] = NULL;
	std::cout << _classLabel << _nameLabel
			  << FT_DIM_GREEN" 'default' constructor called" FT_RST
			  << std::endl;
}

Character::Character(const std::string &name) : _name(name), _inventory()
{
	_nameLabel = buildNameLabel(_name, FT_WHITE_B);
	for (int i = 0; i < (int) INVENTORY_SIZE; i++) this->_inventory[i] = NULL;
	std::cout << _classLabel << _nameLabel
			  << FT_DIM_GREEN" 'name' constructor called" FT_RST << std::endl;
}

Character::Character(const Character &other) : _name(other._name), _inventory()
{
	for (int i = 0; i < (int) INVENTORY_SIZE; i++)
	{
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	_nameLabel = buildNameLabel(_name, FT_WHITE_B);
	std::cout << _classLabel << _nameLabel
			  << FT_DIM_GREEN" 'copy' constructor called" << std::endl;
}

/*
** ------------------------------- DESTRUCTOR ---------------------------------
*/

Character::~Character()
{
	for (int i = 0; i < (int) INVENTORY_SIZE; i++)
		if (this->_inventory[i] != 0)
			delete this->_inventory[i];
	std::cout << _classLabel << _nameLabel
			  << FT_LIGHT_BROWN" destructor" FT_RST << " called" << std::endl;
}

/*
** -------------------------------- OPERATORS ---------------------------------
*/

Character &Character::operator=(const Character &other)
{
	std::cout << _classLabel << _nameLabel
			  << " copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_nameLabel = other._nameLabel;
	}
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string Character::buildNameLabel(const std::string &name,
									  const char *colour)
{
	std::string label = name;
	label.insert(0, colour);
	label.insert(name.length() + std::strlen(colour), FT_RST);
	return label;
}

void Character::equip(AMateria *materia)
{
	if (materia == 0)
	{
		std::cout << "Materia doesn't exist!" << std::endl;
		return;
	}
	if (materia->getMateriaSource() != 0)
	{
		std::cout << materia->getType()
				  << " is already equipped to a materia source. Can't equip it to "
					 "another slot!"
				  << std::endl;
		return;
	}
	// Search for empty slot to equip
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = materia;
			std::cout << this->getName() << " equipped " << materia->getType()
					  << ". (slot "
					  << i << ")" << std::endl;
			return;
		}
	}
	// If there is no empty slot in inventory it falls onto the ground
	for (int i = 0; i < 50; i++)
	{
		if (Character::_floor[i] == NULL)
		{
			_floor[i] = materia;
			std::cout << this->_name << "'s inventory is full. Can't equip "
					  << materia->getType()
					  << ". It falls onto the floor! (location: " << i
					  << ")" << std::endl;
			return;
		}
	}
	std::cout << this->_name
			  << "'s inventory is full. The materia falls onto the ground and "
				 "shatters, as the floor is already full of other materias!"
			  << std::endl;
	delete materia;
}


void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid inventory index!" << std::endl;
		return;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << "Inventory slot already empty!" << std::endl;
		return;
	}
	int i = 0;
	for (i = 0; i < 50; i++)
	{
		if (Character::_floor[i] == NULL)
		{
			_floor[i] = this->_inventory[i];
			std::cout
				<< "Materia is unequipped and falls on the ground! (location: "
				<< i << ")" << std::endl;
			break;
		}
	}
	if (i == 50)
	{
		std::cout
			<< "Too many materias on the floor. The hero can't move their "
			   "arms to unequip the item!"
			<< std::endl;
		return;
	}
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid inventory index!" << std::endl;
		return;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << "Slot " << idx << " is empty!" << std::endl;
		return;
	}
	std::cout << _name << ": ";
	this->_inventory[idx]->use(target);
	delete this->_inventory[idx];
	this->_inventory[idx] = NULL;
}

/*
** -------------------------------- ACCESSORS ---------------------------------
*/

u_int Character::getInventorySize()
{
	return INVENTORY_SIZE;
}

const std::string &Character::getClassLabel() const
{
	return _classLabel;
}

const std::string &Character::getName() const
{
	return _name;
}

const std::string &Character::getClassName() const
{
	return _className;
}

AMateria *Character::getInventory(int idx) const
{
	if (idx < 0 || idx > 3)
		return NULL;
	return this->_inventory[idx];
}

void Character::setInventory(int idx, AMateria *materia)
{
	if (idx < 0 || idx > 3)
		return;
	this->_inventory[idx] = materia;
}

const std::string &Character::getNameLabel() const
{
	return _nameLabel;
}
