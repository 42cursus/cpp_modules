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

#include <iomanip>
#include <iostream>
#include <limits>
#include <cstdio>
#include "PhoneBook.hpp"

const int  PhoneBook::_phoneBookSize = MAX_CONTACT_NUM;

std::string PhoneBook::ftStrTrim(const std::string &str)
{
	std::string substr;
	const std::string whitespace = " \t\n\r\f\v";

	// Find the first non-whitespace character
	std::string::size_type start = str.find_first_not_of(whitespace);
	if (start != std::string::npos)
	{
		std::string::size_type end = str.find_last_not_of(whitespace);
		substr = str.substr(start, end - start + 1);
	}
	else
		substr = "";
	return substr;
}

int PhoneBook::readField(const std::string &prompt, std::string &field)
{
	int status = 0;

	std::string input;
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input)) {
			if (std::cin.eof()) {
				std::cin.clear();
				freopen("/dev/tty", "r", stdin);
				status = -1;
				break;
			}
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard bad input
			std::cout << "Invalid input. Try again.\n";
			continue;
		}
		field = ftStrTrim(input);
		if (!field.empty())
			break;
		std::cout << "Field cannot be empty. Please enter a valid value.\n";
	}
	return (status);
}

const PhoneBook::CommandMap PhoneBook::_commandMap = {
	.size = 3,
	.map = {
		{.key = std::string("ADD"), .value = ADD},
		{.key = std::string("SEARCH"), .value = SEARCH},
		{.key = std::string("EXIT"), .value = EXIT},
	}
};

PhoneBook::Command PhoneBook::getCommand(const std::string &input)
{
	Command command = NOT_FOUND;
	for (int i = 0; i < _commandMap.size; i++)
	{
		const CommandMap::CommandMapEntry &cmd = _commandMap.map[i];
		if (cmd.key == input)
			command = cmd.value;
	}
	return (command);
}

std::string PhoneBook::formatColumn(const std::string &str)
{
	const int width = 10;
	if (str.length() > width)
		return str.substr(0, width - 1) + ".";
	return std::string(width - str.length(), ' ') + str;
}

void PhoneBook::print(std::ostream &os) const
{
	os << '|' << formatColumn("Index") << '|'
	   << formatColumn("First name") << '|'
	   << formatColumn("Last name") << '|'
	   << formatColumn("Nickname") << '|'
	   << std::endl;

	for (int idx = 0; idx < PhoneBook::_amountOfContacts; idx++)
	{
		const Contact &contact = this->_contacts[idx];
		os << "|" << std::setw(10) << idx
		   << "|" << formatColumn(contact.getFirstName())
		   << "|" << formatColumn(contact.getLastName())
		   << "|" << formatColumn(contact.getNickname()) << "|\n";
	}
}

Contact &PhoneBook::getContactByIndex(int index)
{
	return this->_contacts[index];
}

Contact &PhoneBook::addContact(const Contact &contact)
{
	Contact &c = this->_contacts[this->_nextIndex++];
	c = contact;
	this->_nextIndex %= _phoneBookSize;
	if (_amountOfContacts < _phoneBookSize)
		_amountOfContacts++;
	return c;
}

int PhoneBook::getSanitizedUserInput(Contact &c)
{
	std::string cmd_search;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_nbr;
	std::string darkest_secret;

	if (readField("First name: ", first_name)
		|| readField("Last name: ", last_name)
		|| readField("Nickname: ", nickname)
		|| readField("Phone number: ", phone_nbr)
		|| readField("Darkest secret: ", darkest_secret))
		return (-1);
	c = Contact(first_name, last_name, nickname,
				phone_nbr, darkest_secret);
	return (0);
}

int PhoneBook::getAmountOfContacts()
{
	return _amountOfContacts;
}

std::ostream &operator<<(std::ostream &os, Contact &contact)
{
	contact.print(os);
	return os;
}

void PhoneBook::searchByIndex()
{
	std::cout << FT_BOLD_M "Select an index between 0 and "
			  << getAmountOfContacts() - 1 << ": " FT_RESET;
	bool validInput = false;
	int index = 0;
	do
	{
		std::cin >> index;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cout << FT_RED "The value entered is not valid\n" FT_RESET;
			validInput = false;
		}
		else if (index < 0 || index >= _amountOfContacts)
			std::cout
				<< FT_RED "Invalid index. Please select an index between 0 and "
				<< _amountOfContacts - 1 << "\n" FT_RESET;
		else
			validInput = true;
	}
	while (!validInput);
	std::cout << getContactByIndex(index) << std::endl;
}
