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

// ************************************************************************** //
//                              ClapTrap Class                                //
// ************************************************************************** //

#include <iostream>
#include <string>

class ClapTrap
{

private:
	std::string _name;
	int _health;
	int _energy;
	int _attack;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap &);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

};


#endif //CLAPTRAP_HPP
