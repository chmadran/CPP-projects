/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:24:07 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/20 18:32:12 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"


Account::_nbAccounts = 0;
Account::_totalAmount = 0
Account::_totalNbDeposits = 0;
Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit){
	this->_amount = initial_deposit;
	this->_accountIndex = getNbAccounts();
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	Account::_nbAccounts++;
	return;
}

Account::~Account(){
	Account::_nbAccounts--;
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
	std::cout << "Account index: " << _accountIndex << std::endl;
	std::cout << "Amount: " << _amount << std::endl;
	std::cout << "Number of deposits: " << _nbDeposits << std::endl;
	std::cout << "Number of withdrawals: " << _nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos() {
	std::cout << "Number of accounts: " << _nbAccounts << std::endl;
	std::cout << "Total amount: " << _totalAmount << std::endl;
	std::cout << "Total number of deposits: " << _totalNbDeposits << std::endl;
	std::cout << "Total number of withdrawals: " << _totalNbWithdrawals << std::endl;
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
