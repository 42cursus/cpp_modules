/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:57:54 by abelov            #+#    #+#             */
/*   Updated: 2025/02/19 23:57:55 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>


// ************************************************************************** //
//                                Zombie Class                                //
// ************************************************************************** //

class Zombie
{
private:
	std::string _name;

public:
	explicit Zombie(const std::string&);
	~Zombie();
	static void randomChump(const std::string& name);
	static Zombie* newZombie(const std::string& name);
	void announce();
};


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

#endif //ZOMBIE_HPP
