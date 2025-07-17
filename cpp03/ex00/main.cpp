/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 01:13:30 by abelov            #+#    #+#             */
/*   Updated: 2025/03/17 01:13:31 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap jim("Jimmy");
	ClapTrap bob("Bobby");

	jim.setDamage(5);
	bob.setDamage(3);

	jim.attack(bob.getName());
	bob.takeDamage(jim.getDamage());

	bob.beRepaired(42);
	jim.attack(bob.getName());
	bob.takeDamage(jim.getDamage());

	bob.beRepaired(42);
	jim.attack(bob.getName());
	bob.takeDamage(jim.getDamage());
	jim.attack(bob.getName());
	bob.takeDamage(jim.getDamage());
	jim.attack(bob.getName());
	bob.takeDamage(jim.getDamage());

	ClapTrap some;
	some.setDamage(11);
	some.attack(jim.getName());
	jim.takeDamage(some.getDamage());
	jim.beRepaired(5);

	return (0);
}
