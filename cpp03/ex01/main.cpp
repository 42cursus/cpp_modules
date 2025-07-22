/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 01:23:37 by abelov            #+#    #+#             */
/*   Updated: 2025/03/17 01:23:38 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	std::cout << "-----------------------------------" << std::endl;
	std::cout << FT_BOLD_G << "CONSTRUCTORS" << FT_RST << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	ScavTrap jim("Jimmy");
	ScavTrap tim("Timmy");
	ScavTrap bim(jim); // bim will have name "Jimmy"
	ScavTrap bar;
	bar = tim; // bar will have name "Timmy"

	std::cout << "-----------------------------------"  << std::endl;
	std::cout << FT_BOLD_Y << "MAIN" << FT_RST << std::endl;
	std::cout << "-----------------------------------"  << std::endl;

	jim.attack(tim.getName());
	tim.takeDamage(jim.getDamage());

	tim.beRepaired(4);
	jim.attack(tim.getName());
	tim.takeDamage(jim.getDamage());

	tim.beRepaired(2);
	jim.attack(tim.getName());
	tim.takeDamage(jim.getDamage());
	jim.attack(tim.getName());
	tim.beRepaired(10);
	tim.beRepaired(42);
	tim.beRepaired(5);
	tim.takeDamage(jim.getDamage());
	jim.attack(tim.getName());
	tim.takeDamage(jim.getDamage());

	bar.setDamage(11);
	bar.attack(bim.getName());
	bim.takeDamage(bar.getDamage());
	bim.beRepaired(5);
	std::cout << std::endl;
	{
		ScavTrap Robot("Warden");
		std::cout << std::endl;
		Robot.guardGate();
		std::cout << std::endl;
	}

	std::cout << "-----------------------------------" << std::endl;
	std::cout << FT_BOLD_R << "DESTRUCTORS" << FT_RST  << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	return (0);
}
