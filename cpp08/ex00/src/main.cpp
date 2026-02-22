/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:37:48 by abelov            #+#    #+#             */
/*   Updated: 2026/02/22 18:26:00 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::cout << "<--- Vector container --->" << std::endl;
	std::vector<int> vector;
	vector.push_back(5);
	vector.push_back(10);
	vector.push_back(15);
	vector.push_back(20);
	vector.push_back(25);
	vector.push_back(30);
	vector.push_back(35);

	try {
		easyfind(vector, 25);
		easyfind(vector, 50);
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "<--- List container --->" << std::endl;
	std::list<int> list;

	for (int i = 1; i < 42; ++i)
		list.push_back(i * 5);

	try {
		easyfind(list, 25);
		easyfind(list, 50);
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}
}
