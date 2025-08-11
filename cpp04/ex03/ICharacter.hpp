/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 23:47:31 by abelov            #+#    #+#             */
/*   Updated: 2025/07/24 23:47:31 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"

class AMateria;

// ************************************************************************** //
//                             ICharacter Class                               //
// ************************************************************************** //

class ICharacter
{
private:
	static const std::string _className;
	static const std::string _classLabel;
protected:
	ICharacter();

	static std::string buildClassLabel(const std::string &classname,
									   const char *colour);

public:
	virtual ~ICharacter()
	{}

	virtual const std::string &getClassLabel() const;

	virtual const std::string &getClassName() const;

	virtual std::string const &getName() const = 0;

	virtual std::string const &getNameLabel() const = 0;

	virtual void equip(AMateria *m) = 0;

	virtual void unequip(int idx) = 0;

	virtual void use(int idx, ICharacter &target) = 0;
};

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

#endif //ICHARACTER_HPP
