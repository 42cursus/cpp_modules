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

const char ScavTrap::_className[] = "ScavTrap";
ScavTrap::ScavTrap() : ClapTrap()
{
	_health = 100;
	_maxHealth = 100;
	_energy = 50;
	_damage = 20;
	std::cout << _className << ": " << _name
			  << " 'default' constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &Name) : ClapTrap(Name)
{
	_health = 100;
	_maxHealth = 100;
	_energy = 50;
	_damage = 20;
	std::cout << _className << ": " << _name
			  << " 'name' constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &other) : ClapTrap(other)
{
	std::cout << _className << ": " << _name
			  << " 'copy' constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}


const char* ScavTrap::getClassName() const {
	return _className;
}

void ScavTrap::attack(const std::string &target)
{
	ClapTrap::attack(target);
}


void ScavTrap::guardGate() {
	std::cout << _className << ": " << _name
			  << " is now is now in the "
			  FT_BOLD_Y "Gate keeper mode" FT_RST << std::endl;
};

ScavTrap::~ScavTrap()
{
	std::cout << _className << ": " << _name
			  << " destructor called" << std::endl;
}
