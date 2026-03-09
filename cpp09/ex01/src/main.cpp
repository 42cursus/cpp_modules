/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:27:29 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 23:27:29 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstdlib>

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error: expected exactly one argument." << std::endl;

		// NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-pointer-arithmetic)
		std::cerr << "Usage: " << argv[0] << " <expr>" << std::endl;
		std::cerr << "Evaluates a math expression written in Reverse Polish notation" << std::endl;
		return (EXIT_FAILURE);
	}

	const char *str = argv[1]; // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)

	std::string inputExpr = RPN::trim(str);

	try {
		RPN::checkInput(inputExpr);
		int result = RPN::eval(inputExpr);
		std::cout << result << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
}
