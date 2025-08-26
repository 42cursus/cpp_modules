/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 23:29:56 by abelov            #+#    #+#             */
/*   Updated: 2025/07/24 23:29:56 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << FT_BOLD_G << "CONSTRUCTORS" << FT_RST << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	Dog basicDog;
	Cat basicCat;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal *animals[10];
	for (int k = 0; k < 5; ++k)
		animals[k] = new Cat();
	for (int k = 5; k < 10; ++k)
		animals[k] = new Dog();

	std::cout << std::endl;
	std::cout << "-----------------------------------"  << std::endl;
	std::cout << FT_BOLD_Y << "MAIN" << FT_RST << std::endl;
	std::cout << "-----------------------------------"  << std::endl;

	std::cout << j->getClassLabel()
			  << "type " << j->getType() << " " << std::endl;
	std::cout << i->getClassLabel()
			  << "type " << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound();
	std::cout << std::endl;
	for (int k = 0; k < 10; ++k)
		animals[k]->makeSound();

	std::cout << std::endl;
	basicDog.getBrain()->setIdea(0, "I want to eat");
	std::cout << basicDog.getClassLabel()
			  << basicDog.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl;
	{
		std::cout << std::endl;
		std::cout << "-----------------------------------" << std::endl;
		std::cout << FT_BOLD_Y << "SCOPE" << FT_RST << std::endl;
		std::cout << "-----------------------------------"  << std::endl;
		const Cat *tmpCat = new Cat(basicCat);
		Dog tmpDog;
		tmpDog = basicDog;
		tmpDog.makeSound();
		tmpCat->makeSound();

		std::cout << std::endl;
		tmpDog.getBrain()->setIdea(0, "I want to drink now");
		std::cout << tmpDog.getClassLabel()
				  << tmpDog.getBrain()->getIdea(0) << std::endl;
		delete tmpCat;
	}
	std::cout << std::endl;

	std::cout << basicDog.getClassLabel()
			  << basicDog.getBrain()->getIdea(0) << std::endl;
	basicDog.getBrain()->setIdea(0, "I am not hungry any more");
	std::cout << basicDog.getClassLabel()
			  << basicDog.getBrain()->getIdea(0) << std::endl;
	basicDog.getBrain()->setIdea(1, "I want to sleep ... ZZZZ");
	std::cout << basicDog.getClassLabel()
			  << basicDog.getBrain()->getIdea(1) << std::endl;

	std::cout << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << FT_BOLD_R << "DESTRUCTORS" << FT_RST  << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	delete j; // should not incur any leaks
	delete i;
	for (int k = 0; k < 10; k++)
		delete animals[k];
	return 0;
}
