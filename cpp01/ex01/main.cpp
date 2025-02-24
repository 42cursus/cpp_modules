/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:15:02 by abelov            #+#    #+#             */
/*   Updated: 2025/02/20 00:15:02 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int size = 10;

	Zombie* zombies = Zombie::zombieHorde(size, "Goblin");
	for (int i = 0; i < 10; i++)
		zombies[i].announce();

	for (int i = 0; i < size; ++i)
		zombies[i].~Zombie();

	operator delete[](zombies); // Free raw memory
	return (0);
}
