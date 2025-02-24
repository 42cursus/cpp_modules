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
	std::cout << "DEBUG: I love having extra bacon for my "
				 "7XL-double-cheese-triple-pickle-special-ketchup burger. "
				 "I really do!\n";
}

void Harl::info()
{
	std::cout << "INFO: I cannot believe adding extra bacon costs more money. "
				 "You didn’tput enough bacon in my burger! If you did, "
				 "I wouldn’t be asking for more!\n";
}

void Harl::warning()
{
	std::cout<< "WARNING: I think I deserve to have some extra bacon for free. "
				"I’ve been coming for years whereas you started working here "
				"since last month.\n";
}

void Harl::error()
{
	std::cout << "ERROR: This is unacceptable! "
				 "I want to speak to the manager now.\n";
}

void Harl::complain(const std::string& level)
{

}
