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
	std::cout << "-----------------------------------"  << std::endl;
	std::cout << BOLD_GREEN << "CONSTRUCTORS" << RESET << std::endl;
	std::cout << "-----------------------------------"  << std::endl;

	ScavTrap foo;
	ScavTrap bar("Bar");
	ScavTrap buz(foo); // buz will have name "Foo"
	ScavTrap qux;
	qux = bar; // qux will have name "Bar"

	std::cout << "-----------------------------------"  << std::endl;
	std::cout << FT_BOLD_Y << "MAIN" << FT_RST << std::endl;
	std::cout << "-----------------------------------"  << std::endl;

	foo.attack("Bar");
	bar.takeDamage(20);
	foo.attack("Bar");
	bar.takeDamage(20);
	bar.takeDamage(20);
	bar.takeDamage(20);
	bar.takeDamage(20);
	buz.attack("Bar");
	qux.takeDamage(200);
	qux.attack("Foo");

	qux.guardGate();

	std::cout << "-----------------------------------"  << std::endl;
	std::cout << FT_BOLD_R << "DESTRUCTORS" << FT_RST << std::endl;
	std::cout << "-----------------------------------"  << std::endl;
}
