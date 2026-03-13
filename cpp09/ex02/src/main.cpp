/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:32:30 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 23:32:31 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/**
 * Exercise 02: PmergeMe
 */
int main(int argc, char *argv[])
{
	std::vector<int> data;
	if (!PmergeMe::parseInput(argc, argv, data)) {
		std::cerr << "Error" << std::endl;  // NOLINT(performance-avoid-endl)
		return EXIT_FAILURE;
	}

	std::cout << "Before: ";
	PmergeMe::printValues(data);

	std::vector<int> sorted = PmergeMe::fordJohnsonSort(data);
	std::cout << "After: ";
	PmergeMe::printValues(sorted);

	return EXIT_SUCCESS;
}
