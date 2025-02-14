/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:46:53 by abelov            #+#    #+#             */
/*   Updated: 2025/02/14 12:46:54 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <string>
#include <ostream>

// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class Contact
{

private:
	int			id;
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

public:
	Contact(int id, const std::string &first_name,
			const std::string &last_name, const std::string &nickname,
			const std::string &phone_number, const std::string &darkest_secret);

	friend std::ostream &operator<<(std::ostream &os, const Contact &contact);
};

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

#endif /* __CONTACT_H__ */
