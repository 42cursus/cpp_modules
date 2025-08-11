/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 01:28:12 by abelov            #+#    #+#             */
/*   Updated: 2025/03/17 01:28:12 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


/*
** -------------------------------- STATIC VARS -------------------------------
*/

const std::string FragTrap::_className = "FragTrap";
const std::string FragTrap::_classLabel = buildClassLabel(_className,
														  FT_STEEL_BLUE_B);
/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/
FragTrap::FragTrap() : ClapTrap()
{
	std::cout << _classLabel << _nameLabel << FT_OLIVE_GREEN
			  << "'default' constructor called" FT_RST << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << _classLabel << _nameLabel
			  << FT_ASH_ORANGE"destructor" FT_RST << " called" << std::endl;
}

FragTrap::FragTrap(const std::string &Name) : ClapTrap(Name)
{
	std::cout << _classLabel << _nameLabel << FT_OLIVE_GREEN
			  << "'name' constructor called" FT_RST << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

FragTrap::FragTrap(FragTrap &other) : ClapTrap(other)
{
	std::cout << _classLabel << _name << FT_PALE_GREEN
			  << "'copy' constructor called" FT_RST << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << getClassLabel() << getNameLabel()
			  << "'High five, guys!'" FT_RST << std::endl;
}

const std::string &FragTrap::getClassName() const
{
	return _className;
}

const std::string &FragTrap::getClassLabel() const
{
	return _classLabel;
}
