/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:08:54 by abelov            #+#    #+#             */
/*   Updated: 2026/02/17 18:08:54 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>

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

template <typename T>
void	swap(T &lhs, T &rhs)
{
    T tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

#endif //WHATEVER_HPP
