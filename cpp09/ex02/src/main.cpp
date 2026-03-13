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
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

void pair_blocks_by_last(const std::vector<int>& data, std::vector<std::size_t>& ord, std::size_t blockSize)
{
	std::size_t i = 0;

	while (i + 2 * blockSize <= ord.size()) {

		std::size_t leftBlockStart = i;
		std::size_t rightBlockStart = i + blockSize;

		std::size_t leftKeyIndex = ord[leftBlockStart + blockSize - 1];
		std::size_t rightKeyIndex = ord[rightBlockStart + blockSize - 1];

		if (data[leftKeyIndex] > data[rightKeyIndex]) {
			std::size_t j = 0;
			while (j < blockSize) {
				std::swap(ord[leftBlockStart + j], ord[rightBlockStart + j]);
				++j;
			}
		}

		i += 2 * blockSize;
	}
}

void pair_adjacent(const std::vector<int>& data, std::vector<std::size_t>& ord)
{
	std::size_t i = 0;

	for (; i + 1 < ord.size(); i += 2) {
		if (data[ord[i]] > data[ord[i + 1]])
			std::swap(ord[i], ord[i + 1]);
	}

}

static void print_ordered_values(const std::vector<int>& data, const std::vector<std::size_t>& ord)
{
	for (std::size_t i = 0; i < ord.size(); ++i) {
		std::cout << data[ord[i]];
		if (i + 1 < ord.size())
			std::cout << " ";
	}
	std::cout << std::endl;
}

/**
 * Exercise 02: PmergeMe
 */
int main(int argc, char *argv[])
{
	int raw[] = {
		11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21,
		1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7
	};
	const std::size_t size = sizeof(raw) / sizeof(raw[0]);

	std::vector<int> data(&raw[0], &raw[0] + size);

	std::vector<std::size_t> ord(data.size());
	std::generate(ord.begin(), ord.end(), PmergeMe::IndexGenerator());

	std::cout << "Before: ";
	print_ordered_values(data, ord);

	pair_adjacent(data, ord);

	std::cout << "After pair stage: ";
	print_ordered_values(data, ord);

	std::vector<int> sorted = ford_johnson_sort_impl(data, std::less<int>());
	std::cout << "Result: ";
	PmergeMe::printRange(sorted.begin(), sorted.end());

	return (EXIT_SUCCESS);
	(void)argc;
	(void)argv;
}
