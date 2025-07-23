/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 01:29:46 by abelov            #+#    #+#             */
/*   Updated: 2025/03/17 01:29:46 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/**
 * In C++98, without virtual inheritance:
 *       ClapTrap
 *       /     \
 *  ScavTrap  FragTrap
 *       \     /
 *     DiamondTrap
 *
 * Using virtual inheritance in ScavTrap and FragTrap:
 *         ClapTrap
 *         /     \
 *  virtual     virtual
 *     |         |
 *  ScavTrap  FragTrap
 *         \     /
 *       DiamondTrap
 *
 * Now there’s only one shared ClapTrap subobject,
 * so the override resolution is unambiguous.
 */
class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	static const std::string& DEFAULT_NAME;
protected:
	static const std::string _className;
	static const std::string _classLabel;

	std::string _name;
	std::string _nameLabel;
public:
	DiamondTrap();
	explicit DiamondTrap(const std::string& Name);
	DiamondTrap(DiamondTrap &other);

	DiamondTrap &operator=(const DiamondTrap &other);

	~DiamondTrap();
	const std::string& getClassLabel() const;
	const std::string& getClassName() const;

	void whoAmI();
	void attack(const std::string &target);

	// https://en.cppreference.com/w/cpp/keyword/using.html
	// https://en.cppreference.com/w/cpp/language/using_declaration.html
	using ScavTrap::attack;

};

#endif //DIAMONDTRAP_HPP
