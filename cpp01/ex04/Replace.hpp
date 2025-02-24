/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:49:44 by abelov            #+#    #+#             */
/*   Updated: 2025/02/24 12:49:44 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>

// ************************************************************************** //
//                               Replace Class                                //
// ************************************************************************** //

class Replace
{
public:
	static std::string strReplace(std::string line,
								  const std::string &s1, const std::string &s2);
};


#endif //REPLACE_HPP
