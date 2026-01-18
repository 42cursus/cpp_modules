/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:43:08 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 21:43:09 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*
** ------------------------ STATIC VARS AND DECLARATIONS ----------------------
*/

namespace {

    enum DataType {
        TYPE_CHAR,
        TYPE_INT,
        TYPE_FLOAT,
        TYPE_DOUBLE,
        TYPE_SPECIAL,
        TYPE_INVALID
    };

    bool isSpecial(const std::string &str);
    bool isCharLiteral(const std::string &str);
    bool isSingleNonDigitChar(const std::string &str);
    bool isInt(const std::string &str);
    bool scanFloatingCore(const std::string &str, std::size_t end, bool &seenDot, bool &seenDigit);
    bool isDouble(const std::string &str);
    bool isFloat(const std::string &str);
    DataType detectDataType(const std::string &str);
    template <typename T>
    void printConversion(DataType type, T num);
    int stringToInt(const std::string &str);
    std::string removeChar(const std::string &str);
    float stringToFloat(const std::string &str);
    double stringToDouble(const std::string &str);
    void convertToChar(const std::string &str);
    void convertToInt(const std::string &str);
    void convertToFloat(const std::string &str);
    void convertToDouble(const std::string &str);
    void specialCase(const std::string &str);

}// namespace

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

ScalarConverter::ScalarConverter() {}

/*
** ------------------------------- DESTRUCTORS --------------------------------
*/

ScalarConverter::~ScalarConverter() {}

/*
** -------------------------------- OPERATORS ---------------------------------
*/

/*
** -------------------------------- OVERLOADS ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void ScalarConverter::convert(const std::string &str) {
    DataType type = detectDataType(str);

    switch (type) {
        case TYPE_CHAR:
            convertToChar(str);
            return;
        case TYPE_INT:
            convertToInt(str);
            return;
        case TYPE_FLOAT:
            convertToFloat(str);
            return;
        case TYPE_DOUBLE:
            convertToDouble(str);
            return;
        case TYPE_SPECIAL:
            specialCase(str);
            return;
        default:
            std::cerr << "Error: invalid data input" << std::endl;
    }
}

/*
** -------------------------------- ACCESSORS ---------------------------------
*/

/*
** -------------------------------- EXCEPTIONS --------------------------------
*/



/*
** -------------------------------- MISCELLANEOUS --------------------------------
*/

namespace {

//******************************************************************************************/
//                            TYPE DETECTION FUNCTIONS
//******************************************************************************************/

    bool isSpecial(const std::string &str) {
        return str == "nan" || str == "nanf" ||
               str == "inf" || str == "inff" ||
               str == "+inf" || str == "-inf" ||
               str == "+inff" || str == "-inff";
    }

    bool isCharLiteral(const std::string &str) {
        return str.size() == 3 && str[0] == '\'' && str[2] == '\'';
    }

    bool isSingleNonDigitChar(const std::string &str) {
        return str.size() == 1 &&
               (std::isdigit(static_cast<unsigned char>(str[0])) == 0);
    }

    bool isInt(const std::string &str) {
        std::size_t iter = 0;

        if (str.empty())
            return false;
        if (str[iter] == '+' || str[iter] == '-')
            iter++;
        if (iter == str.size())
            return false;

        while (iter < str.size()) {
            if (std::isdigit(static_cast<unsigned char>(str[iter])) == 0)
                return false;
            iter++;
        }
        return true;
    }

    bool scanFloatingCore(const std::string &str,
                          std::size_t end,
                          bool &seenDot,
                          bool &seenDigit) {
        std::size_t iter = 0;

        seenDot = false;
        seenDigit = false;

        if (iter < end && (str[iter] == '+' || str[iter] == '-'))
            iter++;

        if (iter == end)
            return false;

        while (iter < end) {
            char chr = str[iter];
            if (std::isdigit(static_cast<unsigned char>(chr)) != 0) {
                seenDigit = true;
            } else if (chr == '.' && !seenDot) {
                seenDot = true;
            } else {
                return false;
            }
            iter++;
        }
        return true;
    }

    bool isDouble(const std::string &str) {
        if (str.empty())
            return false;
        if (str[str.size() - 1] == 'f')
            return false;

        bool seenDot = false;
        bool seenDigit = false;

        if (!scanFloatingCore(str, str.size(), seenDot, seenDigit))
            return false;

        return seenDot && seenDigit;
    }

    bool isFloat(const std::string &str) {
        if (str.size() < 2)
            return false;
        if (str[str.size() - 1] != 'f')
            return false;

        bool seenDot = false;
        bool seenDigit = false;

        if (!scanFloatingCore(str, str.size() - 1, seenDot, seenDigit))
            return false;

        return seenDot && seenDigit;
    }

    DataType detectDataType(const std::string &str) {

        struct Rule { DataType type; bool (*match)(const std::string &); };
        static const Rule rules[] = {
                {TYPE_SPECIAL, isSpecial },
                {TYPE_CHAR,    isCharLiteral },
                {TYPE_CHAR,    isSingleNonDigitChar },
                {TYPE_FLOAT,   isFloat },
                {TYPE_DOUBLE,  isDouble },
                {TYPE_INT,     isInt }
        };

        DataType type = TYPE_INVALID;

        for (size_t i = 0; i < sizeof(rules) / sizeof(rules[0]); ++i) {
            if (rules[i].match(str)) {
                type = rules[i].type;
                break;
            }
        }
        return type;
    }

//******************************************************************************************/
//                            PRINTING FUNCTIONS
//******************************************************************************************/

    template <typename T>
    void printConversion(DataType type, T num) {
        if (num < 32 || num > 126)
            std::cout << "char: " FT_RED << "non displayable" << FT_RST << std::endl;
        else if (type == TYPE_CHAR)
            std::cout << "char: " FT_PUMPKIN2 "'" << num << FT_RST "'" << std::endl;
        else if (isprint(static_cast<char>(num)))
            std::cout << "char: " FT_PUMPKIN2 "'" << static_cast<char>(num) << FT_RST "'" << std::endl;
        else
            std::cout << "char: " FT_RED "impossible" FT_RST << std::endl;
        if (std::isnan(num) || (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max()))
            std::cout << "int: " << FT_RED "impossible" FT_RST << std::endl;
        else {
            if (type == TYPE_INT)
                std::cout << "int: " << FT_CADET_BLUE << num << FT_RST << std::endl;
            else
                std::cout << "int: " << FT_CADET_BLUE << static_cast<int>(num) << FT_RST << std::endl;
        }
        if (isnan(num) || (num < -std::numeric_limits<float>::max() || num > std::numeric_limits<float>::max()))
            std::cout << "float: " << FT_RED "impossible" FT_RST << std::endl;
        else {
            if (type == TYPE_FLOAT)
                std::cout << "float: " FT_GREEN << std::fixed << std::setprecision(1) << num << "f" FT_RST << std::endl;
            else
                std::cout << "float: " FT_GREEN << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" FT_RST << std::endl;
        }
        if (isnan(num) || (num < -std::numeric_limits<double>::max() || num > std::numeric_limits<double>::max()))
            std::cout << "double: " << FT_RED "impossible" FT_RST << std::endl;
        else {
            if (type == TYPE_DOUBLE)
                std::cout << "double: " FT_CYAN << std::fixed << std::setprecision(1) << num << FT_RST << std::endl;
            else
                std::cout << "double: " FT_CYAN << std::fixed << std::setprecision(1) << static_cast<double>(num) << FT_RST << std::endl;
        }
    }

//******************************************************************************************/
//								CONVERTION FUNCTIONS
//******************************************************************************************/

    void convertToChar(const std::string &str) {
        char chr = str[0];
        printConversion(TYPE_CHAR, chr);
    }

    void convertToInt(const std::string &str) {
        int int_nbr = stringToInt(str);
        if (int_nbr == 0) {
            if (str[0] == '0')
                printConversion(TYPE_INT, int_nbr);
            else
                printConversion(TYPE_INT, stringToDouble(str));
        } else
            printConversion(TYPE_INT, int_nbr);
    }

    void convertToFloat(const std::string &str) {
        float float_nbr = stringToFloat(str);
        printConversion(TYPE_FLOAT, float_nbr);
    }

    void convertToDouble(const std::string &str) {
        double double_nbr = stringToDouble(str);
        printConversion(TYPE_DOUBLE, double_nbr);
    }

    void specialCase(const std::string &str) {
        std::string infinitArrayF[3] = {"+inff", "-inff", "nanf"};
        std::string infinitArrayD[3] = {"+inf", "-inf", "nan"};

        for (int i = 0; i < 3; i++) {
            if (str == infinitArrayF[i] || str == infinitArrayD[i]) {
                std::cout << "char: " FT_RED "impossible" FT_RST << std::endl;
                std::cout << "int: " FT_RED "impossible" FT_RST << std::endl;
                std::cout << "float: " FT_GREEN << infinitArrayF[i] << FT_RST << std::endl;
                std::cout << "double: " FT_CYAN << infinitArrayD[i] << FT_RST << std::endl;
                return ;
            }
        }
        std::cerr << "Error: invalid data input" << std::endl;
    }

    int stringToInt(const std::string &str) {
        int int_nbr = 0;
        std::istringstream iss(str);
        iss >> int_nbr;
        if (iss.fail() || !iss.eof())
            return 0;
        return int_nbr;
    };

    std::string removeChar(const std::string &str) {
        if (str[str.size() - 1] == 'f') {
            return str.substr(0, str.size() - 1);
        }
        return str;
    }

    float stringToFloat(const std::string &str) {
        std::string temp = removeChar(str);
        float float_nbr = NAN;
        std::istringstream iss(temp);
        iss >> float_nbr;
        if (iss.fail() || !iss.eof())
            return std::numeric_limits<float>::quiet_NaN();
        return float_nbr;
    };

    double stringToDouble(const std::string &str) {
        double double_nbr = NAN;
        std::istringstream iss(str);
        iss >> double_nbr;
        if (iss.fail() || !iss.eof())
            return std::numeric_limits<double>::quiet_NaN();

        return double_nbr;
    };

}// namespace



