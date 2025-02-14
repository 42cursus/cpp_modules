/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 23:38:00 by abelov            #+#    #+#             */
/*   Updated: 2025/02/13 23:38:01 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

/**
 * https://en.cppreference.com/w/cpp/string/byte/toupper
 * 	Like all other functions from <cctype>, the behavior of std::toupper is
 * 	undefined if the argument's value is neither representable as unsigned char
 * 	nor equal to EOF.
 * 	To use these functions safely with plain chars (or signed chars),
 * 	the argument should first be converted to unsigned char.
 *
 * @param str
 * @return pointer to a modified string
 */
char	*toUpper(char *str)
{
	for (int i = 0; str[i]; i++)
		str[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(str[i])));
	return (str);
}

int	main(int argc, char **argv) {

	std::string theString("* LOUD AND UNBEARABLE FEEDBACK NOISE *");

	if (argc == 1)
		std::cout << theString << std::endl;
	else {
		for (int i = 1; i < argc; i++)
			std::cout << toUpper(argv[i]);
		std::cout << std::endl;
	}
}
