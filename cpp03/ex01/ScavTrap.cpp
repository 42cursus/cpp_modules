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

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_name = "ScavTrapDefault";
	_className = __func__;
	_health = 100;
	_energy = 50;
	_damage = 20;
	std::cout << _className << ": " << _name
			  << " 'default' constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &Name) : ClapTrap(Name)
{
	_className = __func__;
	_health = 100;
	_energy = 50;
	_damage = 20;
	std::cout << _className << ": " << _name
			  << " 'default' constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << _className << ": " << _name
			  << " destructor called" << std::endl;
}
