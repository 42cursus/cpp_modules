/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:32:45 by abelov            #+#    #+#             */
/*   Updated: 2026/03/13 21:35:19 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

class PmergeMe {
public:
	struct TaggedIndex;

	struct PairInfo {
		PairInfo(size_t smallIndexValue, size_t largeIndexValue, size_t pairIdValue);
		TaggedIndex smallTag() const;
		TaggedIndex largeTag() const;
		std::size_t smallIndex;
		std::size_t largeIndex;
		std::size_t pairId;
	};

	struct SplitStage {
		std::vector<PairInfo>	 pairs;
		std::vector<std::size_t> larges;
		bool					 hasStraggler;
		std::size_t				 stragglerIndex;
	};

	struct TaggedIndex {
	private:
		std::size_t _dataIndex;
		std::size_t _pairId;

	public:
		TaggedIndex();
		TaggedIndex(std::size_t dataIndex, std::size_t pairId);
		size_t pairId() const;
		size_t dataIndex() const;
	};
	static std::vector<std::size_t> buildJacobsthalOrder(std::size_t count);
	static std::vector<int>			fordJohnsonSort(const std::vector<int> &data);
	static std::list<int>			fordJohnsonSort(const std::list<int> &data);
	static std::vector<std::size_t> fordJohnsonPermutation(const std::vector<int>		  &data,
														   const std::vector<std::size_t> &ord);
	static bool						parseInput(int argc, char **argv, std::vector<int> &data);
	static void						printValues(const std::vector<int> &values);
	static void						printValues(const std::list<int> &values);
	static double					elapsedTime(clock_t start, clock_t end);
private:
	static size_t _findPairBound(const std::vector<TaggedIndex> &chain, std::size_t pairId);
	static const PairInfo &_findPairByLarge(const std::vector<PairInfo> &pairs, size_t largeIndex);
	static bool			   _parsePositiveInt(const char *raw, int &out);
	static SplitStage	   _splitStage(const std::vector<int>		  &data,
									   const std::vector<std::size_t> &ord);
	static SplitStage _splitStage(const std::vector<std::list<int>::const_iterator> &dataRefs,
								  const std::vector<std::size_t>					   &ord);
	static void			   _boundedBinaryInsert(std::vector<TaggedIndex> &chain,
												const TaggedIndex		 &candidate,
												std::size_t				  upperBound,
												const std::vector<int>	 &data);
	static void _boundedBinaryInsert(std::vector<TaggedIndex>							 &chain,
									 const TaggedIndex									 &candidate,
									 std::size_t										  upperBound,
									 const std::vector<std::list<int>::const_iterator> &dataRefs);
	static std::vector<std::size_t> _mergeInsertStage(const std::vector<int>		 &data,
													  const SplitStage				 &split,
													  const std::vector<std::size_t> &sortedLarges);
	static std::vector<std::size_t> _mergeInsertStage(
		const std::vector<std::list<int>::const_iterator> &dataRefs,
		const SplitStage								  &split,
		const std::vector<std::size_t>					  &sortedLarges);
	static std::vector<std::size_t> fordJohnsonPermutation(
		const std::vector<std::list<int>::const_iterator> &dataRefs,
		const std::vector<std::size_t>					  &ord);

};

#endif //PMERGEME_HPP
