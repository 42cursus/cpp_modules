/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:56:46 by abelov            #+#    #+#             */
/*   Updated: 2025/02/24 12:56:47 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sysexits.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Replace.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " " << "[1] filename - ";
		std::cerr << "[2] str_to_replace - [3] substitution" << std::endl;
		return (EXIT_FAILURE);
	}

	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string filename = argv[1];

	std::ifstream inFile(filename.c_str()); // open file
	if (!inFile.is_open())
	{
		std::cerr <<"The file cannot be opened\n";
		return (1);
	}

	std::ofstream outFile((filename + ".replace").c_str()); // create new file
	if (!outFile.is_open())
	{
		std::cerr << "The file cannot be opened\n";
		return (1);
	}
	std::string line;
	while (std::getline(inFile, line))
	{
		line = Replace::strReplace(line, s1, s2);
		outFile << line << "\n";
	}

	inFile.close();
	outFile.close();

	return (EX_OK);
}
