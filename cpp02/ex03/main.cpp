/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:04:53 by abelov            #+#    #+#             */
/*   Updated: 2025/02/26 00:04:53 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

struct Input
{
	float triangle[3][2];
	const Point &testPoint;
	bool expected;
};

void check(bool succes)
{
	std::cout
		<< (succes ? "> " FT_GREEN".OK " FT_RESET : "> " FT_RED".KO " FT_RESET)
	<< std::endl;
}

int ftDoTest(Input &input)
{
	int result;
	int check_val;

	result = bsp(Point(input.triangle[0]), Point(input.triangle[1]),
				 Point(input.triangle[2]), input.testPoint);

	check_val = result == input.expected;
	if (!check_val)
		std::cout << "got \"" << (result ? "inside" : "outside")
				  << "\" whilst \"" << (input.expected ? "inside" : "outside")
				  << "\" was to be expected" << std::endl;
	check(check_val);
	return (0);
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-loop-convert"

int main()
{
	Input inputs[] = {
		{
			.triangle = {
				{1, 0},
				{3, 0},
				{2, 2}
			},
			.testPoint = Point(2, 1),
			.expected = true
		},
		{
			.triangle = {
				{1, 0},
				{1, 0},
				{2, 2}
			},
			.testPoint = Point(2, 1),
			.expected = false
		},
		{
			.triangle = {
				{1, 0},
				{2, 1},
				{2, 2}},
			.testPoint = Point(2.5f, 1.5f),
			.expected = false
		},
		{
			.triangle = {
				{1, 0},
				{2, 1},
				{2, 2}},
			.testPoint = Point(2, 1.001f),
			.expected = false
		},
		{
			.triangle = {
				{1, 0},
				{2, 1},
				{2, 2}
			},
			.testPoint = Point(2, 1.005f),
			.expected = true
		},
		{
			.triangle = {
				{0, 0},
				{10, 30},
				{20, 0}
			},
			.testPoint = Point(10, 15),
			.expected = true
		},
		{
			.triangle = {
				{0, 0},
				{10, 30},
				{20, 0}
			},
			.testPoint = Point(30, 15),
			.expected = false
		},
		{
			.triangle = {
				{0, 0},
				{10, 30},
				{20, 0}
			},
			.testPoint = Point(10, 30),
			.expected = false
		},
		{
			.triangle = {
				{0, 0},
				{10, 30},
				{20, 0}
			},
			.testPoint = Point(10, 0),
			.expected = true
		},
		{
			.triangle = {
				{0, 0},
				{10, 30},
				{20, 0}
			},
			.testPoint = Point(15, 10),
			.expected = true
		},
		{
			.triangle = {
				{0, 0},
				{10, 30},
				{20, 0}
			},
			.testPoint = Point(10, 10),
			.expected = true
		},
		{
			.triangle = {
				{4.65, 3.33},
				{12.42, 3.33},
				{6.69, 11.13}
			},
			.testPoint = Point(6.25, 6.43),
			.expected = true
		},
		{
			.triangle = {
				{4.65, 3.33},
				{12.42, 3.33},
				{6.69, 11.13}
			},
			.testPoint = Point(12.21, 9.99),
			.expected = false
		},
		{
			.triangle = {
				{4.65, 3.33},
				{12.42, 3.33},
				{6.69, 11.13}
			},
			.testPoint = Point(6.69, 11.13),
			.expected = false
		},
		{
			.triangle = {
				{4.65, 3.33},
				{12.42, 3.33},
				{6.69, 11.13}
			},
			.testPoint = Point(7.42, 3.33),
			.expected = true
		},
		{
			.triangle = {
				{4.65, 3.33},
				{12.42, 3.33},
				{6.69, 11.13}
			},
			.testPoint = Point(7.33, 8.88),
			.expected = true
		},
		{
			.triangle = {
				{4.65, 3.33},
				{12.42, 3.33},
				{6.69, 11.13}
			},
			.testPoint = Point(7.92, 5.93),
			.expected = true
		},
	};

	for (int i = 0; i < (sizeof(inputs) / sizeof(inputs[0])); i++)
		ftDoTest(inputs[i]);
	return (0);
}

#pragma clang diagnostic pop
