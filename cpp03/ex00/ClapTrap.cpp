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

ClapTrap::ClapTrap() : _name("John Doe"), _health(_HEALTH_CAP),
					   _energy(_DEFAULT_ENERGY), _damage(_DEFAULT_DAMAGE)
{
	const char *className = typeid(*this).name();
	char buf[42];
	size_t length = 42;
	char *demangledClassName = abi::__cxa_demangle(
		className, buf, &length, NULL);

	std::cout << demangledClassName << " " << _name
			  << " 'default' constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name),
											  _health(_HEALTH_CAP),
											  _energy(_DEFAULT_ENERGY),
											  _damage(_DEFAULT_DAMAGE)
{
	const char *className = typeid(*this).name();
	char buf[CLASSNAME_BUF_SIZE];
	size_t length = CLASSNAME_BUF_SIZE;
	char *demangledClassName = abi::__cxa_demangle(
		className, buf, &length, NULL);

	std::cout << demangledClassName << " " << _name
			  << " 'name' constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name),
											_health(other._health),
											_energy(other._energy),
											_damage(other._damage)
{
	const char *className = typeid(*this).name();
	char buf[CLASSNAME_BUF_SIZE];
	size_t length = CLASSNAME_BUF_SIZE;
	char *demangledClassName = abi::__cxa_demangle(
		className, buf, &length, NULL);

	std::cout << demangledClassName << " " << _name
			  << " 'copy' constructor called\n";
}

/*
** ------------------------------- DESTRUCTOR ---------------------------------
*/

ClapTrap::~ClapTrap()
{
	const char *className = typeid(*this).name();
	char buf[CLASSNAME_BUF_SIZE];
	size_t length = CLASSNAME_BUF_SIZE;
	char *demangledClassName = abi::__cxa_demangle(
		className, buf, &length, NULL);
	std::cout << demangledClassName << " " << _name
			  << " destructor called" << std::endl;
}

/*
** -------------------------------- OVERLOADS ---------------------------------
*/

/**
 * Copy assignment operator
 * @param other
 * @return
 */
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
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
	const char *className = typeid(*this).name();
	char buf[CLASSNAME_BUF_SIZE];
	size_t length = CLASSNAME_BUF_SIZE;
	char *demangledClassName = abi::__cxa_demangle(
		className, buf, &length, NULL);

	if (!_energy || !_health)
	{
		std::cout << demangledClassName << " " << _name
				  << " can't repaire itself." << std::endl;
		return;
	}
	else if (_health >= _HEALTH_CAP) // we could set
	{
		std::cout << demangledClassName << " " << _name
				  << "already has maximum health." << std::endl;
		return;
	}

	unsigned int delta = 0;
	unsigned int amountHealed = _health + amount;
	delta = (amountHealed > _HEALTH_CAP) ? _HEALTH_CAP - _health : amountHealed;

	_energy--;
	_health += delta;
	std::cout << demangledClassName << " " << _name << " repairs itself with "
			  << delta << " hit points." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{

	const char *className = typeid(*this).name();
	char buf[CLASSNAME_BUF_SIZE];
	size_t length = CLASSNAME_BUF_SIZE;
	char *demangledClassName = abi::__cxa_demangle(
		className, buf, &length, NULL);

	if (_health)
	{
		if (amount > _health)
		{
			_health = 0;
			std::cout << demangledClassName << " " << _name
					  << " received an Overkill!" << std::endl;
		}
		else
		{
			_health -= amount;
			std::cout << demangledClassName << " " << _name << " took "
					  << amount << " of damage." << std::endl;
		}
		std::cout << demangledClassName << " " << _name
				  << "'s health is now " << _health << "." << std::endl;
	}
	else
		std::cout << demangledClassName << " " << _name
				  << " is already dead ;(" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	const char *className = typeid(*this).name();
	char buf[CLASSNAME_BUF_SIZE];
	size_t length = CLASSNAME_BUF_SIZE;
	char *demangledClassName = abi::__cxa_demangle(
		className, buf, &length, NULL);

	std::cout << demangledClassName << " " << _name << " attacks " << target
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
