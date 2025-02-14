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
	void	setFirstName(const std::string&);
	void	setLastName(const std::string&);
	void	setNickname(const std::string&);
	void	setPhoneNumber(const std::string&);
	void	setDarkestSecret(const std::string&);
	void	printContact(void);
	void	printContactColumn(void);
	int		getContactId(void);
	void	updateContactId(int);
};

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

#endif /* __CONTACT_H__ */
