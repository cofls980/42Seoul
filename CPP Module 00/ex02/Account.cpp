#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::t::_nbAccounts = 0;
int Account::t::_totalAmount = 0;
int Account::t::_totalNbDeposits = 0;
int Account::t::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	for (int i = 0;i < getNbAccounts();i++)
	{
		_displayTimestamp();
		std::cout << "index:" << i << ";amount:" << getTotalAmount() << ";created" << std::endl;
	}
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts++;
	_totalAmount += initial_deposit;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}

/*Account::~Account(void)
{}

void	Account::makeDeposit(int deposit)
{}

bool	Account::makeWithdrawal(int withdrawal)
{}
*/
int	Account::checkAmount(void) const//const: 이 클래스 함수가 클래스의 멤버 변수를 변경하는 것을 컴파일러 오류로 만듭니다.
{
	return this->_amount;
}

void	Account::displayStatus(void) const
{}
//-----------------
void	Account::_displayTimestamp(void)
{
	time_t tmp;
	struct tm* tinfo;

	time(&tmp);
	tinfo = localtime(&tmp);
	std::cout << "[";
	std::cout << 1900 + tinfo->tm_year;
	if (1 + tinfo->tm_mon < 10)
		std::cout << "0";
	std::cout << 1 + tinfo->tm_mon;
	if (tinfo->tm_mday < 10)
		std::cout << "0";
	std::cout << tinfo->tm_mday << "_";
	if (tinfo->tm_hour < 10)
		std::cout << "0";
	std::cout << tinfo->tm_hour;
	if (tinfo->tm_min < 10)
		std::cout << "0";
	std::cout << tinfo->tm_min;
	if (tinfo->tm_sec < 10)
		std::cout << "0";
	std::cout << tinfo->tm_sec;
	std::cout << "] ";
}
//[19920104_091532]
/*Account::Account(void)
{}*/