// INCLUDES.
#pragma once

#include "Customer.h"

//////////////////////////////////////////////////////////////

constexpr int MAX_CUSTOMERS = 10;

class Bank
{
public:
	Bank();
	~Bank();

private:
	// MEMBER FUNCTIONS.
	void welcome();
	void adminLogin();
	void customerLogin();
	void printAdminOptions();
	void printCustomerOptions();
	void makeCustomerChoice(int& l_choice);
	void makeAdminChoice(int& l_choice);
	void addNewCustomer();
	void removeCustomer();
	void searchCustomer();
	void addAccForExistingCustomer();
	void closeAccForExistingCustomer();
	void loanApplication();
	void calcInterest();
	int searchCustomer(std::string l_name);
	bool loanApplication(double l_currBal, int l_borrowAmount);
	double calcInterest(double& l_currBal, double& l_rate);

	// MEMBER VARIABLES.	
	Customer* m_customers[MAX_CUSTOMERS];		// An array of 10 pointers of type Customer.
	int m_customerIndex;
	double m_rate;
};

