/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:43:45 by abelov            #+#    #+#             */
/*   Updated: 2025/07/26 21:43:46 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

// ************************************************************************** //
//                              AMateria Class                                //
// ************************************************************************** //

class Character : public ICharacter
{
private:
	static const std::string &DEFAULT_NAME;
	static const u_int INVENTORY_SIZE = 4;
	static const std::string _className;
	static const std::string _classLabel;
	std::string _name;
	std::string _nameLabel;
	AMateria *_inventory[INVENTORY_SIZE];
	static AMateria *_floor[50];
protected:
	static std::string buildNameLabel(const std::string &classname,
									  const char *colour);

public:
	Character();

	explicit Character(std::string const &name);

	Character(Character const &other);

	~Character();

	Character &operator=(const Character &);

	virtual void equip(AMateria *materia);

	virtual void unequip(int idx);

	virtual void use(int idx, ICharacter &target);

	const std::string &getClassLabel() const;

	const std::string &getName() const;

	const std::string &getNameLabel() const;

	AMateria *getInventory(int idx) const;

	void setInventory(int idx, AMateria *materia);

	static u_int getInventorySize();

	const std::string &getClassName() const;
};

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

#endif //CHARACTER_HPP
