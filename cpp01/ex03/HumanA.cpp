/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:50:23 by abelov            #+#    #+#             */
/*   Updated: 2025/02/23 23:50:24 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon &weapon) :
	_name(name), _weapon(weapon) {}

HumanA::HumanA(Weapon &weapon) : _weapon(weapon) {}
HumanA::~HumanA() {}

void HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weapon.getType() << "\n";
}

