/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 00:53:13 by abelov            #+#    #+#             */
/*   Updated: 2025/07/18 00:53:14 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

const std::string& DiamondTrap::DEFAULT_NAME = "D4MND-TP#";
const std::string DiamondTrap::_className = "DiamondTrap";
const std::string DiamondTrap::_classLabel = buildClassLabel(_className,
															 FT_LIGHT_PURPLE);


DiamondTrap::DiamondTrap()
	: ClapTrap(DEFAULT_NAME + "_clap_name"),
	ScavTrap(DEFAULT_NAME),
	FragTrap(DEFAULT_NAME),
	_name(DEFAULT_NAME)
{
	_health = _maxHealth = FragTrap::DEFAULT_HEALTH;
	_energy = _maxEnergy = ScavTrap::DEFAULT_ENERGY;
	_damage = FragTrap::DEFAULT_DAMAGE;
	std::cout << _classLabel << _name << FT_OLIVE_GREEN
			  << " 'default' constructor called" FT_RST << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << _classLabel << _name << " destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &Name)
	: ClapTrap(Name + "_clap_name"),
	  ScavTrap(Name),
	  FragTrap(Name),
	  _name(Name)
{
	_health = _maxHealth = FragTrap::DEFAULT_HEALTH;
	_energy = _maxEnergy = ScavTrap::DEFAULT_ENERGY;
	_damage = FragTrap::DEFAULT_DAMAGE;
	std::cout << _classLabel << _name << FT_SEA_GREEN2_B
			  << " 'name' constructor called" FT_RST << std::endl;
}

const std::string& DiamondTrap::getClassLabel() const
{
	return _classLabel;
}

DiamondTrap::DiamondTrap(DiamondTrap &other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other),
	  _name(other._name),
	  _nameLabel(other._nameLabel)
{
	std::cout << _classLabel << " copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		_name = other._name;
		_nameLabel = other._nameLabel;
	}
	std::cout << _classLabel << " assignment operator called" << std::endl;
	return *this;
}

const std::string &DiamondTrap::getClassName() const
{
	return _className;
}

void DiamondTrap::whoAmI()
{
	std::cout << _classLabel << "I am " << _name
			  << ", ClapTrap name is " << FT_CADET_BLUE << ClapTrap::_name << FT_RST << "." << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}
