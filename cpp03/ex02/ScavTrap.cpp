/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 01:26:31 by abelov            #+#    #+#             */
/*   Updated: 2025/03/17 01:26:32 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


/*
** -------------------------------- STATIC VARS -------------------------------
*/

const std::string ScavTrap::_className = "ScavTrap";
const std::string ScavTrap::_classLabel = buildClassLabel(_className,
														  FT_DARK_SEA_GREEN4_B);
const std::string& ScavTrap::DEFAULT_NAME = "SC4V-TP#";

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/


ScavTrap::ScavTrap() : ClapTrap()
{
	_health = _maxHealth = DEFAULT_HEALTH;
	_energy = _maxEnergy = DEFAULT_ENERGY;
	_damage = DEFAULT_DAMAGE;
	std::cout << _classLabel << _nameLabel << FT_OLIVE_GREEN
			  << " 'default' constructor called" FT_RST << std::endl;
}

ScavTrap::ScavTrap(const std::string &Name) : ClapTrap(Name)
{
	_health = _maxHealth = DEFAULT_HEALTH;
	_energy = _maxEnergy = DEFAULT_ENERGY;
	_damage = DEFAULT_DAMAGE;
	std::cout << _classLabel << _nameLabel << FT_OLIVE_GREEN
			  << " 'name' constructor called" FT_RST << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &other) : ClapTrap(other)
{

	std::cout << _classLabel << _nameLabel << FT_OLIVE_GREEN
			  << " 'copy' constructor called" FT_RST << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << _classLabel << _nameLabel
			  << FT_PUMPKIN2" destructor" FT_RST << " called" << std::endl;
}



ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


void ScavTrap::attack(const std::string &target)
{
	std::cout << getClassLabel() << getNameLabel();

	if (_energy <= 0 || _health <= 0)
		std::cout << " can't act (no energy or dead)." << std::endl;
	else
	{
		_energy--;
		std::cout << " ferociously attacks " << target << ", inflicting "
				  << FT_SALMON << _damage << FT_RST << " DMG." << std::endl;
		printStatus();
	}
}

void ScavTrap::guardGate() {
	std::cout << getClassLabel() << getNameLabel()
			  << FT_BOLD_Y " Gate keeper mode engaged" FT_RST << std::endl;
}

/*
** -------------------------------- ACCESSORS ---------------------------------
*/

const std::string& ScavTrap::getClassName() const
{
	return _className;
}

const std::string &ScavTrap::getClassLabel() const
{
	return _classLabel;
}
