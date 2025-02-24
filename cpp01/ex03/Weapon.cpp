/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:36:44 by abelov            #+#    #+#             */
/*   Updated: 2025/02/23 23:36:44 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string &Weapon::getType() const
{
	return _type;
}

void Weapon::setType(const std::string &type)
{
	_type = type;
}

Weapon::Weapon() {}

Weapon::Weapon(const std::string& type) : _type(type) {}
