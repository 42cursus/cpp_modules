/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:20:20 by abelov            #+#    #+#             */
/*   Updated: 2025/02/24 13:20:20 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sysexits.h>
#include "Harl.hpp"


int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: harlFilter LOGLEVEL" << std::endl;
		std::cout << " where LOGLEVEL is one of \"DEBUG\" \"INFO\" \"WARNING\""
					 " \"ERROR\"" << std::endl;
		return (EX_USAGE);
	}

	Harl harl;
	harl.harlFilter(argv[1]);
	return (EX_OK);
}
