/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:32:30 by abelov            #+#    #+#             */
/*   Updated: 2026/03/13 21:35:14 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/**
 * Exercise 02: PmergeMe
 */
int main(int argc, char *argv[])
{
	if (argc < 2) {
		std::cerr << "Error" << std::endl; // NOLINT(performance-avoid-endl)
		return EXIT_FAILURE;
	}

	std::vector<int> data;
	if (!PmergeMe::parseInput(argc, argv, data)) {
		std::cerr << "Error" << std::endl; // NOLINT(performance-avoid-endl)
		return EXIT_FAILURE;
	}

	std::cout << "Before: ";
	PmergeMe::printValues(data);

	std::vector<int> sorted = PmergeMe::fordJohnsonSort(data);
	std::cout << "After: ";
	PmergeMe::printValues(sorted);

	return EXIT_SUCCESS;
}
