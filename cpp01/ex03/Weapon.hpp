/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:36:35 by abelov            #+#    #+#             */
/*   Updated: 2025/02/23 23:36:36 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

// ************************************************************************** //
//                                Weapon Class                                //
// ************************************************************************** //

class Weapon
{
private:
	std::string _type;
public:
	Weapon();
	const std::string &getType() const;
	void setType(const std::string &newType);

	// Single-argument constructors must be marked explicit
	// to avoid unintentional implicit conversions
	explicit Weapon(const std::string& type);
};

#endif //WEAPON_HPP
