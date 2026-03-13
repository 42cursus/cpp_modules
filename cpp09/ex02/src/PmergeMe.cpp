/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:32:52 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 23:32:53 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <cerrno>
#include <climits>

namespace {



} // namespace


bool PmergeMe::_parsePositiveInt(const char *raw, int &out)
{
	char *end = 0;
	errno = 0;
	long value = std::strtol(raw, &end, 10);

	if (raw[0] == '\0' || *end != '\0' || errno == ERANGE || value <= 0 || value > INT_MAX)
		return false;
	out = static_cast<int>(value);
	return true;
}

bool PmergeMe::parseInput(int argc, char *argv[], std::vector<int> &data)
{
	if (argc < 2)
		return false;

	for (int i = 1; i < argc; ++i) {
		int value = 0;
		if (!_parsePositiveInt(argv[i], value))
			return false;
		data.push_back(value);
	}
	return true;
}

void PmergeMe::printValues(const std::vector<int> &values)
{
	for (std::size_t i = 0; i < values.size(); ++i) {
		std::cout << values[i];
		if (i + 1 != values.size())
			std::cout << " ";
	}
	std::cout << std::endl; // NOLINT(performance-avoid-endl)
}

const PmergeMe::PairInfo *PmergeMe::findPairByLarge(
	const std::vector<PmergeMe::PairInfo> &pairs,
	std::size_t largeIndex)
{
	for (std::size_t i = 0; i < pairs.size(); ++i) {
		if (pairs[i].largeIndex == largeIndex)
			return &pairs[i];
	}
	return 0;
}

std::size_t PmergeMe::findPairBound(
	const std::vector<PmergeMe::TaggedIndex> &chain,
	std::size_t pairId)
{
	for (std::size_t i = 0; i < chain.size(); ++i) {
		if (chain[i].pairId == pairId)
			return i;
	}
	return chain.size();
}

void PmergeMe::boundedBinaryInsert(
	std::vector<TaggedIndex> &chain,
	const TaggedIndex &candidate,
	std::size_t upperBound,
	const std::vector<int> &data)
{
	std::size_t left = 0;
	std::size_t right = upperBound;

	while (left < right) {
		const std::size_t mid = left + ((right - left) / 2);
		if (data[chain[mid].dataIndex] < data[candidate.dataIndex])
			left = mid + 1;
		else
			right = mid;
	}
	chain.insert(chain.begin() + left, candidate);
}

std::vector<std::size_t> PmergeMe::buildJacobsthalOrder(std::size_t count)
{
	std::vector<std::size_t> order;

	if (count == 0)
		return order;

	order.push_back(0);
	if (count == 1)
		return order;

	std::size_t inserted = 1;
	std::size_t prevJacob = 1;
	std::size_t currJacob = 3;

	while (inserted < count) {
		std::size_t limit = currJacob;
		limit = std::min(limit, count);

		std::size_t i = limit;
		while (i > inserted) {
			order.push_back(i - 1);
			--i;
		}

		inserted = limit;
		const std::size_t nextJacob = currJacob + 2 * prevJacob;
		prevJacob = currJacob;
		currJacob = nextJacob;
	}
	return order;
}

std::vector<std::size_t> PmergeMe::fordJohnsonPermutation(
	const std::vector<int> &data,
	const std::vector<std::size_t> &ord)
{
	if (ord.size() <= 1)
		return ord;

	std::vector<PairInfo> pairs;
	std::vector<std::size_t> larges;
	bool hasStraggler = false;
	std::size_t stragglerIndex = 0;

	for (std::size_t i = 0; i + 1 < ord.size(); i += 2) {
		std::size_t left = ord[i];
		std::size_t right = ord[i + 1];
		if (data[right] < data[left])
			std::swap(left, right);

		PairInfo pair = {};
		pair.smallIndex = left;
		pair.largeIndex = right;
		pair.pairId = pairs.size() + 1;
		pairs.push_back(pair);
		larges.push_back(right);
	}

	if (ord.size() % 2 != 0) {
		hasStraggler = true;
		stragglerIndex = ord[ord.size() - 1];
	}

	std::vector<std::size_t> sortedLarges = fordJohnsonPermutation(data, larges);

	std::vector<TaggedIndex> chain;
	std::vector<TaggedIndex> pend;

	if (!sortedLarges.empty()) {
		const PairInfo *firstPair = findPairByLarge(pairs, sortedLarges[0]);
		chain.push_back(TaggedIndex());
		chain.back().dataIndex = firstPair->smallIndex;
		chain.back().pairId = firstPair->pairId;
		chain.push_back(TaggedIndex());
		chain.back().dataIndex = firstPair->largeIndex;
		chain.back().pairId = firstPair->pairId;

		for (std::size_t i = 1; i < sortedLarges.size(); ++i) {
			const PairInfo *currentPair = findPairByLarge(pairs, sortedLarges[i]);

			chain.push_back(TaggedIndex());
			chain.back().dataIndex = currentPair->largeIndex;
			chain.back().pairId = currentPair->pairId;

			pend.push_back(TaggedIndex());
			pend.back().dataIndex = currentPair->smallIndex;
			pend.back().pairId = currentPair->pairId;
		}
	}

	if (hasStraggler) {
		pend.push_back(TaggedIndex());
		pend.back().dataIndex = stragglerIndex;
		pend.back().pairId = 0;
	}

	std::size_t pendPairCount = pend.size();
	if (hasStraggler)
		--pendPairCount;

	const std::vector<std::size_t> insertionOrder = PmergeMe::buildJacobsthalOrder(pendPairCount);
	for (std::size_t i = 0; i < insertionOrder.size(); ++i) {
		const TaggedIndex candidate = pend[insertionOrder[i]];
		const std::size_t bound = findPairBound(chain, candidate.pairId);
		boundedBinaryInsert(chain, candidate, bound, data);
	}

	if (hasStraggler)
		boundedBinaryInsert(chain, pend[pend.size() - 1], chain.size(), data);

	std::vector<std::size_t> result;
	result.reserve(chain.size());
	for (std::size_t i = 0; i < chain.size(); ++i)
		result.push_back(chain[i].dataIndex);
	return result;
}

std::vector<int> PmergeMe::fordJohnsonSort(const std::vector<int> &data)
{
	std::vector<std::size_t> ord(data.size());
	for (std::size_t i = 0; i < ord.size(); ++i)
		ord[i] = i;

	const std::vector<std::size_t> sortedOrd = fordJohnsonPermutation(data, ord);
	std::vector<int> result;
	result.reserve(sortedOrd.size());
	for (std::size_t i = 0; i < sortedOrd.size(); ++i)
		result.push_back(data[sortedOrd[i]]);
	return result;
}
