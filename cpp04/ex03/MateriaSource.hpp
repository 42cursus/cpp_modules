/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 18:53:38 by abelov            #+#    #+#             */
/*   Updated: 2025/07/27 18:53:38 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip> // for std::setw, std::setfill
#include <sstream> // for std::ostringstream
#include <string>
#include <sys/types.h>
#include "generic.h"
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{

private:
	static const std::string &DEFAULT_NAME;
	static const u_int INVENTORY_SIZE = 4;
	static const std::string _className;
	static const std::string _classLabel;
	std::string _name;
	std::string _nameLabel;
	AMateria *_inventory[INVENTORY_SIZE];
public:
	MateriaSource();

	explicit MateriaSource(std::string const &name);

	MateriaSource(MateriaSource const &other);

	~MateriaSource();

	MateriaSource &operator=(MateriaSource);

	void swap(MateriaSource &first, MateriaSource &second);

	const std::string &getClassLabel() const;

	const std::string &getName() const;

	const std::string &getNameLabel() const;

	void learnMateria(AMateria *materia);

	AMateria *createMateria(const std::string &type);

	AMateria *const *getInventory() const;

	void setInventory(int idx, AMateria *materia);
};

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

#endif //MATERIASOURCE_HPP
