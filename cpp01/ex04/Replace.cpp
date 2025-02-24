/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:55:14 by abelov            #+#    #+#             */
/*   Updated: 2025/02/24 12:55:15 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

std::string Replace::strReplace(std::string line, const std::string &s1,
								const std::string &s2)
{
	std::string result;
	size_t position = 0;
	position = line.find(s1, position);
	while (position != std::string::npos)
	{
		result += line.substr(0, position);
		result += s2;
		position += s1.length();
		line = line.substr(position);
		position = 0;
		position = line.find(s1, position);
	}
	result += line;
	return (result);
}
