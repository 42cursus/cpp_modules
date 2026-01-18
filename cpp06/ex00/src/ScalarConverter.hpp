/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:43:03 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 21:43:13 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <limits>
#include "formatting.h"

class ScalarConverter {
public:
    static void convert(const std::string &str);

private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
};

#endif //SCALARCONVERTER_HPP
