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
#include <iostream>

int	main(int argc, char *argv[])
{
	BitcoinExchange	exchange;

	if (argc != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}

	try {
		exchange.process_input(argv[1]);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

}
