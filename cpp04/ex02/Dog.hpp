/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:25:00 by abelov            #+#    #+#             */
/*   Updated: 2025/07/23 15:25:01 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* _brain;
	static const std::string _className;
	static const std::string _classLabel;
public:
	Dog();
	Dog(const Dog &other);
	~Dog();

	Dog &operator=(const Dog &other);
	void makeSound() const;

	Brain *getBrain() const;
	const std::string &getClassLabel() const;
};

#endif //DOG_HPP
