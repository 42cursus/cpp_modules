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

std::ostream &operator<<(std::ostream &os, const PhoneBook &phoneBook)
{
	phoneBook.print(os);
	return os;
}

std::string ftStrTrim(const std::string& str) {
	std::string substr;
	const std::string whitespace = " \t\n\r\f\v";

	// Find the first non-whitespace character
	std::string::size_type start = str.find_first_not_of(whitespace);
	if (start != std::string::npos)
	{
		std::string::size_type end = str.find_last_not_of(whitespace);
		substr = str.substr(start, end - start + 1);
	}
	else
		substr = "";
	return substr;
}

int	main()
{
	PhoneBook phoneBook;
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
				phoneBook.addContact();
				break;
			case PhoneBook::SEARCH:
				std::cout << "SEARCH entered" << std::endl;
				std::cout << phoneBook << std::endl;
				break;
			case PhoneBook::EXIT:
				std::cout << "Exiting the program" << std::endl;
				break;
			case PhoneBook::NOT_FOUND:
			default:
				std::cout << "Command not found. Please try again."
						  << std::endl;
				break;
		}
		if (command == PhoneBook::EXIT)
			break;
	}
	return (0);
}
