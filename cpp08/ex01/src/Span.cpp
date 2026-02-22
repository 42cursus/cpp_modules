/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:57:21 by abelov            #+#    #+#             */
/*   Updated: 2026/02/22 17:47:10 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <algorithm>

/*
** -------------------------------- STATIC VARS -------------------------------
*/

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

Span::Span() : N(0)
{}
Span::Span(const unsigned int nbr) : N(nbr)
{}
Span::Span(const Span &other) : N(other.N), arr(other.arr)
{}

/*
** ------------------------------- DESTRUCTORS --------------------------------
*/

Span::~Span()
{}

/*
** -------------------------------- OPERATORS ---------------------------------
*/

Span &Span::operator=(const Span &other)
{
	if (this != &other) {
		N	= other.N;
		arr = other.arr;
	}
	return (*this);
}

/*
** -------------------------------- OVERLOADS ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void Span::addNumber(int nbr)
{
	if (arr.size() >= N) {
		const char *errMsg = "Span is already full. You can not add any more elements.";
		throw std::runtime_error(errMsg);
	}
	arr.push_back(nbr);
}

void Span::addNumber(std::vector<int> vec)
{
	if (arr.size() + vec.size() > N) {
		const char *errMsg = "Span can not add that many numbers. There is no enought space.";
		throw std::runtime_error(errMsg);
	}
	arr.insert(arr.end(), vec.begin(), vec.end());
}

int Span::shortestSpan() const
{
	if (arr.size() <= 1) {
		const char *errMsg = "There are less than 2 elements. Impossible to get shortest span.";
		throw std::runtime_error(errMsg);
	}
	int ret = abs(arr[0] - arr[1]);

	std::vector<int> tmp(arr);
	std::sort(tmp.begin(), tmp.end());
	for (unsigned long i = 1; i + 1 < tmp.size(); i++)
		ret = ::min(tmp[i + 1] - tmp[i], ret);
	return (ret);
}

int Span::longestSpan() const
{
	if (arr.size() <= 1) {
		const char *errMsg = "There are less than 2 elements. Impossible to get longest span.";
		throw std::invalid_argument(errMsg);
	}
	std::vector<int>::const_iterator itMax = std::max_element(arr.begin(), arr.end());
	std::vector<int>::const_iterator itMin = std::min_element(arr.begin(), arr.end());
	int								 nMax  = *itMax;
	int								 nMin  = *itMin;
	return (nMax - nMin);
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
