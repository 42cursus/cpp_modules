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

#include "ClapTrap.hpp"

// ************************************************************************** //
//                              ScavTrap Class                                //
// ************************************************************************** //

class ScavTrap : public virtual ClapTrap
{
private:
	static const std::string& DEFAULT_NAME;
protected:
	static const u_int	DEFAULT_HEALTH = 100;
	static const u_int	DEFAULT_ENERGY = 50;
	static const u_int	DEFAULT_DAMAGE = 20;
	static const std::string _className;
	static const std::string _classLabel;
public:
	ScavTrap();
	explicit ScavTrap(const std::string& Name);
	ScavTrap(ScavTrap &other);

	ScavTrap &operator=(const ScavTrap &other);

	~ScavTrap();
	const std::string& getClassName() const;
	const std::string& getClassLabel() const;

	void attack(const std::string& target);
	void guardGate();
};

#endif //SCAVTRAP_HPP
