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

	jim.attack("Bobby");
	bob.takeDamage(2);

	jim.attack("Bobby");
	bob.takeDamage(3);
	bob.beRepaired(1);

	return (0);
}
