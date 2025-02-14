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

#include "Contact.hpp"

Contact::Contact(int id, const std::string &first_name,
				 const std::string &last_name, const std::string &nickname,
				 const std::string &phone_number,
				 const std::string &darkest_secret)
	: id(id),
	  _firstName(first_name),
	  _lastName(last_name),
	  _nickname(nickname),
	  _phoneNumber(phone_number),
	  _darkestSecret(darkest_secret)
{}

std::ostream &operator<<(std::ostream &os, const Contact &contact)
{
	os << "id: " << contact.id << " _firstName: " << contact._firstName
	   << " _lastName: " << contact._lastName
	   << " _nickname: " << contact._nickname << " _phoneNumber: "
	   << contact._phoneNumber << " _darkestSecret: "
	   << contact._darkestSecret;
	return os;
}

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //