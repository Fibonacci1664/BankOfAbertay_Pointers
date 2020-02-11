// INCLUDES.
#include "Customer.h"

//////////////////////////////////////////////////////////////

// CONSTRUCTORS / DESTRUCTOR.
Customer::Customer(std::string l_name, int l_customerID) :
	m_name(l_name), m_customerID(l_customerID)
{
	// Initialize all elements in the dynamically created array of pointers to NULL.
	for (int i = 0; i < MAX_ACCOUNTS; ++i)
	{
		m_accounts[i] = nullptr;
	}

	m_index = 0;
}

//////////////////////////////////////////////////////////////

Customer::~Customer()
{
	std::cout << "Customer object destroyed!\n";
}

//////////////////////////////////////////////////////////////

// MEMBER FUNCTIONS.
bool Customer::login(std::string l_name, int l_customerID)
{
	if (l_name == m_name && l_customerID == m_customerID)
	{
		return true;
	}

	return false;
}

//////////////////////////////////////////////////////////////

Account Customer::searchAccounts(int& accNum)
{
	if (m_accounts[m_index] == nullptr)
	{
		std::cout << "\nYou currently have no accounts with the bank.\n";
		return *m_accounts[m_index];
	}

	std::cout << "\nSearching Your Personal Accounts...\n";

	for (int i = 0; i < MAX_ACCOUNTS; ++i)
	{
		if (m_accounts[i]->getAccNum() == accNum)
		{
			std::cout << "\nAccount exists.\n";
			std::cout << '\n';
			return *m_accounts[i];
		}
	}

	std::cout << "\nAccount not found.\n";
}

//////////////////////////////////////////////////////////////

int Customer::searchAccounts()
{
	if (m_accounts[m_index] == nullptr)
	{
		std::cout << "\nYou currently have no accounts with the bank.\n";
		return -1;
	}

	int accNum = 0;
	std::cout << "\nPlease enter the acc number you wish to search for:> ";

	std::cin >> accNum;

	std::cout << "\nSearching Your Personal Accounts...\n";

	for (int i = 0; i < MAX_ACCOUNTS; ++i)
	{
		if (m_accounts[i]->getAccNum() == accNum)
		{
			std::cout << "\nAccount exists.\n";
			std::cout << '\n';
			return 0;
		}
	}

	std::cout << "\nAccount not found.\n";
	return -1;
}

//////////////////////////////////////////////////////////////

void Customer::depositFunds()
{
	if (m_accounts[m_index] == nullptr)
	{
		std::cout << "\nYou currently have no accounts with the bank.\n";
		return;
	}

	int accNum;
	std::cout << "\nPlease enter the acc number you wish to deposit to:> ";
	std::cin >> accNum;

	double depositAmount;
	std::cout << "\nPlease enter the amount you wish to deposit:> ";
	std::cin >> depositAmount;

	for (int i = 0; i < MAX_ACCOUNTS; ++i)
	{
		if (m_accounts[i]->getAccNum() == accNum)
		{
			std::cout << "\n" << char(156) << depositAmount << " has been deposited.\n";
			std::cout << '\n';

			m_accounts[i]->depositFunds(depositAmount);
			break;
		}
	}
}

//////////////////////////////////////////////////////////////

// A seperate deposit funds function specifically for depositing any loan amounts.
void Customer::depositFunds(int accNum, int loanAmount)
{
	if (m_accounts[m_index] == nullptr)
	{
		std::cout << "\nYou currently have no accounts with the bank.\n";
		return;
	}

	for (int i = 0; i < MAX_ACCOUNTS; ++i)
	{
		if (accNum == m_accounts[i]->getAccNum())
		{
			m_accounts[i]->depositFunds(loanAmount);
			break;
		}
	}
}

//////////////////////////////////////////////////////////////

void Customer::withdrawFunds()
{
	if (m_accounts[m_index] == nullptr)
	{
		std::cout << "\nYou currently have no accounts with the bank.\n";
		return;
	}

	int accNum;
	std::cout << "\nPlease enter the acc number you wish to withdraw from:> ";
	std::cin >> accNum;

	double withdrawAmount;
	std::cout << "\nPlease enter the amount you wish to withdraw:> ";
	std::cin >> withdrawAmount;

	for (int i = 0; i < MAX_ACCOUNTS; ++i)
	{
		if (m_accounts[i]->getAccNum() == accNum)
		{
			std::cout << "\n" << char(156) << withdrawAmount << " has been withdrawn from your account.\n";
			std::cout << '\n';

			m_accounts[i]->withdrawFunds(withdrawAmount);
			break;
		}
	}
}

//////////////////////////////////////////////////////////////

void Customer::checkBalance()
{
	if (m_accounts[m_index] == nullptr)
	{
		std::cout << "\nYou currently have no accounts with the bank.\n";
		return;
	}

	int accNum;
	std::cout << "\nPlease enter the acc number you wish to check the balance on:> ";
	std::cin >> accNum;

	for (int i = 0; i < MAX_ACCOUNTS; ++i)
	{
		if (m_accounts[i]->getAccNum() == accNum)
		{
			std::cout << '\n';

			m_accounts[i]->checkBalance();
			break;
		}
	}
}

//////////////////////////////////////////////////////////////

void Customer::openAccount()
{
	int count = 0;

	for (int i = 0; i < MAX_ACCOUNTS; ++i)
	{
		if (m_accounts[i] != nullptr)
		{
			++count;

			if (count == 3)
			{
				std::cout << "\nYou cannot create anymore than three accounts.\n";
				return;
			}
		}
	}

	int accNum = rand() % 1000000 + 1;
	double openingBal = 0;

	do
	{
		std::cout << "\nHow much would you like to open the account with:> ";
		std::cin >> openingBal;
	} while (openingBal == 0);

	for (int i = 0; i < MAX_ACCOUNTS; ++i)
	{
		if (m_accounts[i] == nullptr)
		{
			m_accounts[i] = new Account(m_name, accNum, openingBal);
			m_index = i;
			break;
		}
	}


	//m_accounts.push_back(Account(m_name, accNum, openingBal));

	std::cout << "\nA new account has now been opened, your account number is " << accNum << '\n';
	std::cout << "\n******************** IMPORTANT **********************\n";
	std::cout << "********** PLEASE NOTE YOUR ACCOUNT NUMBER **********\n";
	std::cout << '\n';
}

//////////////////////////////////////////////////////////////

void Customer::closeAccount(int& accNum)
{
	for (int i = 0; i < MAX_ACCOUNTS; ++i)
	{
		if (m_accounts[i]->getAccNum() == accNum)
		{
			delete m_accounts[i];
			m_accounts[i] = nullptr;

			std::cout << "\nAccount " << accNum << " erased.\n";
			return;
		}
	}

	std::cout << "\nAccount not found.\n";
}

//////////////////////////////////////////////////////////////

void Customer::listAllAccounts()
{
	if (m_accounts[m_index] == nullptr)
	{
		std::cout << "\nYou currently have no accounts with the bank.\n";
		return;
	}	

	for (int i = 0; i < MAX_ACCOUNTS; ++i)
	{
		if (m_accounts[i] == nullptr)
		{
			break;
		}

		std::cout << "\nAccount num " << (i + 1) << " = " << m_accounts[i]->getAccNum()
			<< " - Current Balance = " << char(156) << m_accounts[i]->getBalance() << '\n';
	}
}

//////////////////////////////////////////////////////////////

// GETTERS & SETTERS.
int Customer::getIndex()
{
	return m_index;
}

//////////////////////////////////////////////////////////////

void Customer::setIndex(int l_indexPos)
{
	m_index = l_indexPos;
}

//////////////////////////////////////////////////////////////

std::string Customer::getName()
{
	return m_name;
}

//////////////////////////////////////////////////////////////

void Customer::setName(std::string l_name)
{
	m_name = l_name;
}

//////////////////////////////////////////////////////////////

int Customer::getAccNum(int indexPos)
{
	return m_accounts[indexPos]->getAccNum();
}

//////////////////////////////////////////////////////////////

double Customer::getBalanceFromAcc(int accNum)
{
	if (m_accounts[m_index] == nullptr)
	{
		std::cout << "\nYou currently have no accounts with the bank.\n";
		return 0;
	}

	for (int i = 0; i < MAX_ACCOUNTS; ++i)
	{
		if (m_accounts[i]->getAccNum() == accNum)
		{
			return m_accounts[i]->getBalance();
		}
	}

	return 0;
}

//////////////////////////////////////////////////////////////