/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:28:04 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 23:28:05 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstring>
/*
** -------------------------------- STATIC VARS -------------------------------
*/

const char RPN::WHITESPACE[] = " \t\n\r\f\v";
const char RPN::VALID_ALPHABET[] = " \t\n\r\f\v0123456789+-*/";

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

RPN::RPN()
{}


/*
** ------------------------------- DESTRUCTORS --------------------------------
*/

RPN::~RPN()
{}

/*
** -------------------------------- OPERATORS ---------------------------------
*/

/*
** -------------------------------- OVERLOADS ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

int RPN::eval(const std::string &input)
{
	std::stack<int>	  stack;

	for (std::string::const_iterator it = input.begin(); it != input.end(); ++it) {
		const char &elem = *it;
		if (std::strchr(static_cast<const char*>(RPN::WHITESPACE), elem) != NULL)
			continue;
		if (std::isdigit(static_cast<unsigned char>(elem)) == 0)
			_executeOperation(stack, elem);
		else {
			int temp = elem - '0';
			stack.push(temp);
		}
	}
	return stack.top();
}

void RPN::_executeOperation(std::stack<int> &stack, const char &elem)
{
	int result = 0;

	int num1 = stack.top();
	stack.pop();
	int num2 = stack.top();
	stack.pop();

	switch (elem) {
		case '+':
			result = num2 + num1;
			break;
		case '-':
			result = num2 - num1;
			break;
		case '/':
			if (num1 == 0)
				throw std::runtime_error("Error: divide by zero!\n");
			result = num2 / num1;
			break;
		case '*':
			result = num2 * num1;
			break;
		default:
			throw std::invalid_argument("Error: Invalid op");
			break;
	}
	stack.push(result);
}

std::string RPN::trim(const std::string &str)
{
	std::string		  substr;

	std::string::size_type start = str.find_first_not_of(static_cast<const char*>(RPN::WHITESPACE));
	if (start != std::string::npos) {
		std::string::size_type end = str.find_last_not_of(static_cast<const char*>(RPN::WHITESPACE));
		substr					   = str.substr(start, end - start + 1);
	} else
		substr = "";
	return substr;
}

void RPN::checkInput(const std::string &input)
{
	int amountOfDigits = 0;
	int amountOfOps	   = 0;

	if (input.size() < 3)
		throw std::invalid_argument("Error: invalid RPN format. Calculus isn't possible");

	if ((std::isdigit(static_cast<unsigned char>(input.at(0))) == 0) &&
		(std::isdigit(static_cast<unsigned char>(input.at(1))) == 0))
		throw std::invalid_argument("Error: invalid expression");

	for (std::string::const_iterator it = input.begin(); it != input.end(); ++it) {
		if (std::strchr(static_cast<const char*>(RPN::VALID_ALPHABET), *it) == NULL)
			throw std::invalid_argument(std::string("Error: invalid symbol: ") + *it);
		if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
			amountOfOps++;
		else if (std::isdigit(static_cast<unsigned char>(*it)) != 0)
			amountOfDigits++;
	}

	if (amountOfOps != (amountOfDigits - 1))
		throw std::invalid_argument("invalid RPN format. Calculus isn't possible");
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