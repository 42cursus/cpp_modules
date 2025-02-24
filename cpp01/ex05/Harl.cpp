/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:13:53 by abelov            #+#    #+#             */
/*   Updated: 2025/02/24 13:13:54 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug()
{
	std::cout << FT_BOLD_W"DEBUG: I love having extra bacon for my "
				 "7XL-double-cheese-triple-pickle-special-ketchup burger. "
				 "I really do!" << FT_RESET << std::endl;
}

void Harl::info()
{
	std::cout << FT_BOLD_G"INFO: I cannot believe adding extra bacon costs more money. "
				 "You didn’tput enough bacon in my burger! If you did, "
				 "I wouldn’t be asking for more!" << FT_RESET << std::endl;
}

void Harl::warning()
{
	std::cout
		<< FT_CYAN"WARNING: I think I deserve to have some extra bacon for free. "
		   "I’ve been coming for years whereas you started working here "
		   "since last month." << FT_RESET << std::endl;
}

void Harl::error()
{
	std::cout << FT_RED"ERROR: This is unacceptable! "
				 "I want to speak to the manager now." << FT_RESET << std::endl;
}

void Harl::complain(const std::string &level)
{

	void (Harl::*complaints[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*complaints[i])();
			return;
		}
	}

	std::cerr << FT_BOLD_Y"Invalid level: " << level << FT_RESET << std::endl;
}
