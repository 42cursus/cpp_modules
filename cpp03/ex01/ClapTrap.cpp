/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 01:17:03 by abelov            #+#    #+#             */
/*   Updated: 2025/03/17 01:17:04 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

ClapTrap::ClapTrap() : _name("John Doe"), _health(HEALTH_CAP),
					   _energy(DEFAULT_ENERGY), _damage(DEFAULT_DAMAGE)
{
	_className = __func__;

	std::cout << FT_BOLD_G << _className << FT_RST": " << _name
			  << FT_CYAN" 'default' constructor called" FT_RST << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name),
											  _health(HEALTH_CAP),
											  _energy(DEFAULT_ENERGY),
											  _damage(DEFAULT_DAMAGE)
{
	_className = __func__;

	std::cout << FT_BOLD_G << _className << FT_RST": " << _name
			  << FT_CYAN" 'name' constructor called" FT_RST << std::endl;;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name),
											_health(other._health),
											_energy(other._energy),
											_damage(other._damage)
{
	_className = __func__;

	std::cout << FT_BOLD_G << _className << FT_RST": " << _name
			  << FT_CYAN" 'copy' constructor called" FT_RST<< std::endl;;
}

/*
** ------------------------------- DESTRUCTOR ---------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << FT_BOLD_G << _className << FT_RST": " << _name
			  << FT_SALMON" destructor called" FT_RST << std::endl;
}

/*
** -------------------------------- OVERLOADS ---------------------------------
*/

/**
 * Copy assignment operator
 * @param other
 * @return
 */
ClapTrap &ClapTrap::operator = (const ClapTrap &other)
{
	if (this != &other)
	{
		this->_damage = other._damage;
		this->_energy = other._energy;
		this->_health = other._health;
		this->_name = other._name;
	}
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!_energy || !_health)
	{
		std::cout << FT_BOLD_G << _className << FT_RST": " << _name
				  << " can't repair itself." << std::endl;
		return;
	}
	else if (_health >= HEALTH_CAP) // we could set
	{
		std::cout << FT_BOLD_G << _className << FT_RST": " << _name
				  << " already has the maximum health." << std::endl;
		return;
	}

	unsigned int delta = 0;
	unsigned int amountHealed = _health + amount;
	delta = (amountHealed > HEALTH_CAP) ? HEALTH_CAP - _health : amountHealed;

	_energy--;
	_health += delta;
	std::cout << FT_BOLD_G << _className << FT_RST": " << _name
			  << " repairs itself regaining "
			  << FT_GREEN << delta << FT_RST" hit points." << std::endl;
	std::cout << FT_BOLD_G << _className << FT_RST": " << _name
			  << "'s health is now " FT_BOLD_Y << _health << FT_RST"." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_health)
	{
		if (amount > _health)
		{
			_health = 0;
			std::cout << FT_BOLD_G << _className << FT_RST": " << _name
					  << " received an Overkill!" << std::endl;
		}
		else
		{
			_health -= amount;
			std::cout << FT_BOLD_G << _className << FT_RST": " << _name << " took "
					  << FT_RED << amount << FT_RST" of damage." << std::endl;
		}
		std::cout << FT_BOLD_G << _className << FT_RST": " << _name
				  << "'s health is now " FT_BOLD_Y << _health << FT_RST"." << std::endl;
	}
	else
		std::cout << FT_BOLD_G << _className << FT_RST": " << _name
				  << " is already dead ;(" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	std::cout << FT_BOLD_G << _className << FT_RST": "
			  << _name << " attacks " << target
			  << ", causing " << _damage << " points of damage!" << std::endl;
}

/*
** -------------------------------- ACCESSORS ---------------------------------
*/

const std::string &ClapTrap::getName() const
{
	return _name;
}

unsigned int ClapTrap::getEnergy() const
{
	return _energy;
}

unsigned int ClapTrap::getHealth() const
{
	return _health;
}

unsigned int ClapTrap::getDamage() const
{
	return _damage;
}

void ClapTrap::setName(const std::string &name)
{
	_name = name;
}

void ClapTrap::setHealth(unsigned int health)
{
	_health = health;
}

void ClapTrap::setEnergy(unsigned int energy)
{
	_energy = energy;
}

void ClapTrap::setDamage(unsigned int damage)
{
	_damage = damage;
}

const std::string &ClapTrap::getClassName() const
{
	return _className;
}
