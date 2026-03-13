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
#include <iostream>
#include <vector>

/*
** -------------------------------- STATIC VARS -------------------------------
*/

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

/*
** ------------------------------- DESTRUCTORS --------------------------------
*/


/*
** -------------------------------- OPERATORS ---------------------------------
*/

/*
** -------------------------------- OVERLOADS ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

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
		std::size_t nextJacob = currJacob + 2 * prevJacob;
		prevJacob = currJacob;
		currJacob = nextJacob;
	}

	return order;
}

/*
** -------------------------------- ACCESSORS ---------------------------------
*/

/*
** -------------------------------- EXCEPTIONS --------------------------------
*/

/*
** -------------------------------- MISCELLANEOUS --------------------------------
*/

std::size_t PmergeMe::IndexGenerator::operator()()
{
	return current++;
}

