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

int main(int argc, char **argv)
{
	std::cout << "-----------------------------------" << std::endl;
	std::cout << FT_BOLD_G << "CONSTRUCTORS" << FT_RST << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	ScavTrap jim("Bully");
	ScavTrap tim("Timmy");
	ScavTrap bim(jim); // bim will have name "Bully"
	ScavTrap bar;
	bar = tim; // bar will have name "Timmy"

	std::cout << "-----------------------------------"  << std::endl;
	std::cout << FT_BOLD_Y << "MAIN" << FT_RST << std::endl;
	std::cout << "-----------------------------------"  << std::endl;

	jim.attack(tim.getName());
	tim.takeDamage(jim.getDamage());

	tim.beRepaired(42);
	jim.attack(tim.getName());
	tim.takeDamage(jim.getDamage());

	tim.beRepaired(42);
	jim.attack(tim.getName());
	tim.takeDamage(jim.getDamage());
	jim.attack(tim.getName());
	tim.takeDamage(jim.getDamage());
	jim.attack(tim.getName());
	tim.takeDamage(jim.getDamage());

	bar.setDamage(11);
	bar.attack(bim.getName());
	bim.takeDamage(bar.getDamage());
	bim.beRepaired(5);

	{
		ScavTrap temp("Scoped");
		temp.attack("Target");
	}

	bar.guardGate();

	std::cout << "-----------------------------------" << std::endl;
	std::cout << FT_BOLD_R << "DESTRUCTORS" << FT_RST  << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	return (0);
	(void)argc;
	(void)argv;
}
