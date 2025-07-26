/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 01:23:57 by abelov            #+#    #+#             */
/*   Updated: 2025/03/17 01:23:58 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << FT_BOLD_G << "CONSTRUCTORS" << FT_RST << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	ClapTrap Sally("Sally");
	ScavTrap Bob("Bob");
	FragTrap Sam("Sam");
	DiamondTrap hfg;

	std::cout << std::endl;
	std::cout << "-----------------------------------"  << std::endl;
	std::cout << FT_BOLD_Y << "MAIN" << FT_RST << std::endl;
	std::cout << "-----------------------------------"  << std::endl;

	Bob.setEnergy(1);
	Bob.attack(Sally.getName());
	Sally.takeDamage(Bob.getDamage());
	Sally.beRepaired(42);
	Sally.attack(Bob.getName());
	Bob.takeDamage(Sally.getDamage());
	Bob.beRepaired(15);

	std::cout << std::endl;
	{
		std::cout << FT_BOLD_Y << "SCOPE" << FT_RST << std::endl;
		std::cout << "-----------------------------------"  << std::endl;
		ScavTrap Robot("Warden");

		Robot.guardGate();
	}
	std::cout << "-----------------------------------"  << std::endl;
	std::cout << std::endl;

	Sam.highFivesGuys();
	hfg.whoAmI();
	hfg.highFivesGuys();
	hfg.attack(Sam.getName());
	Sam.takeDamage(hfg.getDamage());

	std::cout << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << FT_BOLD_R << "DESTRUCTORS" << FT_RST  << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	return (0);
}
