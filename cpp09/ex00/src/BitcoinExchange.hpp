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

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

class BitcoinExchange {
public:
	struct Date {
		int year;
		int month;
		int day;

		Date &operator=(const Date &other);

		bool operator<(const Date &other) const;
		bool operator==(const Date &other) const;
		bool operator!=(const Date &other) const;
		bool operator>(const Date &other) const;
		bool operator<=(const Date &other) const;
		bool operator>=(const Date &other) const;

		static bool formatIsValid(const std::string &date_str);
		void		setDate(const std::string &date_str);
		std::string outputDate() const;
		virtual ~Date();
	};

	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &other);

	BitcoinExchange &operator=(BitcoinExchange const &src);
	void			 loadDatabase(const std::string &filename);
	void			 processInput(const char *filename);

	class DBSyntaxException : public std::exception { // CSV parses but syntax is invalid
	public:
		virtual const char *what() const throw();
	};

	class FileLoadException : public std::exception { // I/O open failure
	public:
		virtual const char *what() const throw();
	};

	class InvalidDateException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	static const char DATABASE_FILENAME[];

private:
	std::map<Date, float> _db;
	float				  _findRateForDate(const Date &date) const;
	static float		  parseValue(const std::string &val_str);
	float				  parseRate(const std::string &rate_str) const;
};

#endif //BITCOINEXCHANGE_HPP
