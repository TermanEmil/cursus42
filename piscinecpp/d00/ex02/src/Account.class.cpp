/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 10:16:15 by eterman           #+#    #+#             */
/*   Updated: 2017/07/21 12:45:43 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <iostream>
#include <ctime>
#include <sstream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts (void) {
	return _nbAccounts;
}

int Account::getTotalAmount (void) {
	return _totalAmount;
}

int Account::getNbDeposits (void) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals (void) {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos (void) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}

void Account::_displayTimestamp (void) {

	//cout << "[20150406_153629] ";
	//return;

	std::stringstream currentDateTime;
	time_t ttNow = time(0);
	tm *ptmNow;

	ptmNow = localtime(&ttNow);

	currentDateTime << "[";

	currentDateTime << 1900 + ptmNow->tm_year;

	if (ptmNow->tm_mon < 9)
		currentDateTime << "0" << 1 + ptmNow->tm_mon;
	else
		currentDateTime << (1 + ptmNow->tm_mon);

	if (ptmNow->tm_mday < 10)
		currentDateTime << "0" << ptmNow->tm_mday << "_";
	else
		currentDateTime <<  ptmNow->tm_mday << "_";

	if (ptmNow->tm_hour < 10)
		currentDateTime << "0" << ptmNow->tm_hour;
	else
		currentDateTime << ptmNow->tm_hour;

	if (ptmNow->tm_min < 10)
		currentDateTime << "0" << ptmNow->tm_min;
	else
		currentDateTime << ptmNow->tm_min;

	if (ptmNow->tm_sec < 10)
		currentDateTime << "0" << ptmNow->tm_sec;
	else
		currentDateTime << ptmNow->tm_sec;

	currentDateTime << "] ";
	std::cout << currentDateTime.str();
}

Account::Account (int initial_deposit = 0) : _amount(initial_deposit) {

	_nbWithdrawals = 0;
	_nbDeposits = 0;
	_accountIndex = _nbAccounts;

	//Static
	_nbAccounts++;
	_totalAmount += _amount;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";created" << std::endl;
}

Account::~Account (void) {
	_nbAccounts--;
	_totalAmount -= _amount;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;
}

void Account::makeDeposit (int deposit) {
	int p_amount = _amount;

	_totalNbDeposits++;
	_totalAmount += deposit;

	_nbDeposits++;
	_amount += deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal (int withdrawal) {
	int p_amount = _amount;

	if (_amount - withdrawal < 0) {
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";";
		std::cout << "p_amount:" << p_amount << ";";
		std::cout << "withdrawal:refused" << std::endl;

		return false;
	}

	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;

	_nbWithdrawals++;
	_amount -= withdrawal;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;

	return true;
}

void Account::displayStatus (void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

int Account::checkAmount (void) const {
	static int nbOfTimesCalled = 0;

	nbOfTimesCalled++;

	std::cout << "NbOfTimesCalled: " << nbOfTimesCalled << std::endl;

	return _amount;
}
