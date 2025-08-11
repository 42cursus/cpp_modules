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
** -------------------------------- STATIC VARS -------------------------------
*/

const std::string ClapTrap::_className = "ClapTrap";
const std::string ClapTrap::_classLabel = buildClassLabel(_className,
														  FT_PALE_TURQUOISE4_B);
const std::string& ClapTrap::DEFAULT_NAME = "CL4P-TP#";
const u_int ClapTrap::DEFAULT_HEALTH;
const u_int ClapTrap::DEFAULT_ENERGY;
const u_int ClapTrap::DEFAULT_DAMAGE;
const u_int ClapTrap::DEFAULT_BAR_WIDTH;
const u_int ClapTrap::_barWidth;

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

ClapTrap::ClapTrap() : _name(DEFAULT_NAME),
					   _nameLabel(buildNameLabel(_name, FT_WHITE_B)),
					   _health(DEFAULT_HEALTH),
					   _maxHealth(DEFAULT_HEALTH),
					   _energy(DEFAULT_ENERGY),
					   _maxEnergy(DEFAULT_ENERGY),
					   _damage(DEFAULT_DAMAGE)
{
	std::cout << _classLabel << _nameLabel
			  << FT_DIM_GREEN"'default' constructor called" FT_RST << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name),
											  _nameLabel(buildNameLabel(_name, FT_WHITE_B)),
											  _health(DEFAULT_HEALTH),
											  _maxHealth(DEFAULT_HEALTH),
											  _energy(DEFAULT_ENERGY),
											  _maxEnergy(DEFAULT_ENERGY),
											  _damage(DEFAULT_DAMAGE)
{
	std::cout << _classLabel << _nameLabel
			  << FT_DIM_GREEN"'name' constructor called" FT_RST << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name),
											_nameLabel(buildNameLabel(_name, FT_WHITE_B)),
											_health(other._health),
											_maxHealth(other._health),
											_energy(other._energy),
											_maxEnergy(other._maxEnergy),
											_damage(other._damage)
{
	std::cout << _classLabel << _nameLabel
			  << FT_DIM_GREEN"'copy' constructor called" << std::endl;;
}

/*
** ------------------------------- DESTRUCTOR ---------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << _classLabel << _nameLabel
			  << FT_LIGHT_BROWN"destructor" FT_RST << " called" << std::endl;
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
	std::cout << _classLabel << _nameLabel
			  << "assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_damage = other._damage;
		this->_energy = other._energy;
		this->_maxEnergy = other._maxEnergy;
		this->_health = other._health;
		this->_maxHealth = other._maxHealth;
		this->_name = other._name;
		this->_nameLabel = other._nameLabel;
	}
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string ClapTrap::buildNameLabel(const std::string& name,
									 const char *colour)
{
	std::string label = (name + " ");
	label.insert(0, colour);
	label.insert(name.length() + std::strlen(colour), FT_RST);
	return label;
}

std::string ClapTrap::buildClassLabel(const std::string& classname,
									  const char *colour)
{
	std::ostringstream oss;
	oss << std::left << std::setw(CLASS_NAME_PADDING) << (classname + ":");

	std::string label = oss.str();
	label.insert(0, colour);
	label.insert(classname.length() + std::strlen(colour), FT_RST);
	return label;
}

std::string ClapTrap::renderBar(u_int current, u_int max, const char* color)
{
	std::ostringstream oss;
	u_int filled = (current * _barWidth + max - 1) / max;
	u_int empty = _barWidth - filled;

	const char full = '#';
	const char empt = '-';

	oss << color
		<< std::string(filled, full)
		<< std::string(empty, empt)
		<< FT_RST;
	return oss.str();
}

void ClapTrap::printStatusFull() const
{
	std::string hpBar = renderBar(_health, _maxHealth, FT_BOLD_G);
	std::string epBar = renderBar(_energy, _maxEnergy, FT_PUMPKIN2);

	std::cout << getClassLabel() << getNameLabel()
			  << " HP:  [" << hpBar << "] "
			  << FT_BOLD_G << _health << "/" << _maxHealth << FT_RST
			  << ", EP:  [" << epBar << "] "
			  << FT_ORANGE << _energy << "/" << _maxEnergy  << FT_RST
			  << ", DMG: " << FT_HOT_PINK << _damage << FT_RST << std::endl;
}

void ClapTrap::printStatus() const
{
	std::string hpBar = renderBar(_health, _maxHealth, FT_SOFT_GREEN);
	std::string epBar = renderBar(_energy, _maxEnergy, FT_SAND_TAN);

	std::ostringstream oss;
	oss << std::left << std::setw(CLASS_NAME_PADDING) << " "
		<< FT_DIM << "HP: [" << hpBar << FT_DIM << "] "
		<< std::right << std::setw(3) << _health << "/" << _maxHealth
		<< " | EP: [" << epBar << FT_DIM << "] "
		<< _energy << "/" << _maxEnergy << FT_RST;
	std::cout << oss.str() << std::endl;
}

void ClapTrap::printHealth() const
{
	std::string hpBar = renderBar(_health, _maxHealth, FT_SOFT_GREEN);

	std::ostringstream oss;
	oss << std::left << std::setw(CLASS_NAME_PADDING) << " "
		<< FT_DIM << "HP: [" << hpBar << FT_DIM << "] "
		<< _health << "/" << _maxHealth << FT_RST;
	std::cout << oss.str() << std::endl;
}

void ClapTrap::beRepaired(u_int amount)
{
	std::cout << getClassLabel() << getNameLabel();
	if (!_energy || !_health)
	{
		std::cout << "can't repair itself (no energy or dead)." << std::endl;
		return;
	}
	else if (_health >= _maxHealth)
	{
		std::cout << "won't repair itself (maximum health)." << std::endl;
		return;
	}

	u_int amountHealed = _health + amount;
	u_int delta = (amountHealed > _maxHealth) ? _maxHealth - _health : amount;

	_energy--;
	_health += delta;
	std::cout << "repairs itself."
			  << FT_BOLD_G << " (+" << delta << " HP)" << FT_RST << std::endl;
	printStatus();
}

void ClapTrap::takeDamage(u_int amount)
{
	std::cout << getClassLabel() << getNameLabel();

	if (_health)
	{
		if (amount > _health)
		{
			_health = 0;
			std::cout << "receives an Overkill!";
		}
		else
		{
			_health -= amount;
			std::cout << "been attacked";
		}

		ssize_t amountLost = _health - amount;
		u_int delta = (amountLost < 0) ? amount - _health : amount;
		std::cout << FT_SALMON << " (-" << delta << " HP)" FT_RST << std::endl;
		printHealth();
	}
	else
		std::cout << "is already dead X_X" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	std::cout << getClassLabel() << getNameLabel();

	if (_energy <= 0 || _health <= 0)
		std::cout << "can't act (no energy or dead)." << std::endl;
	else
	{
		_energy--;
		std::cout << "attacks " << target << ", inflicting "
				  << FT_SALMON << _damage << FT_RST << " DMG." << std::endl;
		printStatus();
	}
}

/*
** -------------------------------- ACCESSORS ---------------------------------
*/

const std::string &ClapTrap::getName() const
{
	return _name;
}

u_int ClapTrap::getEnergy() const
{
	return _energy;
}

u_int ClapTrap::getHealth() const
{
	return _health;
}

u_int ClapTrap::getDamage() const
{
	return _damage;
}

void ClapTrap::setName(const std::string &name)
{
	_name = name;
}

void ClapTrap::setHealth(u_int health)
{
	if (health <= _maxHealth)
		_health = health;
	else
		_health = _maxHealth;
	printStatus();
}

void ClapTrap::setEnergy(u_int energy)
{
	if (energy <= _maxEnergy)
		_energy = energy;
	else
		_energy = _maxEnergy;
	printStatus();
}

void ClapTrap::setDamage(u_int damage)
{
	_damage = damage;
}

const std::string& ClapTrap::getClassName() const
{
	return _className;
}

const std::string& ClapTrap::getClassLabel() const
{
	return _classLabel;
}

const std::string &ClapTrap::getNameLabel() const
{
	return _nameLabel;
}
