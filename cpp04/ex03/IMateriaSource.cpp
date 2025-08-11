/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 23:48:21 by abelov            #+#    #+#             */
/*   Updated: 2025/07/24 23:48:22 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

/*
** -------------------------------- STATIC VARS -------------------------------
*/

const std::string IMateriaSource::_className = "ICharacter";
const std::string IMateriaSource::_classLabel = buildClassLabel(_className,
																FT_PALE_TURQUOISE4_B);

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string IMateriaSource::buildClassLabel(const std::string &classname,
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

const std::string &IMateriaSource::getClassName() const
{
	return _className;
}

const std::string &IMateriaSource::getClassLabel() const
{
	return _classLabel;
}
