/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:08:32 by abelov            #+#    #+#             */
/*   Updated: 2025/02/20 00:08:33 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main()
{
	Zombie	stack("Bob");
	stack.announce();

	Zombie*	heap;
	heap = Zombie::newZombie("Alice");
	heap->announce();
	delete heap;

	Zombie::randomChump("Eve");
	return (0);
}
