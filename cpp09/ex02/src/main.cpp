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
#include <ctime>
#include <iomanip>

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

	const std::clock_t vectorStart = std::clock();
	std::vector<int> sorted = PmergeMe::fordJohnsonSort(data);
	const std::clock_t vectorEnd = std::clock();

	const std::list<int> listData(data.begin(), data.end());
	const std::clock_t listStart = std::clock();
	const std::list<int> sortedList = PmergeMe::fordJohnsonSort(listData);
	const std::clock_t listEnd = std::clock();

	std::cout << "After: ";
	PmergeMe::printValues(sorted);

	(void)sortedList;
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << data.size()
			  << " elements with std::vector : " << PmergeMe::elapsedTime(vectorStart, vectorEnd) << " us"
			  << std::endl; // NOLINT(performance-avoid-endl)
	std::cout << "Time to process a range of " << data.size()
			  << " elements with std::list   : " << PmergeMe::elapsedTime(listStart, listEnd) << " us"
			  << std::endl; // NOLINT(performance-avoid-endl)

	return EXIT_SUCCESS;
}
