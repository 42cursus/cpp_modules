/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:42:30 by abelov            #+#    #+#             */
/*   Updated: 2025/07/26 21:42:31 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

// ************************************************************************** //
//                              AMateria Class                                //
// ************************************************************************** //

class Cure : public AMateria
{
private:
	static const std::string _className;
	static const std::string _classLabel;
	static const std::string MATERIA_TYPE;
public:
	Cure();

	Cure(const Cure &other);

	~Cure();

	Cure &operator=(Cure other);

	AMateria *clone() const;

	void use(ICharacter &target);
};

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

#endif //CURE_HPP
