// INCLUDES.
#include<iostream>
//#include<vector>

#include "Bank.h"

//////////////////////////////////////////////////////////////

// CONSTRUCTORS / DESTRUCTOR.
Bank::Bank()
{
	// Initialize all elements in the dynamically created array of pointers to NULL.
	for (int i = 0; i < MAX_CUSTOMERS; ++i)
	{
		m_customers[i] = nullptr;
	}

	m_customerIndex = 0;
	m_rate = 0.035;			// 3.5% interest rate.
	welcome();
}

//////////////////////////////////////////////////////////////

Bank::~Bank()
{
	std::cout << "Bank object destroyed!\n";
}

//////////////////////////////////////////////////////////////

// MEMBER FUNCTIONS.
void Bank::welcome()
{
	std::cout << "WELCOME TO THE BANK OF ABERTAY\n";
	std::cout << '\n';
	std::cout << "PLEASE CHOOSE FROM THE FOLLOWING OPTIONS:> \n";

	int choice;

	std::cout << "\n\t1. Admin Login.\n"
		<< "\t2. Customer Login.\n"
		<< "\t3. Quit App.\n";

	std::cout << "\nChoose a number to continue:> ";
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		adminLogin();
		break;
	case 2:
		customerLogin();
		break;
	case 3:
		exit(0);
	default:
		std::cout << "\nOops, something went wrong choosing your login option.\n";
		break;
	}
}

//////////////////////////////////////////////////////////////

void Bank::adminLogin()
{
	std::cout << "\nWELCOME TO THE ADMIN LOGIN.\n";

	std::string username = "admin";
	int password = 12345;

	std::string uNameInput;
	int pWordInput;

	int attempts = 0;

	while (attempts < 3)
	{
		std::cout << "\nADMIN USERNAME:> ";
		std::cin >> uNameInput;

		std::cout << "\nADMIN PASSWORD:> ";
		std::cin >> pWordInput;

		std::cin.clear();
		std::cin.ignore(1000, '\n');

		if (username == uNameInput && password == pWordInput)
		{
			printAdminOptions();
			break;
		}

		++attempts;

		std::cout << "\nIncorrect admin login details, please try again " << (3 - attempts) <<
			" attempts remaining\n";
	}

	if (attempts == 3)
	{
		std::cout << "\nTo many failed logins, goodbye!\n";
	}
	else
	{
		welcome();
	}
}

//////////////////////////////////////////////////////////////

void Bank::customerLogin()
{
	std::cout << "\nWELCOME TO THE CUSTOMER LOGIN.\n";

	std::string name;
	int customerID;
	int attempts = 0;
	bool loginScuccesful = false;

	while (attempts < 3)
	{
		++attempts;
		std::cin.clear();
		std::cin.ignore(1000, '\n');

		std::cout << "\nPlease enter your surname:> ";
		std::cin >> name;

		std::cout << "\nPlease enter your customer ID:> ";
		std::cin >> customerID;

		for (unsigned int i = 0; i < MAX_CUSTOMERS; ++i)
		{
			loginScuccesful = m_customers[i]->login(name, customerID);

			if (loginScuccesful)
			{
				m_customerIndex = i;
				break;
			}
		}

		if (loginScuccesful)
		{
			printCustomerOptions();
			break;
		}

		std::cout << "\nIncorrect customer login details, please try again " << (3 - attempts) <<
			" attempts remaining\n";
	}

	if (attempts == 3)
	{
		std::cout << "\nTo many failed logins, goodbye!\n";
	}
	else
	{
		welcome();
	}
}

//////////////////////////////////////////////////////////////

void Bank::printAdminOptions()
{
	int choice = 0;

	while (choice < 8)
	{
		std::cout << "\nWELCOME TO ADMIN OPTIONS\n";

		std::cout << "\n\t1. Add New Customer.\n"
			<< "\t2. Remove Customer.\n"
			<< "\t3. Search Customers.\n"
			<< "\t4. Add New Acc for Existing Customer.\n"
			<< "\t5. Close Acc for Existing Customer.\n"
			<< "\t6. Calculate Interest.\n"
			<< "\t7. Print Options Again.\n"
			<< "\t8. Return to Main Menu.\n";

		do
		{
			std::cout << "\nChoose a number to continue:> ";
			std::cin >> choice;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		} while (!std::cin.good());

		std::cout << '\n';
		makeAdminChoice(choice);
	}
}

//////////////////////////////////////////////////////////////

void Bank::printCustomerOptions()
{
	int choice = 0;

	while (choice < 9)
	{
		std::cout << "\nWELCOME TO YOUR CUSTOMER OPTIONS\n";

		std::cout << "\n\t1. Request to Open New Account.\n"
			<< "\t2. Request to Close Account.\n"
			<< "\t3. Search Accounts.\n"
			<< "\t4. List all Accounts.\n"
			<< "\t5. Deposit Funds.\n"
			<< "\t6. Withdraw Funds.\n"
			<< "\t7. Make a Loan Application.\n"
			<< "\t8. Check Balance.\n"
			<< "\t9. Return to Main Menu.\n";

		do
		{
			std::cout << "\nChoose a number to continue:> ";
			std::cin >> choice;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		} while (!std::cin.good());

		std::cout << '\n';
		makeCustomerChoice(choice);
	}
}

//////////////////////////////////////////////////////////////

void Bank::makeCustomerChoice(int& l_choice)
{
	switch (l_choice)
	{
	case 1:
		adminLogin();
		break;
	case 2:
		adminLogin();
		break;
	case 3:
		m_customers[m_customerIndex]->searchAccounts();
		break;
	case 4:
		m_customers[m_customerIndex]->listAllAccounts();
		break;
	case 5:
		m_customers[m_customerIndex]->depositFunds();
		break;
	case 6:
		m_customers[m_customerIndex]->withdrawFunds();
		break;
	case 7:
		loanApplication();
		break;
	case 8:
		m_customers[m_customerIndex]->checkBalance();
		break;
	case 9:
		return;
		break;
	default:
		std::cout << "\nOops, something went wrong choosing your customer option.\n";
		break;
	}
}

//////////////////////////////////////////////////////////////

void Bank::makeAdminChoice(int& l_choice)
{
	switch (l_choice)
	{
	case 1:
		addNewCustomer();
		break;
	case 2:
		removeCustomer();
		break;
	case 3:
		searchCustomer();
		break;
	case 4:
		addAccForExistingCustomer();
		break;
	case 5:
		closeAccForExistingCustomer();
		break;
	case 6:
		calcInterest();
		break;
	case 7:
		printAdminOptions();
		break;
	case 8:
		return;
		break;
	default:
		std::cout << "\nOops, something went wrong choosing your admin option.\n";
		break;
	}
}

//////////////////////////////////////////////////////////////

void Bank::addNewCustomer()
{
	std::string name;
	int customerID;
	int indexPos = 0;

	std::cout << "\nPlease enter the new customers name:> ";
	std::cin >> name;

	customerID = rand() % 100000 + 1;

	std::cout << "\nYour customer ID is " << customerID << ".\n";
	std::cout << "\n*********************** IMPORTANT *************************\n";
	std::cout << "************ PLEASE NOTE YOUR CUSTOMER ID NUMBER **********\n";

	for (int i = 0; i < MAX_CUSTOMERS; ++i)
	{
		if (m_customers[i] == nullptr)
		{
			m_customers[i] = new Customer(name, customerID);
			indexPos = i;
			break;;
		}
	}

	//m_customers.push_back(Customer(name, customerID));

	std::cout << "\nA new customer with the name " << name << " now exists\n";
	//customers[customers.size() - 1].setName(name);

	char ans;

	std::cout << "\nWould you like to open an account now for this customer: y/n:> ";
	std::cin >> ans;

	if (ans == 'y')
	{
		m_customers[indexPos]->openAccount();
	}
	else
	{
		std::cout << "\nYou can always open an account through your personal customer options later.\n";
	}
}

//////////////////////////////////////////////////////////////

void Bank::removeCustomer()
{
	if (m_customers[m_customerIndex] == nullptr)
	{
		std::cout << "\nThere a zero customers on file.\n";
		return;
	}

	// Remove a customer.

	std::string name;
	std::cout << "\nPlease enter the surname of the customer you would like to remove:> ";
	std::cin >> name;

	int indexPos = searchCustomer(name);

	if (indexPos > -1)
	{
		delete m_customers[m_customerIndex];
		m_customers[m_customerIndex] = nullptr;

		std::cout << "\nCustomer " << name << " has been removed\n";
	}
}

//////////////////////////////////////////////////////////////

void Bank::searchCustomer()
{
	// Ask for info on who to search and pass that to searchCustomers.
	std::string name;
	std::cout << "\nPlease enter the surname of the customer you would like to search for:> ";
	std::cin >> name;

	int customerExists = searchCustomer(name);

	if (customerExists > -1)
	{
		std::cout << "\nCustomer " << name << " exists on file.\n";
	}
}

//////////////////////////////////////////////////////////////

void Bank::addAccForExistingCustomer()
{
	if (m_customers[m_customerIndex] == nullptr)
	{
		std::cout << "\nThere a zero customers on file.\n";
		return;
	}

	std::string name;
	int customerID;

	std::cout << "\nPlease enter the customers name you wish to open another acc for:> ";
	std::cin >> name;

	for (int i = 0; i < MAX_CUSTOMERS; ++i)
	{
		if (name == m_customers[i]->getName())
		{
			m_customers[i]->openAccount();
			return;
		}
	}

	std::cout << "\nNo customer with the name " << name << " on file.\n";
}

//////////////////////////////////////////////////////////////

void Bank::closeAccForExistingCustomer()
{
	if (m_customers[m_customerIndex] == nullptr)
	{
		std::cout << "\nThere a zero customers on file.\n";
		return;
	}

	std::string name;
	int accNum = 0;

	std::cout << "\nPlease enter the customers name who wishes to close an acc:> ";
	std::cin >> name;

	std::cout << "\nNow please enter the acc num of the account they wish to close:> ";
	std::cin >> accNum;

	for (int i = 0; i < MAX_CUSTOMERS; ++i)
	{
		if (name == m_customers[i]->getName())
		{
			m_customers[i]->closeAccount(accNum);
			return;
		}
	}

	std::cout << "\nNo customer with the name " << name << " on file.\n";
}

//////////////////////////////////////////////////////////////

void Bank::loanApplication()
{
	if (m_customers[m_customerIndex] == nullptr)
	{
		std::cout << "\nThere a zero customers on file.\n";
		return;
	}

	// Get info and pass to loanApplication.
	std::string name;
	int accNum = 0;
	int borrowAmount = 0;
	int currBal = 0;

	std::cout << "\nPlease enter the customers name who is applying for a loan:> ";
	std::cin >> name;

	std::cout << "\nNow please enter the account number of the account to be assesed for loan application:> ";
	std::cin >> accNum;

	std::cout << "\nNow please enter the amount the customer wishes to borrow to:> ";
	std::cin >> borrowAmount;

	for (int i = 0; i < MAX_CUSTOMERS; ++i)
	{
		if (name == m_customers[i]->getName())
		{
			currBal = m_customers[i]->getBalanceFromAcc(accNum);

			if (currBal == 0)
			{
				break;
			}

			if (loanApplication(currBal, borrowAmount))
			{
				m_customers[i]->depositFunds(accNum, borrowAmount);
				return;
			}
		}
	}

	std::cout << "\nNo customer with the name " << name << " on file.\n";
}

//////////////////////////////////////////////////////////////

void Bank::calcInterest()
{
	if (m_customers[m_customerIndex] == nullptr)
	{
		std::cout << "\nThere a zero customers on file.\n";
		return;
	}

	// Get info and pass to calcInterest.
	std::string name;
	int accNum = 0;
	double currBal = 0;
	double interest = 0;

	std::cout << "\nPlease enter the customers name:> ";
	std::cin >> name;

	std::cout << "\nNow please enter the account number of the account they wish to calculate interest on:> ";
	std::cin >> accNum;

	for (int i = 0; i < MAX_CUSTOMERS; ++i)
	{
		if (name == m_customers[i]->getName())
		{
			currBal = m_customers[i]->getBalanceFromAcc(accNum);
			interest = calcInterest(currBal, m_rate);

			if (currBal == 0)
			{
				return;
			}

			std::cout << "\nThe interest on account - " << accNum << " with balance - "
				<< char(156) << currBal << " and with a annual interest rate of - "
				<< (m_rate * 100) << "% is - " << char(156) << interest << '\n';
			return;
		}
	}

	std::cout << "\nNo customer with the name " << name << " on file.\n";
}

//////////////////////////////////////////////////////////////

int Bank::searchCustomer(std::string l_name)
{
	// Search customers based on name.

	for (int i = 0; i < MAX_CUSTOMERS; ++i)
	{
		if (m_customers[i]->getName() == l_name)
		{
			return i;
		}
	}

	std::cout << "\nNo customer on file.\n";

	return -1;
}

//////////////////////////////////////////////////////////////

bool Bank::loanApplication(double l_currBal, int l_borrowAmount)
{
	// Apply for a loan.

	if (l_borrowAmount < (l_currBal * 2))
	{
		std::cout << "\nLoan application sucessfull.\n";
		return true;
	}

	std::cout << "\nYour loan application was unsucessful at this time.\n";
	return false;
}

//////////////////////////////////////////////////////////////

double Bank::calcInterest(double& l_currBal, double& l_rate)
{
	// Calculate interest based on balance and going rate.

	double interest = l_currBal * l_rate;

	return interest;
}

//////////////////////////////////////////////////////////////