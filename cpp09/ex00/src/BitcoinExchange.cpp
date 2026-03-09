/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:26:40 by abelov            #+#    #+#             */
/*   Updated: 2026/02/25 00:49:02 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <fstream>
#include <limits>
#include <math.h>

/*
** -------------------------------- STATIC VARS -------------------------------
*/

const char BitcoinExchange::DATABASE_FILENAME[] = "data.csv";

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _db(other._db)
{}

/*
** ------------------------------- DESTRUCTORS --------------------------------
*/

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange::Date::~Date()
{}

/*
** -------------------------------- OPERATORS ---------------------------------
*/

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other) { // Self-assignment check
		_db = other._db;
	}
	return *this;
}

BitcoinExchange::Date &BitcoinExchange::Date::operator=(const BitcoinExchange::Date &other)
{
	if (this != &other) {
		year  = other.year;
		month = other.month;
		day	  = other.day;
	}
	return (*this);
}


bool BitcoinExchange::Date::operator>=(const BitcoinExchange::Date &other) const
{
	return !(*this < other);
}

bool BitcoinExchange::Date::operator<=(const BitcoinExchange::Date &other) const
{
	return !(other < *this);
}

bool BitcoinExchange::Date::operator>(const BitcoinExchange::Date &other) const
{
	return other < *this;
}

bool BitcoinExchange::Date::operator==(const BitcoinExchange::Date &other) const
{
	return year == other.year && month == other.month && day == other.day;
}

bool BitcoinExchange::Date::operator!=(const BitcoinExchange::Date &other) const
{
	return !(other == *this);
}


bool BitcoinExchange::Date::operator<(const BitcoinExchange::Date &other) const
{
	bool result = false;

	if (year != other.year)
		result = year < other.year;
	else if (month != other.month)
		result = month < other.month;
	else
		result = day < other.day;
	return result;
}


/*
** -------------------------------- OVERLOADS ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void BitcoinExchange::processInput(const char *filename)
{
	std::ifstream ifs(filename);

	if (ifs.fail() || !ifs.is_open())
		throw FileLoadException();

	std::string line;

	std::getline(ifs, line); // skip header
	while (std::getline(ifs, line) != 0) {
		size_t pos = line.find('|');

		if (pos == std::string::npos || pos == 0)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		Date  _date;
		float val = NAN;
		try {
			std::string date_str = line.substr(0, pos - 1);
			std::string val_str	 = line.substr(pos + 2);

			_date.setDate(date_str);
			val = parseValue(val_str);
		} catch (std::invalid_argument &ex) {
			std::cout << ex.what() << std::endl;
			continue;
		} catch (std::out_of_range &ex) {
			std::cout << ex.what() << std::endl;
			continue;
		}
		float total = val * _findRateForDate(_date);
		std::cout << _date.outputDate() << " => " << val << " = " << total << std::endl;
	}
}

float BitcoinExchange::parseValue(const std::string &val_str)
{
	char *end		 = NULL;
	errno			 = 0;
	double parsedVal = strtod(val_str.c_str(), &end);

	if (end == val_str.c_str() || *end != '\0')
		throw std::invalid_argument("Error: Invalid value format: '" + val_str + "'");
	if (errno == ERANGE || parsedVal < -std::numeric_limits<float>::max() ||
		parsedVal > std::numeric_limits<float>::max())
		throw std::out_of_range("Error: number is out of range: '" + val_str + "'");

	float val = static_cast<float>(parsedVal);
	if (val > 1000)
		throw std::out_of_range("Error: number is too large: '" + val_str + "'");
	if (val < 0)
		throw std::out_of_range("Error: not a positive number: '" + val_str + "'");
	return val;
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream ifs(filename.c_str());
	std::string	  line;

	if (ifs.fail())
		throw FileLoadException();

	std::getline(ifs, line); // skip header
	while (std::getline(ifs, line) != 0) {
		Date   _date;
		size_t pos = line.find(',');

		if (pos == std::string::npos) // not found
		{
			std::cerr << "Error: Invalid format in database." << std::endl;
			std::cerr << "Line:" << line << std::endl;
			throw DBSyntaxException();
		}

		std::string date_str = line.substr(0, pos);
		std::string rate_str = line.substr(pos + 1);

		_date.setDate(date_str);
		float rate = parseRate(rate_str);
		std::pair<Date, float> new_pair(_date, rate);
		_db.insert(new_pair);
	}
}

float BitcoinExchange::parseRate(const std::string &rate_str) const
{
	char *end		  = NULL;
	errno			  = 0;
	double parsedRate = strtod(rate_str.c_str(), &end);

	if (end == rate_str.c_str() || *end != '\0')
		throw std::invalid_argument("Error: invalid exchange rate: '" + rate_str + "'");
	if (errno == ERANGE || parsedRate < -std::numeric_limits<float>::max() ||
		parsedRate > std::numeric_limits<float>::max())
		throw std::out_of_range("Error: exchange rate is out of range: '" + rate_str + "'");

	return static_cast<float>(parsedRate);
}

float BitcoinExchange::_findRateForDate(const BitcoinExchange::Date &date) const
{
	// find the closest date that is less than `date`.
	std::map<Date, float>::const_iterator it = _db.lower_bound(date);

	if (it == _db.end() || (it->first != date && it != _db.begin()))
		it--; // move back to get the closest date that is less than `date`
	return it->second;
}

/**
 * Check for YYYY-MM-DD format
 * @param date_str
 * @return
 */
bool BitcoinExchange::Date::formatIsValid(const std::string &date_str)
{
	if (date_str.size() != 10) // Check length
		return false;

	if (date_str.at(4) != '-' || date_str.at(7) != '-')
		return false;

	bool result = true;
	for (size_t i = 0; i < date_str.size(); ++i) {
		if (i == 4 || i == 7)
			continue;
		if (isdigit(date_str.at(i)) == 0) {
			result = false;
			break;
		}
	}
	return result;
}

std::string BitcoinExchange::Date::outputDate() const
{
	std::ostringstream oss;

	oss << year << "-";
	if (month >= 1 && month <= 9)
		oss << "0";
	oss << month << "-";
	if (day >= 1 && day <= 9)
		oss << "0";
	oss << day;
	return oss.str();
}

/*
** -------------------------------- ACCESSORS ---------------------------------
*/

void BitcoinExchange::Date::setDate(const std::string &date_str)
{
	if (!formatIsValid(date_str))
		throw std::invalid_argument("invalid date format: expected YYYY-MM-DD");
	char *end = NULL;
	enum Month { ILL = 0, JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
	static const int valid_days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	const int parsedYear = static_cast<int>(std::strtol(date_str.c_str(), &end, 10));
	if (*end != '-' || parsedYear < 0)
		throw std::invalid_argument("Error: invalid year in date: " + date_str);

	const int parsedMonth = static_cast<int>(std::strtol(end + 1, &end, 10));
	if (*end != '-' || parsedMonth < JAN || parsedMonth > DEC)
		throw std::invalid_argument("Error: invalid month in date: " + date_str);

	const int parsedDay = static_cast<int>(std::strtol(end + 1, &end, 10));
	if (*end != '\0' || parsedDay < 1 || parsedDay > valid_days[parsedMonth])
		throw std::invalid_argument("Error: invalid day in date: " + date_str);

	if (parsedMonth == FEB) {
		bool isLeapYear = (parsedYear % 4 == 0 && (parsedYear % 100 != 0 || parsedYear % 400 == 0));
		if (parsedDay > (isLeapYear ? 29 : 28))
			throw std::invalid_argument("Error: invalid day for February: " + date_str);
	}

	year  = parsedYear;
	month = parsedMonth;
	day	  = parsedDay;
}

/*
** -------------------------------- EXCEPTIONS --------------------------------
*/

const char *BitcoinExchange::DBSyntaxException::what() const throw()
{
	return ("Error: syntax error in db file.");
}

const char *BitcoinExchange::FileLoadException::what() const throw()
{
	return ("Error: could not open file.");
}

const char *BitcoinExchange::InvalidDateException::what() const throw()
{
	return ("Error: invalid date provided in file.");
}

/*
** -------------------------------- MISCELLANEOUS --------------------------------
*/

