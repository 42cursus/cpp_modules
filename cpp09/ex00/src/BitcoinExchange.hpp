/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:26:33 by abelov            #+#    #+#             */
/*   Updated: 2026/02/25 00:48:59 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
public:
	BitcoinExchange(void);
	~BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange const &src);

	BitcoinExchange &operator=(BitcoinExchange const &src);

	void   load_db(const char *filename);
	double lookup_value(std::string date, double amount) const;
	void   print_lookup(std::string date, double amount) const;
	void   print_lookup(std::string date, long amount) const;
	void   process_input(const char *filename) const;

	class DBSyntaxException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class FileLoadException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class InvalidDateException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class NegativeAmountException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

private:
	std::map<std::string, double> _db;

	void _assertDateValid(std::string date) const;
};


#endif //BITCOINEXCHANGE_HPP
