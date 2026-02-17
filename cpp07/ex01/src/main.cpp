/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:08:44 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 22:08:45 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void intIncreaseAndPrint(int &nbr)
{
	std::cout << "number = " << nbr++ << ";";
	std::cout << "increased number = " << nbr << std::endl;
}

void intPrint(const int &n)
{
	std::cout << "number = " << n << std::endl;
}

void charToUpperAndPrint(char &chr)
{
	chr = static_cast<char>(std::toupper(chr));
	std::cout << chr;
}

int main()
{
	int		  arr[] = {0, 1, 2, 3, 4, 5};
	int const len	= 6;

	iter(&arr[0], len, intPrint);
	iter(&arr[0], len, intIncreaseAndPrint);

	char	  arr2[] = {"Nice to see you!"};
	int const len2	 = static_cast<int>(std::strlen(&arr2[0]));

	iter(&arr2[0], len2, charToUpperAndPrint);

	std::cout << "\n";
}
