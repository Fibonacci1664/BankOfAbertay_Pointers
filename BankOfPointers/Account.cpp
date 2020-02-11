// INCLUDES.
#include "Account.h"

//////////////////////////////////////////////////////////////

// CONSTRUCTORS / DESTRUCTOR.
Account::Account(std::string l_name, int l_accNum, double l_openingBal) :
	m_name(l_name), m_accNum(l_accNum), m_openingBal(l_openingBal)
{
	m_currBal = l_openingBal;
}

//////////////////////////////////////////////////////////////

Account::~Account()
{
	std::cout << "Account object destroyed!\n";
}

//////////////////////////////////////////////////////////////

// MEMBER FUNCTIONS.
void Account::depositFunds(double l_amount)
{
	m_currBal += l_amount;
}

//////////////////////////////////////////////////////////////

void Account::withdrawFunds(double l_amount)
{
	if (m_currBal - l_amount < 0)
	{
		std::cout << "You have insufficient funds available for this transaction at this time.\n";
	}
	else
	{
		m_currBal -= l_amount;
	}
}

//////////////////////////////////////////////////////////////

void Account::checkBalance()
{
	std::cout << "Your current balance is " << char(156) << m_currBal << '\n';
}

//////////////////////////////////////////////////////////////

// GETTERS & SETTERS.
double Account::getBalance()
{
	return m_currBal;
}

int Account::getAccNum()
{
	return m_accNum;
}