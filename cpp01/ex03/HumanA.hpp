/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:37:37 by abelov            #+#    #+#             */
/*   Updated: 2025/02/23 23:37:38 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_HPP
#define HUMANA_HPP



// ************************************************************************** //
//                                HumanA Class                                //
// ************************************************************************** //

#include <string>
#include <iostream>
#include "Weapon.hpp"

// HumanA will always be armed
class HumanA
{
private:
	std::string	_name;
	Weapon		_weapon;
public:
	HumanA(const std::string& name, Weapon &weapon);
	void attack();
	HumanA();
	~HumanA();
};


#endif //HUMANA_HPP
