/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:40:03 by abelov            #+#    #+#             */
/*   Updated: 2025/02/23 23:40:03 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "nullptr.hpp"

HumanB::HumanB(const std::string& name) : _name(name), _weapon(nullptr) {}
void HumanB::attack()
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << "\n";
	else
		std::cout << _name << " attacks empty handed \n";
}
HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}
