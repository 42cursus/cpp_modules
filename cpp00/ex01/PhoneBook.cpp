/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:44:39 by abelov            #+#    #+#             */
/*   Updated: 2025/02/14 12:44:40 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

const PhoneBook::CommandMap PhoneBook::_commandMap = {
	.size = 3,
	.map = {
		{.key = std::string("ADD"), .value = ADD},
		{.key = std::string("SEARCH"), .value = SEARCH},
		{.key = std::string("EXIT"), .value = EXIT},
	}
};

PhoneBook::PhoneBook()
{

}

PhoneBook::~PhoneBook()
{

}

PhoneBook::Command PhoneBook::getCommand(const std::string &input)
{
	Command	cmd = NOT_FOUND;
	for (int i = 0; i < _commandMap.size; i++)
		if (_commandMap.map[i].key == input)
			cmd = _commandMap.map[i].value;
	return (cmd);
}
