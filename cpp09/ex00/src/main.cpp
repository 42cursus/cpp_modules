/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:26:00 by abelov            #+#    #+#             */
/*   Updated: 2026/02/25 00:49:06 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	BitcoinExchange exchange;

	if (argc != 2) {
		std::cerr << "Error: expected exactly one argument." << std::endl;

		// NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-pointer-arithmetic)
		std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
		return (EXIT_FAILURE);
	}

	try {
		const char *filename = static_cast<const char *>(BitcoinExchange::DATABASE_FILENAME);
		exchange.loadDatabase(filename);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		std::cerr << "Error: Could not create database." << std::endl;
		return (EXIT_FAILURE);
	}

	try {
		const char *inputFileName = argv[1]; // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
		exchange.processInput(inputFileName);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
