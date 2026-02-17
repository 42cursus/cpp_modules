/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:09:00 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 22:09:00 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

enum { MAX_VAL = 750 };

void printIntArray(Array<int> arr)
{
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i];
		if (i != arr.size() - 1)
			std::cout << " - ";
	}
	std::cout << std::endl;
}

int main2()
{
	Array<int> numbers(MAX_VAL);

	int *mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++) {
		const int value = rand();
		numbers[i]		= value;
		mirror[i]		= value;
	}

	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i]) {
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try {
		numbers[-2] = 0;
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}
	try {
		numbers[MAX_VAL] = 0;
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++) {
		numbers[i] = rand();
	}
	delete[] mirror; //
	return 0;
}

int main()
{
	std::cout << FT_BLUE << "Instantiate an array of 7 elements:\n" << FT_RST;
	Array<int> arr(7);
	/*set int values from 0 to 6 and print them*/
	for (int i = 0; i < arr.size(); i++)
		arr[i] = i;
	printIntArray(arr);

	std::cout << FT_YELLOW << "Testing size function:\n" << FT_RST;
	std::cout << "Size is " << arr.size() << std::endl;

	std::cout << FT_YELLOW << "Testing operator[]:\n" << FT_RST;
	try {
		std::cout << "Output value arr[3] through operator[]: " << arr[3] << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << FT_YELLOW << "Testing operator[] with the index out of bounds:\n" << FT_RST;
	try {
		std::cout << "Output value arr[10] through operator[]: " << arr[10] << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << FT_BLUE << "Create Array2 with copy construtor:\n" << FT_RST;
	Array<int> arr2(arr);
	/*let's check values by outputting them*/
	printIntArray(arr2);

	std::cout << FT_BLUE << "Create Array3:\n" << FT_RST;
	Array<int> arr3(3);
	printIntArray(arr3);
	std::cout << FT_YELLOW << "Operator= usage:\n" << FT_RST;
	arr3 = arr2;
	printIntArray(arr3);
	return main2();
}
