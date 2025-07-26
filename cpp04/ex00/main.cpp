/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 22:48:31 by abelov            #+#    #+#             */
/*   Updated: 2025/07/17 22:48:32 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << FT_BOLD_G << "CONSTRUCTORS" << FT_RST << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	const Animal* cat = new Cat();
	const Animal* dog = new Dog();
	const Animal* generic = new Animal();
	std::cout << std::endl;
	const WrongAnimal* wCat = new WrongCat();
	const WrongAnimal* wGeneric = new WrongAnimal();

	std::cout << std::endl;
	std::cout << "-----------------------------------"  << std::endl;
	std::cout << FT_BOLD_Y << "MAIN" << FT_RST << std::endl;
	std::cout << "-----------------------------------"  << std::endl;

	std::cout << dog->getClassLabel() << dog->getType() << " " << std::endl;
	std::cout << cat->getClassLabel() << cat->getType() << " " << std::endl;
	cat->makeSound(); // will output the cat sound!
	dog->makeSound(); // will output the dog sound!
	generic->makeSound();
	std::cout << std::endl;
	std::cout << wCat->getClassLabel() << wCat->getType() << " " << std::endl;
	std::cout << wGeneric->getClassLabel() << wGeneric->getType() << " " << std::endl;
	wCat->makeSound();	// will not output the cat sound as
						// the pointer is of a type WrongAnimal and makeSound()
						// is not virtual!
	wGeneric->makeSound();

	std::cout << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << FT_BOLD_R << "DESTRUCTORS" << FT_RST  << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	delete cat;
	delete dog;
	delete generic;

	delete wCat;
	delete wGeneric;

	return 0;
}