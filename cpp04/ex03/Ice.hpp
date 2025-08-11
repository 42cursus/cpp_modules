/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:41:53 by abelov            #+#    #+#             */
/*   Updated: 2025/07/26 21:41:54 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

// ************************************************************************** //
//                              AMateria Class                                //
// ************************************************************************** //

class Ice : public AMateria
{
private:
	static const std::string _className;
	static const std::string _classLabel;
	static const std::string MATERIA_TYPE;
public:
	Ice();

	Ice(const Ice &other);

	~Ice();

	AMateria *clone() const;

	void use(ICharacter &target);
};

#endif //ICE_HPP
