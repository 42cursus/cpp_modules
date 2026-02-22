/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:49:39 by abelov            #+#    #+#             */
/*   Updated: 2026/02/22 18:25:52 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span spn = Span(5);

	spn.addNumber(6);
	spn.addNumber(3);
	spn.addNumber(17);
	spn.addNumber(9);
	spn.addNumber(11);

	std::cout << spn.shortestSpan() << std::endl;
	std::cout << spn.longestSpan() << std::endl;

	try {
		spn.addNumber(20);
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	Span spn2 = Span(5);
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(100);
	vec.push_back(150);
	vec.push_back(500);

	try {
		spn2.addNumber(vec);
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	try {
		std::cout << spn2.shortestSpan() << std::endl;
		std::cout << spn2.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	Span sp3 = Span(1984);
	for (int i = 0; i < 1984; i++)
		sp3.addNumber(i);
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;

	return (0);
}
