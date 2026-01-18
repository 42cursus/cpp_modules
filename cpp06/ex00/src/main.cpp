/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:37:51 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 21:37:52 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        std::cerr << "Usage: ./convert <value>" << std::endl;
        return (1);
    }

    ScalarConverter::convert(argv[1]); // NOLINT(*-pro-bounds-pointer-arithmetic)

    return (0);
}
