/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:20:06 by abelov            #+#    #+#             */
/*   Updated: 2025/02/24 13:20:06 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include "Harl.hpp"

Harl::~Harl() {}
Harl::Harl() {}

void Harl::debug()
{
	std::cout << FT_BOLD_W"I love having extra bacon for my "
				 "7XL-double-cheese-triple-pickle-special-ketchup burger. "
				 "I really do!" << FT_RST << std::endl;
}

void Harl::info()
{
	std::cout
		<< FT_BOLD_G"I cannot believe adding extra bacon costs more money. "
		   "You didn’tput enough bacon in my burger! If you did, "
		   "I wouldn’t be asking for more!" << FT_RST << std::endl;
}

void Harl::warning()
{
	std::cout
		<< FT_CYAN"I think I deserve to have some extra bacon for free. "
		   "I’ve been coming for years whereas you started working here "
		   "since last month." << FT_RST << std::endl;
}

void Harl::error()
{
	std::cout << FT_RED"This is unacceptable! "
				 "I want to speak to the manager now." << FT_RST << std::endl;
}

const std::string Harl::_levels[4] = {
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR"
};

const Harl::t_function Harl::_harl_complains[4] = {
	&Harl::debug,
	&Harl::info,
	&Harl::warning,
	&Harl::error
};

void Harl::complain(const std::string &level)
{
	for (int i = 0; i < 4; ++i)
	{
		if (level == _levels[i])
		{
			(this->*_harl_complains[i])();
			break;
		}
	}

	std::cerr << FT_BOLD_Y"Invalid level: " << level << FT_RST << std::endl;
}

void Harl::harlFilter(const std::string &level)
{
	int index = -1;
	for (int i = 0; i < 4; ++i)
	{
		if (level == _levels[i])
		{
			index = i;
			break;
		}
	}
	switch (index)
	{
		case 0:
			std::cout << "[ " << _levels[0] << " ]" << std::endl;
			(this->*_harl_complains[0])();
			std::cout << std::endl;
			/* fallthrough */
		case 1:
			std::cout << "[ " << _levels[1] << " ]" << std::endl;
			(this->*_harl_complains[1])();
			std::cout << std::endl;
			/* fallthrough */
		case 2:
			std::cout << "[ " << _levels[2] << " ]" << std::endl;
			(this->*_harl_complains[2])();
			std::cout << std::endl;
			/* fallthrough */
		case 3:
			std::cout << "[ " << _levels[3] << " ]" << std::endl;
			(this->*_harl_complains[3])();
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]"
					  << std::endl;
	}
}
