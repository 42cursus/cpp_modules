/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:12:43 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 22:12:43 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstring>
#include <string>

template <typename T>
void iter(T* arr, size_t len, void (*apply)(T&))
{
	// std::cout << "Template with non-const reference called:\n";
	for (size_t i = 0; i < len; i++)
		apply(arr[i]);
}

template <typename T>
void iter(T* arr, size_t len, void (*apply)(const T&))
{
	// std::cout << "Template with const reference called:\n";
	for (size_t i = 0; i < len; i++)
		apply(arr[i]);
}


#endif //ITER_HPP
