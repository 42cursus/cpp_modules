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
#include <ostream>
#include "Contact.hpp"

/**
 * we use either `\e` to represent the escape character (ESC or ASCII 27)
 * or `\033` (octal representation of ESC).
 *
 * Note:
 * 	`\e` is a GCC extension and is not part of the standard C language.
 */

#define FT_RED    "\033[0;31m"
#define FT_BOLD   "\033[1m"		/* Bold */
#define FT_UND    "\033[4m"		/* Underline */

#define FT_GREEN  "\033[0;32m"	/* Green */
#define FT_CYAN   "\033[36m"
#define FT_BOLD_R "\033[1;31m"	/* Bold red */
#define FT_BOLD_G "\033[1;32m"	/* Bold green */
#define FT_BOLD_B "\033[1;34m"	/* Bold blue */
#define FT_BOLD_Y "\033[1;33m"	/* Bold yellow */
#define FT_BOLD_M "\033[1;35m"	/* Bold magenta */
#define FT_BOLD_C "\033[1;36m"	/* Bold cyan */
#define FT_BOLD_W "\033[1;37m"	/* Bold white */
#define FT_RESET  "\033[0m"		/* Reset to default color */

// ************************************************************************** //
//                             PhoneBook Class                                //
// ************************************************************************** //

#define MAX_CONTACT_NUM 8

class PhoneBook
{
public:
	enum Command { ADD, SEARCH, EXIT, NOT_FOUND };

private:
	Contact 				_contacts[MAX_CONTACT_NUM];
	static const int		_phoneBookSize;
	int						_amountOfContacts;
	int						_nextIndex;
	struct CommandMap
	{
		const int	size;
		const struct CommandMapEntry
		{
			const std::string	key;
			const Command		value;
		}					map[3];
	};
	static const CommandMap	_commandMap;
public:
	PhoneBook();
	static std::string	ftStrTrim(const std::string &str);
	static Command		getCommand(const std::string&);
	static int getSanitizedUserInput(Contact &c);
	int 				getAmountOfContacts();
	Contact				&getContactByIndex(int index);
	void				searchByIndex();
	Contact				&addContact(const Contact& contact);
	void				print(std::ostream &os) const;
	static std::string	formatColumn(const std::string &str);
	static int readField(const std::string& prompt, std::string &field);
};

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

#endif /* __PHONEBOOK_H__ */
