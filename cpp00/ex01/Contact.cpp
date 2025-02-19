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
	os << "Id: " << getId() << "\n"
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
	return _id;
}

const std::string &Contact::getNickname() const
{
	return _nickname;
}
// Default constructor
Contact::Contact() : _id(getUniqueId()) {}

// Copy constructor
Contact::Contact(const Contact &other)
	: _id(other._id), _firstName(other._firstName), _lastName(other._lastName),
	  _nickname(other._nickname), _phoneNumber(other._phoneNumber),
	  _darkestSecret(other._darkestSecret) {}

// Parameterized constructor
Contact::Contact(const std::string &first_name, const std::string &last_name,
				 const std::string &nickname, const std::string &phone_number,
				 const std::string &darkest_secret):
					_id(getUniqueId()),
					_firstName(first_name),
					_lastName(last_name),
					_nickname(nickname),
					_phoneNumber(phone_number),
					_darkestSecret(darkest_secret)
{}

int Contact::getUniqueId()
{
	static int uid = { 0 };
	return uid++;
}

// Copy assignment operator
Contact &Contact::operator=(const Contact &other)
{
	if (this != &other) { // Self-assignment check
		_id = other._id;
		_firstName = other._firstName;
		_lastName = other._lastName;
		_nickname = other._nickname;
		_phoneNumber = other._phoneNumber;
		_darkestSecret = other._darkestSecret;
	}
	return *this;
}

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
