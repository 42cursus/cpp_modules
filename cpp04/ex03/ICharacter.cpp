/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 23:55:09 by abelov            #+#    #+#             */
/*   Updated: 2025/07/24 23:55:09 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

/*
** -------------------------------- STATIC VARS -------------------------------
*/

const std::string ICharacter::_className = "ICharacter";
const std::string ICharacter::_classLabel = buildClassLabel(_className,
															FT_PALE_TURQUOISE4_B);

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

ICharacter::ICharacter()
{
	std::cout << _classLabel
			  << FT_DIM_GREEN"'default' constructor called" FT_RST << std::endl;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string ICharacter::buildClassLabel(const std::string &classname,
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

const std::string &ICharacter::getClassName() const
{
	return _className;
}

const std::string &ICharacter::getClassLabel() const
{
	return _classLabel;
}
