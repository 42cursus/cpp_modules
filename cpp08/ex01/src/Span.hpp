/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:57:17 by abelov            #+#    #+#             */
/*   Updated: 2026/02/22 17:47:06 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <vector>

class Span {
public:
	Span();
	Span(unsigned int nbr);
	~Span();
	Span(const Span &other);
	Span &operator=(const Span &other);

	void addNumber(int nbr);
	void addNumber(std::vector<int> vec);
	int	 shortestSpan() const;
	int	 longestSpan() const;

private:
	unsigned int	 N;
	std::vector<int> arr;
};


template <typename T>
T const & max(T const &lhs, T const &rhs)
{
	return lhs >= rhs ? lhs : rhs;
}

template <typename T>
T const & min(T const &lhs, T const &rhs)
{
	return lhs <= rhs ? lhs : rhs;
}

#endif //SPAN_HPP
