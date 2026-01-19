/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 23:46:13 by abelov            #+#    #+#             */
/*   Updated: 2025/07/24 23:46:14 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <cstring>
#include <iostream>
#include <iomanip> // for std::setw, std::setfill
#include <sstream> // for std::ostringstream
#include <string>
#include <sys/types.h>
#include "generic.h"

#include "ICharacter.hpp"

// ************************************************************************** //
//                              AMateria Class                                //
// ************************************************************************** //

class Character;
class ICharacter;
class MateriaSource;
class IMateriaSource;

class AMateria
{
private:
	static const std::string _className;
	static const std::string _classLabel;
protected:
	bool _isOnFloor;
	std::string _type;
	MateriaSource *_materia_source;
public:
	AMateria();

	explicit AMateria(std::string const &type);

	AMateria(const AMateria &other);

	MateriaSource *getMateriaSource() const;

	void setMateriaSource(MateriaSource *materia_source);

	virtual ~AMateria();

	AMateria &operator=(AMateria const &other);

	std::string const &getType() const; // Returns the materia tag
	static std::string buildClassLabel(const std::string &classname,
									   const char *colour);

	virtual AMateria *clone() const = 0;

	virtual void use(ICharacter &target) = 0;
};

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

#endif //AMATERIA_HPP
