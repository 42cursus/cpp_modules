/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 01:13:59 by abelov            #+#    #+#             */
/*   Updated: 2025/03/17 01:14:00 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <cxxabi.h>

// ************************************************************************** //
//                              ClapTrap Class                                //
// ************************************************************************** //

#define CLASSNAME_BUF_SIZE 42

class ClapTrap
{

private:
	static const unsigned int _HEALTH_CAP = 10;
	static const unsigned int _DEFAULT_ENERGY = 10;
	static const unsigned int _DEFAULT_DAMAGE = 0;

	std::string _name;
	unsigned int _health;
	unsigned int _energy;
	unsigned int _damage;

public:
	ClapTrap();
	explicit ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &);
	~ClapTrap();

	ClapTrap& operator=(const ClapTrap &);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	const std::string &getName() const;
	unsigned int getHealth() const;
	unsigned int getEnergy() const;
	unsigned int getDamage() const;

	void setName(const std::string &name);
	void setHealth(unsigned int health);
	void setEnergy(unsigned int energy);
	void setDamage(unsigned int damage);
};


#endif //CLAPTRAP_HPP
