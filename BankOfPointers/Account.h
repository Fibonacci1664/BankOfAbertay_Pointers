#pragma once
#include<iostream>

//////////////////////////////////////////////////////////////

class Account
{
public:
	Account(std::string l_name, int l_accNum, double l_openingBal);
	~Account();

	// MEMBER FUNCTIONS.
	void depositFunds(double l_amount);
	void withdrawFunds(double l_amount);
	void checkBalance();

	// GETTERS & SETTERS.
	int getAccNum();
	double getBalance();

private:
	// MEMBER VARIABLES.
	std::string m_name;
	int m_accNum;
	double m_openingBal;
	double m_currBal;
};

