/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:32:52 by abelov            #+#    #+#             */
/*   Updated: 2026/03/13 21:35:17 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <cerrno>
#include <climits>
#include <ctime>
#include <stdexcept>

std::vector<std::size_t> PmergeMe::_mergeInsertStage(const std::vector<int>			&data,
													 const SplitStage				&split,
													 const std::vector<std::size_t> &sortedLarges)
{
	std::vector<TaggedIndex> chain;
	std::vector<TaggedIndex> pend;

	if (!sortedLarges.empty()) {
		const PairInfo &firstPair = _findPairByLarge(split.pairs, sortedLarges[0]);
		chain.push_back(firstPair.smallTag());
		chain.push_back(firstPair.largeTag());

		for (std::size_t i = 1; i < sortedLarges.size(); ++i) {
			const PairInfo &currentPair = _findPairByLarge(split.pairs, sortedLarges[i]);
			chain.push_back(currentPair.largeTag());
			pend.push_back(currentPair.smallTag());
		}
	}

	if (split.hasStraggler)
		pend.push_back(TaggedIndex(split.stragglerIndex, 0));

	std::size_t pendPairCount = pend.size();
	if (split.hasStraggler)
		--pendPairCount;

	const std::vector<std::size_t> jacobsthalSequence = buildJacobsthalOrder(pendPairCount);
	for (std::size_t i = 0; i < jacobsthalSequence.size(); ++i) {
		size_t jnbr = jacobsthalSequence[i];
		const TaggedIndex &candidate = pend[jnbr];
		const std::size_t bound = _findPairBound(chain, candidate.pairId());
		_boundedBinaryInsert(chain, candidate, bound, data);
	}

	if (split.hasStraggler)
		_boundedBinaryInsert(chain, pend[pend.size() - 1], chain.size(), data);

	std::vector<std::size_t> result;
	result.reserve(chain.size());
	for (std::size_t i = 0; i < chain.size(); ++i)
		result.push_back(chain[i].dataIndex());
	return result;
}

std::vector<std::size_t> PmergeMe::_mergeInsertStage(
	const std::vector<std::list<int>::const_iterator> &dataRefs,
	const SplitStage								  &split,
	const std::vector<std::size_t>					  &sortedLarges)
{
	std::vector<TaggedIndex> chain;
	std::vector<TaggedIndex> pend;

	if (!sortedLarges.empty()) {
		const PairInfo &firstPair = _findPairByLarge(split.pairs, sortedLarges[0]);
		chain.push_back(firstPair.smallTag());
		chain.push_back(firstPair.largeTag());

		for (std::size_t i = 1; i < sortedLarges.size(); ++i) {
			const PairInfo &currentPair = _findPairByLarge(split.pairs, sortedLarges[i]);
			chain.push_back(currentPair.largeTag());
			pend.push_back(currentPair.smallTag());
		}
	}

	if (split.hasStraggler)
		pend.push_back(TaggedIndex(split.stragglerIndex, 0));

	std::size_t pendPairCount = pend.size();
	if (split.hasStraggler)
		--pendPairCount;

	const std::vector<std::size_t> insertionOrder = buildJacobsthalOrder(pendPairCount);
	for (std::size_t i = 0; i < insertionOrder.size(); ++i) {
		const TaggedIndex &candidate = pend[insertionOrder[i]];
		const std::size_t  bound	 = _findPairBound(chain, candidate.pairId());
		_boundedBinaryInsert(chain, candidate, bound, dataRefs);
	}

	if (split.hasStraggler)
		_boundedBinaryInsert(chain, pend[pend.size() - 1], chain.size(), dataRefs);

	std::vector<std::size_t> result;
	result.reserve(chain.size());
	for (std::size_t i = 0; i < chain.size(); ++i)
		result.push_back(chain[i].dataIndex());
	return result;
}

PmergeMe::SplitStage PmergeMe::_splitStage(const std::vector<int>		  &data,
										   const std::vector<std::size_t> &ord)
{
	SplitStage stage	 = {};
	stage.hasStraggler	 = false;
	stage.stragglerIndex = 0;

	std::vector<PairInfo>	 &pairs	 = stage.pairs;
	std::vector<std::size_t> &larges = stage.larges;

	for (std::size_t i = 0; i + 1 < ord.size(); i += 2) {
		std::size_t left   = ord[i];
		std::size_t right  = ord[i + 1];
		std::size_t pairId = pairs.size() + 1;
		if (data[right] < data[left])
			std::swap(left, right);
		pairs.push_back(PairInfo(left, right, pairId));
		larges.push_back(right);
	}

	if (ord.size() % 2 != 0) {
		stage.hasStraggler	 = true;
		stage.stragglerIndex = ord[ord.size() - 1];
	}
	return stage;
}

PmergeMe::SplitStage PmergeMe::_splitStage(
	const std::vector<std::list<int>::const_iterator> &dataRefs,
	const std::vector<std::size_t>					   &ord)
{
	SplitStage stage	 = {};
	stage.hasStraggler	 = false;
	stage.stragglerIndex = 0;

	std::vector<PairInfo>	 &pairs	 = stage.pairs;
	std::vector<std::size_t> &larges = stage.larges;

	for (std::size_t i = 0; i + 1 < ord.size(); i += 2) {
		std::size_t left   = ord[i];
		std::size_t right  = ord[i + 1];
		std::size_t pairId = pairs.size() + 1;
		if (*dataRefs[right] < *dataRefs[left])
			std::swap(left, right);
		pairs.push_back(PairInfo(left, right, pairId));
		larges.push_back(right);
	}

	if (ord.size() % 2 != 0) {
		stage.hasStraggler	 = true;
		stage.stragglerIndex = ord[ord.size() - 1];
	}
	return stage;
}

bool PmergeMe::_parsePositiveInt(const char *raw, int &out)
{
	char *end  = 0;
	errno	   = 0;
	long value = std::strtol(raw, &end, 10);

	if (raw[0] == '\0' || *end != '\0' || errno == ERANGE || value < 0 || value > INT_MAX)
		return false;
	out = static_cast<int>(value);
	return true;
}

bool PmergeMe::parseInput(int argc, char *argv[], std::vector<int> &data)
{
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

void PmergeMe::printValues(const std::list<int> &values)
{
	for (std::list<int>::const_iterator it = values.begin(); it != values.end(); ++it) {
		if (it != values.begin())
			std::cout << " ";
		std::cout << *it;
	}
	std::cout << std::endl; // NOLINT(performance-avoid-endl)
}

const PmergeMe::PairInfo &PmergeMe::_findPairByLarge(const std::vector<PmergeMe::PairInfo> &pairs,
													 size_t largeIndex)
{
	for (std::size_t i = 0; i < pairs.size(); ++i) {
		const PairInfo &pair = pairs[i];
		if (pair.largeIndex == largeIndex)
			return pair;
	}
	throw std::logic_error("Pair not found for large index");
}

std::size_t PmergeMe::_findPairBound(const std::vector<PmergeMe::TaggedIndex> &chain,
									 std::size_t							   pairId)
{
	for (std::size_t i = 0; i < chain.size(); ++i) {
		if (chain[i].pairId() == pairId)
			return i;
	}
	return chain.size();
}

void PmergeMe::_boundedBinaryInsert(std::vector<TaggedIndex> &chain,
									const TaggedIndex		 &candidate,
									std::size_t				  upperBound,
									const std::vector<int>	 &data)
{
	std::size_t left  = 0;
	std::size_t right = upperBound;

	while (left < right) {

		const std::size_t mid = left + ((right - left) / 2);

		int middleNumber	= data[chain[mid].dataIndex()];
		int candidateNumber = data[candidate.dataIndex()];

		if (middleNumber < candidateNumber)
			left = mid + 1;
		else
			right = mid;
	}
	chain.insert(chain.begin() + left, candidate);
}

void PmergeMe::_boundedBinaryInsert(std::vector<TaggedIndex>							 &chain,
									const TaggedIndex									 &candidate,
									std::size_t											  upperBound,
									const std::vector<std::list<int>::const_iterator> &dataRefs)
{
	std::size_t left  = 0;
	std::size_t right = upperBound;

	while (left < right) {
		const std::size_t mid = left + ((right - left) / 2);
		if (*dataRefs[chain[mid].dataIndex()] < *dataRefs[candidate.dataIndex()])
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

	std::size_t inserted  = 1;
	std::size_t prevJacob = 1;
	std::size_t currJacob = 3;

	while (inserted < count) {
		std::size_t limit = currJacob;
		limit			  = std::min(limit, count);

		for (std::size_t i = limit; i > inserted; --i)
			order.push_back(i - 1);

		inserted					= limit;
		const std::size_t nextJacob = currJacob + 2 * prevJacob;
		prevJacob					= currJacob;
		currJacob					= nextJacob;
	}
	return order;
}

std::vector<std::size_t> PmergeMe::fordJohnsonPermutation(const std::vector<int>		 &data,
														  const std::vector<std::size_t> &ord)
{
	if (ord.size() <= 1)
		return ord;

	const SplitStage			   split		= _splitStage(data, ord);
	const std::vector<std::size_t> sortedLarges = fordJohnsonPermutation(data, split.larges);
	return _mergeInsertStage(data, split, sortedLarges);
}

std::vector<std::size_t> PmergeMe::fordJohnsonPermutation(
	const std::vector<std::list<int>::const_iterator> &dataRefs,
	const std::vector<std::size_t>					   &ord)
{
	if (ord.size() <= 1)
		return ord;

	const SplitStage			   split		= _splitStage(dataRefs, ord);
	const std::vector<std::size_t> sortedLarges = fordJohnsonPermutation(dataRefs, split.larges);
	return _mergeInsertStage(dataRefs, split, sortedLarges);
}

std::vector<int> PmergeMe::fordJohnsonSort(const std::vector<int> &data)
{
	std::vector<int>		 result;
	std::vector<std::size_t> ord(data.size());
	for (std::size_t i = 0; i < ord.size(); ++i)
		ord[i] = i;

	const std::vector<std::size_t> sortedOrd = fordJohnsonPermutation(data, ord);

	result.reserve(sortedOrd.size());
	for (std::size_t i = 0; i < sortedOrd.size(); ++i)
		result.push_back(data[sortedOrd[i]]);
	return result;
}

std::list<int> PmergeMe::fordJohnsonSort(const std::list<int> &data)
{
	std::vector<std::list<int>::const_iterator> dataRefs;
	dataRefs.reserve(data.size());

	for (std::list<int>::const_iterator it = data.begin(); it != data.end(); ++it)
		dataRefs.push_back(it);

	std::vector<std::size_t> ord(dataRefs.size());
	for (std::size_t i = 0; i < ord.size(); ++i)
		ord[i] = i;

	const std::vector<std::size_t> sortedOrd = fordJohnsonPermutation(dataRefs, ord);

	std::list<int> result;
	for (std::size_t i = 0; i < sortedOrd.size(); ++i)
		result.push_back(*dataRefs[sortedOrd[i]]);
	return result;
}

PmergeMe::TaggedIndex::TaggedIndex() : _dataIndex(), _pairId()
{}

PmergeMe::TaggedIndex::TaggedIndex(std::size_t dataIndex, std::size_t pairId) :
	_dataIndex(dataIndex),
	_pairId(pairId)
{}

size_t PmergeMe::TaggedIndex::pairId() const
{
	return _pairId;
}

size_t PmergeMe::TaggedIndex::dataIndex() const
{
	return _dataIndex;
}

PmergeMe::PairInfo::PairInfo(size_t smallIndexValue, size_t largeIndexValue, size_t pairIdValue) :
	smallIndex(smallIndexValue),
	largeIndex(largeIndexValue),
	pairId(pairIdValue)
{}

PmergeMe::TaggedIndex PmergeMe::PairInfo::smallTag() const
{
	return TaggedIndex(smallIndex, pairId);
}

PmergeMe::TaggedIndex PmergeMe::PairInfo::largeTag() const
{
	return TaggedIndex(largeIndex, pairId);
}

double PmergeMe::elapsedTime(std::clock_t start, std::clock_t end)
{
	return static_cast<double>(end - start) * 1000000.0 / static_cast<double>(CLOCKS_PER_SEC);
}