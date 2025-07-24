/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:29:44 by abelov            #+#    #+#             */
/*   Updated: 2025/07/23 15:29:44 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
	std::string type_;
public:
	Animal();
	explicit Animal(std::string type);
	Animal(const Animal &other);
	virtual ~Animal();
	Animal &operator=(const Animal &other);
	void setType(const std::string &type);
	std::string getType() const;
	virtual void makeSound() const;

};

#endif //ANIMAL_HPP
