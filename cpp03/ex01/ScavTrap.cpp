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

const std::string ScavTrap::_className = "ScavTrap";
const std::string ScavTrap::_classLabel = buildClassLabel(_className, FT_DARK_SEA_GREEN4_B);

ScavTrap::ScavTrap() : ClapTrap()
{
	_health = _maxHealth = 100;
	_energy = _maxEnergy = 50;
	_damage = 20;
	std::cout << _classLabel << _name << FT_OLIVE_GREEN
			  << " 'default' constructor called" FT_RST << std::endl;
}

ScavTrap::ScavTrap(const std::string &Name) : ClapTrap(Name)
{
	_health = _maxHealth = 100;
	_energy = _maxEnergy = 50;
	_damage = 20;
	std::cout << _classLabel << _name << FT_OLIVE_GREEN
			  << " 'name' constructor called" FT_RST << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &other) : ClapTrap(other)
{
	std::cout << _classLabel << _name << FT_OLIVE_GREEN
			  << " 'copy' constructor called" FT_RST << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}


const std::string& ScavTrap::getClassName() const
{
	return _className;
}

void ScavTrap::attack(const std::string &target)
{
	ClapTrap::attack(target);
}

void ScavTrap::guardGate() {
	std::cout << getClassLabel() << _name
			  << FT_BOLD_Y " Gate keeper mode engaged" FT_RST << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << _classLabel << _name
			  << FT_PUMPKIN2" destructor" FT_RST << " called" << std::endl;
}

const std::string &ScavTrap::getClassLabel() const
{
	return _classLabel;
}
