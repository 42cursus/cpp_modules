/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:46:56 by abelov            #+#    #+#             */
/*   Updated: 2025/02/14 12:46:57 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

void Contact::print(std::ostream &os)
{
	os << "ID: " << id << "\n"
	   << "First Name: " << _firstName << "\n"
	   << "Last Name: " << _lastName << "\n"
	   << "Nickname: " << _nickname << "\n"
	   << "Phone Number: " << _phoneNumber << "\n"
	   << "Darkest Secret: " << _darkestSecret;
}

const std::string &Contact::getFirstName() const
{
	return _firstName;
}

const std::string &Contact::getLastName() const
{
	return _lastName;
}

int Contact::getId() const
{
	return id;
}

const std::string &Contact::getNickname() const
{
	return _nickname;
}

Contact::Contact(const std::string &first_name, const std::string &last_name,
				 const std::string &nickname, const std::string &phone_number,
				 const std::string &darkest_secret):
					_firstName(first_name),
					_lastName(last_name),
					_nickname(nickname),
					_phoneNumber(phone_number),
					_darkestSecret(darkest_secret)
{
	id = getUniqueId();
}

Contact::Contact()
{
	id = getUniqueId();
}

int Contact::getUniqueId()
{
	static int uid = { -8 };
	return uid++;
}

std::ostream &operator<<(std::ostream &os, Contact &contact)
{
	contact.print(os);
	return os;
}

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
