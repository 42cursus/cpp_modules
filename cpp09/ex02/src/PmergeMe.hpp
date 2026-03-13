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
#include <cstdlib>

class PmergeMe {
	static bool				   _parsePositiveInt(const char *raw, int &out);
public:
	struct PairInfo {
		std::size_t smallIndex;
		std::size_t largeIndex;
		std::size_t pairId;
	};

	struct TaggedIndex {
		std::size_t dataIndex;
		std::size_t pairId;
	};
	static std::vector<std::size_t> buildJacobsthalOrder(std::size_t count);
	static std::vector<int>			fordJohnsonSort(const std::vector<int> &data);
	static std::vector<std::size_t> fordJohnsonPermutation(const std::vector<int>		  &data,
														   const std::vector<std::size_t> &ord);
	static void						boundedBinaryInsert(std::vector<TaggedIndex> &chain,
														const TaggedIndex		 &candidate,
														size_t					  upperBound,
														const std::vector<int>	 &data);
	static size_t findPairBound(const std::vector<PmergeMe::TaggedIndex> &chain, size_t pairId);
	static const PairInfo *findPairByLarge(const std::vector<PmergeMe::PairInfo> &pairs,
										   size_t								  largeIndex);
	static bool				   parseInput(int argc, char **argv, std::vector<int> &data);
	static void				   printValues(const std::vector<int> &values);
};

#endif //PMERGEME_HPP
