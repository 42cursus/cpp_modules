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
#include "PhoneBook.hpp"

const int  PhoneBook::PHONE_BOOK_SIZE = MAX_CONTACT_NUM;
int  PhoneBook::amountOfContacts = 0;
int  PhoneBook::nextIndex = 0;

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

	for (int idx = 0; idx < PhoneBook::amountOfContacts; idx++)
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

Contact &PhoneBook::addContact(Contact &contact)
{
	Contact &c = this->_contacts[nextIndex++];
	nextIndex %= MAX_CONTACT_NUM;
	c = contact;
	if (amountOfContacts < MAX_CONTACT_NUM)
		amountOfContacts++;
	return c;
}

Contact &PhoneBook::addContact()
{
	Contact &c = this->_contacts[nextIndex++];
	nextIndex %= MAX_CONTACT_NUM;
	c = Contact("Alice", "Smith", "Ali",
				"1234567890", "hates secrets");
	if (amountOfContacts < MAX_CONTACT_NUM)
		amountOfContacts++;
	return c;
}
