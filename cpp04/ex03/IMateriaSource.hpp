/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 23:48:12 by abelov            #+#    #+#             */
/*   Updated: 2025/07/24 23:48:12 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <string>
#include "AMateria.hpp"

// ************************************************************************** //
//                           IMateriaSource Class                             //
// ************************************************************************** //

class AMateria;

class IMateriaSource
{
protected:
	static const std::string _className;
	static const std::string _classLabel;

	static std::string buildClassLabel(const std::string &classname,
									   const char *colour);

public:
	virtual ~IMateriaSource() {}

	virtual void learnMateria(AMateria *) = 0;

	virtual AMateria *createMateria(std::string const &type) = 0;

	virtual const std::string &getClassName() const;

	virtual const std::string &getClassLabel() const;

};

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

#endif //IMATERIASOURCE_HPP
