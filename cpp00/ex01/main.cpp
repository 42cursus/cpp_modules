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
#include <limits>
#include "PhoneBook.hpp"

std::ostream &operator<<(std::ostream &os, const PhoneBook &phoneBook)
{
	phoneBook.print(os);
	return os;
}

std::string &toUpper(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = static_cast<char>(std::toupper(
			static_cast<unsigned char>(str[i])));
	return (str);
}

int main()
{
	PhoneBook phoneBook;
	std::string input;
	Contact c;

	while (true)
	{
		std::cout << std::endl
				  << "Please enter one of the three commands: ADD, SEARCH, EXIT"
				  << std::endl;

		if (!std::getline(std::cin, input)) {
			if (std::cin.eof()) {
				std::cout << "\nEOF reached. Exiting...\n";
				break;
			}
			std::cin.clear();  // Clear error state (needed for other input errors, not EOF)
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard bad input
			std::cout << "Invalid input. Try again.\n";
		}
		else
			std::cout << "You entered: " << toUpper(input) << std::endl;
		PhoneBook::Command command = PhoneBook::getCommand(toUpper(input));
		switch (command)
		{
			case PhoneBook::ADD:
				if (!PhoneBook::getSanitizedUserInput(c))
					phoneBook.addContact(c);
				else
					std::cout << "Input interrupted" << std::endl;
				break;
			case PhoneBook::SEARCH:
				if (!phoneBook.getAmountOfContacts())
					std::cout << "PhoneBook is empty" << std::endl;
				else
				{
					std::cout << phoneBook << std::endl << std::endl;
					phoneBook.searchByIndex();
				}
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
