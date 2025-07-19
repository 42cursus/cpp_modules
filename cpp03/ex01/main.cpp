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
	ScavTrap bob("Bobby");
	ScavTrap foo(jim); // foo will have name "Jimmy"
	ScavTrap bar;
	bar = bob; // bar will have name "Bobby"

	jim.printStatus();
	bob.printStatus();
	foo.printStatus();
	bar.printStatus();

	std::cout << "-----------------------------------"  << std::endl;
	std::cout << FT_BOLD_Y << "MAIN" << FT_RST << std::endl;
	std::cout << "-----------------------------------"  << std::endl;

	jim.attack(bob.getName());
	jim.printStatus();
	bob.takeDamage(jim.getDamage());

	bob.beRepaired(42);
	jim.attack(bob.getName());
	jim.printStatus();
	bob.takeDamage(jim.getDamage());

	bob.beRepaired(42);
	jim.attack(bob.getName());
	bob.takeDamage(jim.getDamage());
	jim.attack(bob.getName());
	bob.takeDamage(jim.getDamage());
	jim.attack(bob.getName());
	bob.takeDamage(jim.getDamage());

	bar.setDamage(11);
	bar.attack(foo.getName());
	foo.takeDamage(bar.getDamage());
	foo.beRepaired(5);

	{
		ScavTrap temp("Scoped");
		temp.attack("Target");
	}

	bar.guardGate();

	std::cout << "-----------------------------------" << std::endl;
	std::cout << FT_BOLD_R << "DESTRUCTORS" << FT_RST  << std::endl;
	std::cout << "-----------------------------------" << std::endl;
}
