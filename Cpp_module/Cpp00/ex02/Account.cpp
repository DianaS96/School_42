/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:51:39 by coverand          #+#    #+#             */
/*   Updated: 2022/05/24 19:51:47 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <time.h>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void    Account::_displayTimestamp() {
    time_t        rawtime;
    struct tm   *timeinfo;
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    std::cout << std::setfill('0') << "[" << \
    1900 + timeinfo->tm_year << \
    std::setw(2) << timeinfo->tm_mon + 1 << \
    std::setw(2) << timeinfo->tm_mday << '_' << \
    std::setw(2) << timeinfo->tm_hour << \
    std::setw(2) << timeinfo->tm_min << \
    std::setw(2) << timeinfo->tm_sec << ']';
}

//[19920104_091532] index:0;amount:42;created
Account::Account(int initial_deposit) {
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _totalAmount += initial_deposit;
    _accountIndex = _nbAccounts;
    _nbAccounts += 1;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << \
    ";amount:" << _amount << \
    ";created" << std::endl;
}

Account::~Account(void) {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << \
    ";amount:" << _amount << \
    ";closed" << std::endl;
}

int Account::getNbAccounts() {
    return (_nbAccounts);
}

int Account::getTotalAmount() {
    return (_totalAmount);
}

int Account::getNbDeposits() {
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals() {
    return (_totalNbWithdrawals);
}

//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts << \
    ";total:" << _totalAmount << \
    ";deposits:" << _totalNbDeposits << \
    ";withdrawals:" << _totalNbWithdrawals << std::endl; 
}

//[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << \
    ";amount:" << _amount << \
    ";deposits:" << _nbDeposits << \
    ";withdrawals:" <<_nbWithdrawals << std::endl;
}

//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << \
    ";p_amount:" << _amount << \
    ";deposit:" << deposit;
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits += 1;
    _totalNbDeposits += 1;
    std::cout << ";amount:" << _amount << \
    ";nb_deposits:" << _nbDeposits << std::endl;
}

//[19920104_091532] index:0;p_amount:47;withdrawal:refused
//[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << \
    ";p_amount:" << _amount;
    if (withdrawal > _amount)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return (false);
    }
    _amount -= withdrawal;
    _nbWithdrawals += 1;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals += 1;
    std::cout << ";withdrawal:" << withdrawal << \
    ";amount:" << _amount << \
    ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}