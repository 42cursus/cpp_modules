/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:40:45 by abelov            #+#    #+#             */
/*   Updated: 2025/02/14 14:40:45 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"


int	main()
{
	PhoneBook pb;
	std::string input;

	while (true)
	{
		std::cout << "Please enter one of the three commands: ADD, SEARCH, EXIT"
				  << std::endl;
		std::getline(std::cin, input);

		PhoneBook::Command command = PhoneBook::getCommand(input);
		switch (command)
		{
			case PhoneBook::ADD:
				break;
			case PhoneBook::SEARCH:
				std::cout << "SEARCH entered" << std::endl;
				break;
			case PhoneBook::EXIT:
				std::cout << "Exiting the program" << std::endl;
				break;
			case PhoneBook::NOT_FOUND:
			default:
				std::cout << "Command not found. Please try again." << std::endl;
				break;
		}
		if (command == PhoneBook::EXIT)
			break;
	}
	return (0);
}
