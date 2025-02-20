/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:14:03 by abelov            #+#    #+#             */
/*   Updated: 2025/02/20 00:14:03 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>


// ************************************************************************** //
//                                Zombie Class                                //
// ************************************************************************** //

class Zombie
{
private:
	std::string _name;
public:
	Zombie* zombieHorde(int N, std::string name);
};


#endif //ZOMBIE_HPP
