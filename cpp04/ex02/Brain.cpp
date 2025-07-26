/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:48:50 by abelov            #+#    #+#             */
/*   Updated: 2025/07/26 21:19:30 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*
** -------------------------------- STATIC VARS -------------------------------
*/

const std::string Brain::_className = "Brain";
const std::string Brain::_classLabel = buildClassLabel(_className,
														FT_SALMON);

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

Brain::Brain()
{
	std::cout << _classLabel
			  << FT_DIM_GREEN"'default' constructor called" FT_RST << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << _classLabel
			  << FT_DIM_GREEN"'copy' constructor called" << std::endl;
	for (int i = 0; i < (int)ARRAY_SIZE; i++)
		_ideas[i]= other._ideas[i];
}

/*
** ------------------------------- DESTRUCTOR ---------------------------------
*/

Brain::~Brain()
{
	std::cout << _classLabel
			  << FT_LIGHT_BROWN"destructor" FT_RST << " called" << std::endl;
}

/*
** -------------------------------- OPERATORS ---------------------------------
*/

Brain& Brain::operator=(const Brain& other)
{
	std::cout << _classLabel
			  << "copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < (int)ARRAY_SIZE; i++)
			_ideas[i] = other._ideas[i];
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string Brain::buildClassLabel(const std::string& classname,
									const char *colour)
{
	std::ostringstream oss;
	oss << std::left << std::setw(CLASS_NAME_PADDING) << (classname + ":");

	std::string label = oss.str();
	label.insert(0, colour);
	label.insert(classname.length() + std::strlen(colour), FT_RST);
	return label;
}

/*
** -------------------------------- ACCESSORS ---------------------------------
*/

const std::string *Brain::getIdeas() const
{
	return _ideas;
}

u_int Brain::getArraySize()
{
	return ARRAY_SIZE;
}

void Brain::setIdea(int i, const std::string& idea)
{
	_ideas[i] = idea;
}

std::string Brain::getIdea(int i) const
{
	return _ideas[i];
}
