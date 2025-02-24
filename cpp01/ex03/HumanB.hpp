/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:39:56 by abelov            #+#    #+#             */
/*   Updated: 2025/02/23 23:39:57 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
#define HUMANB_HPP

// ************************************************************************** //
//                                HumanB Class                                //
// ************************************************************************** //

#include <string>
#include <iostream>
#include "Weapon.hpp"

// HumanB may not always have a weapon
class HumanB
{
private:
	std::string	_name;
	Weapon		*_weapon;
public:
	// Single-argument constructors must be marked explicit
	// to avoid unintentional implicit conversions
	explicit HumanB(const std::string& name);
	~HumanB();
	void setWeapon(Weapon& weapon);

	void attack();
};

#endif //HUMANB_HPP
