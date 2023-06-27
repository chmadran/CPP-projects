/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:24:07 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/27 18:04:50 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <chrono>
#include "Account.hpp"


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit){
	this->_amount = initial_deposit;
	this->_accountIndex = this->_nbAccounts++;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << initial_deposit << ";";
	std::cout << "created" << std::endl;
	return;
}

Account::Account(){
	this->_amount = 0;
	this->_accountIndex = this->_nbAccounts++;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
	return;
}

Account::~Account(){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
	return;
}

int	Account::getNbAccounts( void ) {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void ){
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void ){
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ){
	return  (Account::_totalNbWithdrawals);
}

int		Account::checkAmount( void ) const {
	return (this->_amount);
}

void Account::displayStatus() const {
	Account::_displayTimestamp();
	std::cout << "Account index: " << this->_accountIndex << std::endl;
	std::cout << "Amount: " << this->_amount << std::endl;
	std::cout << "Number of deposits: " << this->_nbDeposits << std::endl;
	std::cout << "Number of withdrawals: " << this->_nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos() {
	std::cout << "Number of accounts: " << Account::_nbAccounts << std::endl;
	std::cout << "Total amount: " << Account::_totalAmount << std::endl;
	std::cout << "Total number of deposits: " << Account::_totalNbDeposits << std::endl;
	std::cout << "Total number of withdrawals: " << Account::_totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
	std::time_t time_now = std::chrono::system_clock::to_time_t(now);

	tm utc_tm = *localtime(&time_now);
	std::cout << std::setfill('0') << "[" << (utc_tm.tm_year + 1900)
			<< std::setw(2) << utc_tm.tm_mon
			<< std::setw(2) << utc_tm.tm_mday << "_"
			<< std::setw(2) << utc_tm.tm_hour
			<< std::setw(2) << utc_tm.tm_min
			<< std::setw(2) << utc_tm.tm_sec << "] ";
}

void	Account::makeDeposit( int deposit ){
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ){
	if (this->_amount >= withdrawal) {
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		return true;
	}
	return false;
}
