/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:15:22 by abelov            #+#    #+#             */
/*   Updated: 2025/02/20 00:15:22 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *Zombie::zombieHorde(int N, const std::string& name)
{
	Zombie *zombies;
	// Allocate raw memory with operator new
	zombies = static_cast<Zombie *>(operator new[](N * sizeof(Zombie)));

	// Construct objects manually using placement new
	for (int i = 0; i < N; i += 1)
		new (&zombies[i]) Zombie(name);
	return (zombies);
}
