/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 23:45:43 by abelov            #+#    #+#             */
/*   Updated: 2025/07/24 23:45:44 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main()
{
	{
		std::cout << FT_BLUE << "----- Test: -----"
				  << std::endl << std::endl;

		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter *me = new Character("me");
		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter *bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}

	{
		std::cout << FT_GREEN << std::endl
				  << "----- Character with Materias: -----" << std::endl
				  << std::endl;

		IMateriaSource *materia_source = new MateriaSource();
		materia_source->learnMateria(new Cure());
		ICharacter *alf = new Character("Alf");
		for (int i = 0; i < 56; i++)
			alf->equip(materia_source->createMateria("cure"));
		delete materia_source;
		delete alf;
	}

	{
		std::cout << FT_ORANGE << std::endl
				  << "----- Copy constructor and assignment operator  -----"
				  << std::endl << std::endl;

		IMateriaSource *materiaSource = new MateriaSource();
		AMateria *cure = new Cure();
		materiaSource->learnMateria(cure);
		AMateria *temp_materia = materiaSource->createMateria("cure");
		Character *bert = new Character("Bert");
		bert->equip(temp_materia);
		Character *casper = new Character(*bert);
		casper->use(0, *bert);
		casper->use(0, *bert);
		Character *dobby = new Character("Dobby");
		*dobby = *bert;
		dobby->use(0, *bert);
		delete materiaSource;
		delete bert;
		delete casper;
		delete dobby;
	}
}
