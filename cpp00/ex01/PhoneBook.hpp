/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:46:46 by abelov            #+#    #+#             */
/*   Updated: 2025/02/14 12:46:47 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include <string>
#include "Contact.hpp"

// ************************************************************************** //
//                             PhoneBook Class                                //
// ************************************************************************** //

#define MAX_CONTACT_NUM 8

class PhoneBook
{
public:
	enum Command { ADD, SEARCH, EXIT, NOT_FOUND };
	static Command getCommand(const std::string&);
	static const int		PHONE_BOOK_SIZE;
	PhoneBook();
	~PhoneBook();
private:
	static Contact 			_contacts[MAX_CONTACT_NUM];
	struct CommandMap
	{
		const int	size;
		const struct CommandMapEntry
		{
			const std::string	key;
			const Command		value;
		}			map[3];
	};
	static const CommandMap	_commandMap;



};

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

#endif /* __PHONEBOOK_H__ */
