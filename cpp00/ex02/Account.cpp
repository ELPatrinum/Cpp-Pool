/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:12:56 by muel-bak          #+#    #+#             */
/*   Updated: 2024/06/01 22:04:09 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int		Account::getNbAccounts( void )
{
	return(_nbAccounts);
}
int		Account::getTotalAmount( void )
{
	return(_totalAmount);
}
int		Account::getNbDeposits( void )
{
	return(_totalNbDeposits);
}
int		Account::getNbWithdrawals( void )
{
	return(_totalNbWithdrawals);
}
void Account::_displayTimestamp(void)
{
	std::time_t	time;
	time = std::time(NULL);

	std::cout << std::setfill('0') <<"[" << 1900 + std::localtime(&time)->tm_year
			  << std::setw(2) << 1 + std::localtime(&time)->tm_mon
			  << std::setw(2) << std::localtime(&time)->tm_mday << "_"
			  << std::setw(2) << std::localtime(&time)->tm_hour
			  << std::setw(2) << std::localtime(&time)->tm_min
			  << std::setw(2) << std::localtime(&time)->tm_sec << "] " << std::flush;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:"    << getNbAccounts()    << ";"
			  << "total:"       << getTotalAmount()   << ";"
			  << "deposits:"    << getNbDeposits()    << ";"
			  << "withdrawals:" << getNbWithdrawals() << std::endl;
}


void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << "index:"      << _accountIndex << ";"
			  << "p_amount:"   << _amount       << ";" << std::flush;
	_amount += deposit;
	std::cout << "deposit:"    << deposit       << ";"
			  << "amount:"     << _amount       << ";"
			  << "nb_deposit:" << _nbDeposits   << std::endl;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:"      << _accountIndex << ";"
              << "p_amount:"   << _amount       << ";"
              << "withdrawal:" << std::flush;
	if (withdrawal > checkAmount())
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal << ";" << std::flush;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << "amount:"     << _amount     << ";"
			  << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (true);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:"       << _accountIndex  << ";"
			  << "amount:"      << _amount        << ";"
			  << "deposits:"    << _nbDeposits    << ";"
			  << "withdrawals:" << _nbWithdrawals << std::endl;
}

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbWithdrawals = 0;
	_nbDeposits = 0;
	_displayTimestamp();
	std::cout << "index:"  << _accountIndex << ";"
			  << "amount:" << _amount       << ";"
			  << "created" << std::endl;
}
Account::~Account( void )
{
	_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:"  << _accountIndex << ";"
			  << "amount:" << _amount       << ";"
			  << "closed" << std::endl;
}
