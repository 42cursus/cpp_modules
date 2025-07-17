/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 01:26:24 by abelov            #+#    #+#             */
/*   Updated: 2025/03/17 01:26:24 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include <cxxabi.h>
#include "ClapTrap.hpp"

// ************************************************************************** //
//                              ScavTrap Class                                //
// ************************************************************************** //

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	explicit ScavTrap(const std::string& Name);
	ScavTrap(ScavTrap &other);

	ScavTrap &operator = (const ScavTrap &other);

	~ScavTrap();

	void attack(const std::string& target);
	void guardGate();
};

#endif //SCAVTRAP_HPP
