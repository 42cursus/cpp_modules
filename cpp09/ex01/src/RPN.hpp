/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:27:58 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 23:27:58 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <sstream>
#include <string>

class RPN
{
public:
	static std::string trim(const std::string &str);
	static void checkInput(const std::string &input);
	static int eval(const std::string &str);

private:
	static const char WHITESPACE[];
	static const char VALID_ALPHABET[];
	RPN();
	~RPN();;
//	static bool	_executeOperation(char token);
	RPN(const RPN &other);
	RPN& operator=(const RPN &other);
	std::stack<int>	_nums;
	static void		_executeOperation(std::stack<int> &stack, const char &elem);
};

#endif //RPN_HPP
