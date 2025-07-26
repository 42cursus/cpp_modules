/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 23:30:55 by abelov            #+#    #+#             */
/*   Updated: 2025/07/26 21:19:34 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip> // for std::setw, std::setfill
#include <sstream> // for std::ostringstream
#include <string>
#include <sys/types.h>
#include "generic.h"

// ************************************************************************** //
//                                Brain Class                                 //
// ************************************************************************** //

#define ARRAY_SIZE 100

class Brain
{
private:
	static const std::string _className;
	static const std::string _classLabel;
	std::string _ideas[ARRAY_SIZE];
public:
	Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	~Brain();

	void setIdea(int i, const std::string& idea);
	std::string getIdea(int i) const;

	static std::string buildClassLabel(const std::string &classname,
									   const char *colour);
	const std::string *getIdeas() const;
	static u_int getArraySize();
};

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

#endif //BRAIN_HPP
