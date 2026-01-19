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
	const WrongCat* wrongCat = new WrongCat();
	const WrongAnimal* wGeneric = new WrongAnimal();

	std::cout << std::endl;
	std::cout << "-----------------------------------"  << std::endl;
	std::cout << FT_BOLD_Y << "MAIN" << FT_RST << std::endl;
	std::cout << "-----------------------------------"  << std::endl;

	std::cout << dog->getClassLabel()
			  << "tag " << dog->getType() << " " << std::endl;
	std::cout << cat->getClassLabel()
			  << "tag " << cat->getType() << " " << std::endl;
	std::cout << generic->getClassLabel()
			  << "tag " << generic->getType() << " " << std::endl;
	std::cout << std::endl;
	cat->makeSound(); // will output the cat sound!
	dog->makeSound(); // will output the dog sound!
	generic->makeSound();
	std::cout << std::endl;
	std::cout << wCat->getClassLabel()
			  << "tag " << wCat->getType() << " " << std::endl;
	std::cout << wrongCat->getClassLabel()
			  << "tag " << wrongCat->getType() << " " << std::endl;
	std::cout << wGeneric->getClassLabel()
			  << "tag " << wGeneric->getType() << " " << std::endl;
	std::cout << std::endl;
	wGeneric->makeSound();
	wrongCat->makeSound();	// will output the cat sound
	wCat->makeSound();	// will not output the cat sound as
						// the pointer is of a tag WrongAnimal and makeSound()
						// is not virtual!


	std::cout << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << FT_BOLD_R << "DESTRUCTORS" << FT_RST  << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	delete cat;
	delete dog;
	delete generic;

	delete wCat;
	delete wrongCat;
	delete wGeneric;

	return 0;
}