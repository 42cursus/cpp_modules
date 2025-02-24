/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:20:02 by abelov            #+#    #+#             */
/*   Updated: 2025/02/24 13:20:02 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

#define FT_RED    "\033[0;31m"
#define FT_BOLD   "\033[1m"        /* Bold */
#define FT_UND    "\033[4m"        /* Underline */

#define FT_GREEN  "\033[0;32m"    /* Green */
#define FT_CYAN   "\033[36m"
#define FT_BOLD_R "\033[1;31m"    /* Bold red */
#define FT_BOLD_G "\033[1;32m"    /* Bold green */
#define FT_BOLD_B "\033[1;34m"    /* Bold blue */
#define FT_BOLD_Y "\033[1;33m"    /* Bold yellow */
#define FT_BOLD_M "\033[1;35m"    /* Bold magenta */
#define FT_BOLD_C "\033[1;36m"    /* Bold cyan */
#define FT_BOLD_W "\033[1;37m"    /* Bold white */
#define FT_RESET  "\033[0m"        /* Reset to default color */

// ************************************************************************** //
//                                 Harl Class                                 //
// ************************************************************************** //

class Harl
{

private:
	static const std::string _levels[4];

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	typedef void (Harl::*t_function)(void);
	static const t_function _harl_complains[4]; // Static table
public:
	Harl();
	~Harl();
	void complain(const std::string &level);
	void harlFilter(const std::string &level);
};

#endif //HARL_HPP
