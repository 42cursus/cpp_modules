/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:31:49 by abelov            #+#    #+#             */
/*   Updated: 2025/02/14 12:31:50 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include "Account.hpp"

#define nullptr NULL

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp()
{
	time_t currentTime = time(nullptr);
	tm *localTime = localtime(&currentTime);

	char formattedTime[19];
	strftime(formattedTime, sizeof(formattedTime),
			 "[%Y%m%d_%H%M%S] ",  localTime);
	std::cout << formattedTime;
}

Account::Account(void)
{

	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
			  << ";deposits:"
			  << getNbDeposits() << ";withdrawals:" << getNbWithdrawals()
			  << "\n";
}

int Account::getTotalAmount()
{
	return _totalAmount;
}

int Account::getNbAccounts()
{
	return _nbAccounts;
}

int Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
			  << ";deposits:"
			  << getNbDeposits() << ";withdrawals:" << getNbWithdrawals()
			  << "\n";
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_nbWithdrawals = 0;
	_nbDeposits = 0;
	_amount = initial_deposit;
	_totalAmount += _amount; // total accounts
	_accountIndex = _nbAccounts;
	_nbAccounts++;

	std::cout << "index:" << _accountIndex << ";amount:" << initial_deposit
			  << ";created\n";

}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			  << ";closed\n";
}

void Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
			  << ";deposit:"
			  << deposit << ";amount:" << _amount + deposit << ";nb_deposits:"
			  << _nbDeposits << "\n";
	_totalAmount += deposit;
	_amount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (_amount >= withdrawal)
	{
		_nbWithdrawals++;
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
				  << ";withdrawal:"
				  << withdrawal << ";amount:" << _amount - withdrawal
				  << ";nb_withdrawals:" << _nbWithdrawals << "\n";
		_amount -= withdrawal;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		return true;
	}
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
			  << ";withdrawal:refused\n";
	return false;
}

int Account::checkAmount() const
{
	return _amount;
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			  << ";deposits:"
			  << _nbDeposits << ";withdrawals:" << _nbWithdrawals << "\n";
}
