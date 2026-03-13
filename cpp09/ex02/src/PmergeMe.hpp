/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:32:45 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 23:32:46 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <iostream>
#include <vector>
class PmergeMe
{
public:
	struct IndexGenerator
	{
		std::size_t current;
		IndexGenerator() : current(0) {}
		std::size_t operator()();
	};
	template <typename Iterator>
	static void printRange(Iterator begin, Iterator end);
	static std::vector<size_t> buildJacobsthalOrder(size_t count);
};

template <typename Iterator>
void PmergeMe::printRange(Iterator begin, Iterator end)
{
	if (begin == end) {
		std::cout << std::endl; // NOLINT(performance-avoid-endl)
		return;
	}

	std::cout << *begin;
	for (++begin; begin != end; ++begin)
		std::cout << ", " << *begin;

	std::cout << std::endl; // NOLINT(performance-avoid-endl)
}


template <typename T>
struct TaggedValue {
	T value;
	std::size_t pairIndex;

	TaggedValue() : value(), pairIndex(0) {}
	TaggedValue(const T &v, std::size_t p) : value(v), pairIndex(p) {}
};

template <typename T>
static std::size_t find_pair_bound(const std::vector< TaggedValue<T> > &chain, std::size_t pairIndex)
{
	std::size_t result = chain.size();

	for (std::size_t i = 0; i < chain.size(); ++i) {
		if (chain[i].pairIndex == pairIndex) {
			result = i;
			break;
		}
	}
	return result;
}

template <typename T, typename Compare>
static void bounded_binary_insert(
	std::vector< TaggedValue<T> > &chain,
	const TaggedValue<T> &value,
	std::size_t upperBound,
	Compare comp)
{
	std::size_t left = 0;
	std::size_t right = upperBound;

	while (left < right) {
		std::size_t mid = left + ((right - left) / 2);
		if (comp(chain[mid].value, value.value))
			left = mid + 1;
		else
			right = mid;
	}
	chain.insert(chain.begin() + left, value);
}


template <typename T, typename Compare>
static std::vector<T> ford_johnson_sort_impl(const std::vector<T> &input, Compare comp)
{
	if (input.size() <= 1)
		return input;

	std::vector<T> smalls;
	std::vector<T> larges;
	std::vector<std::size_t> largePairIndices;

	std::size_t pairIndex = 1;
	for (std::size_t i = 0; i + 1 < input.size(); i += 2) {
		T first = input[i];
		T second = input[i + 1];

		if (comp(second, first))
			std::swap(first, second);

		smalls.push_back(first);
		larges.push_back(second);
		largePairIndices.push_back(pairIndex);
		++pairIndex;
	}

	bool hasStraggler = false;
	T straggler = T();

	if (input.size() % 2 != 0) {
		hasStraggler = true;
		straggler = input[input.size() - 1];
	}

	std::vector<T> sortedLarges = ford_johnson_sort_impl(larges, comp);

	std::vector<TaggedValue<T> > chain;
	std::vector<TaggedValue<T> > pend;

	if (!sortedLarges.empty()) {
		std::vector<bool> used(larges.size(), false);

		std::size_t firstMatch = 0;
		while (firstMatch < larges.size()) {
			if (!used[firstMatch]
				&& !comp(larges[firstMatch], sortedLarges[0])
				&& !comp(sortedLarges[0], larges[firstMatch]))
				break;
			++firstMatch;
		}

		std::size_t firstPair = largePairIndices[firstMatch];
		used[firstMatch] = true;

		chain.push_back(TaggedValue<T>(smalls[firstPair - 1], firstPair));
		chain.push_back(TaggedValue<T>(sortedLarges[0], firstPair));

		for (std::size_t i = 1; i < sortedLarges.size(); ++i) {
			std::size_t match = 0;
			while (match < larges.size()) {
				if (!used[match]
					&& !comp(larges[match], sortedLarges[i])
					&& !comp(sortedLarges[i], larges[match]))
					break;
				++match;
			}

			std::size_t currentPair = largePairIndices[match];
			used[match] = true;

			chain.push_back(TaggedValue<T>(sortedLarges[i], currentPair));
			pend.push_back(TaggedValue<T>(smalls[currentPair - 1], currentPair));
		}
	}

	if (hasStraggler)
		pend.push_back(TaggedValue<T>(straggler, 0));

	std::size_t pendPairsCount = pend.size();
	if (hasStraggler)
		--pendPairsCount;

	std::vector<std::size_t> insertionOrder = PmergeMe::buildJacobsthalOrder(pendPairsCount);

	for (std::size_t i = 0; i < insertionOrder.size(); ++i) {
		const TaggedValue<T> &candidate = pend[insertionOrder[i]];

		std::size_t bound = find_pair_bound(chain, candidate.pairIndex);

		bounded_binary_insert(chain, candidate, bound, comp);
	}

	if (hasStraggler)
		bounded_binary_insert(chain, pend[pend.size() - 1], chain.size(), comp);

	std::vector<T> result;
	result.reserve(chain.size());
	for (std::size_t i = 0; i < chain.size(); ++i)
		result.push_back(chain[i].value);
	return result;
}


#endif //PMERGEME_HPP
