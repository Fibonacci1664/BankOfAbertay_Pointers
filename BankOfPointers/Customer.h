#pragma once
#include<iostream>
#include<vector>
#include"Account.h"

//////////////////////////////////////////////////////////////

constexpr int MAX_ACCOUNTS = 3;

class Customer
{
public:
	Customer(std::string l_name, int l_customerID);
	~Customer();

	// MEMBER FUCNTIONS.
	bool login(std::string l_name, int l_customerID);
	Account searchAccounts(int& accNum);
	int searchAccounts();
	void depositFunds();
	void depositFunds(int accNum, int loanAmount);
	void withdrawFunds();
	void checkBalance();
	void openAccount();
	void closeAccount(int& accNum);
	void listAllAccounts();

	// GETTERS & SETTERS.
	int getIndex();
	void setIndex(int l_indexPos);
	int getAccNum(int indexPos);
	double getBalanceFromAcc(int accNum);
	std::string getName();
	void setName(std::string l_name);

private:
	// MEMBER VARIABLES.
	Account* m_accounts[MAX_ACCOUNTS];
	std::string m_name;
	int m_customerID;
	int m_index;
};

