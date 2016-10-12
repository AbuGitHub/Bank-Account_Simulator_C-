/*  Abuzar Noorali
Assignment: 2, Ch 3.12
Due Date: 09/23/2016
Purpose/Description: This program recieves an initial balance for a bank account and then credits and debits to that account and displays the final account balance.
*/
#include <iostream>
using namespace std;

class Account
{
public:
	//constructor
	explicit Account(int balance)
		: accountBalance(balance)
	{
		if (accountBalance < 0)
		{
			cout << "Error: Your initial balance cannot be less than 0!" << "\n";
			accountBalance = 0;
		}

	}//end constructor

	void setAccountBalance(int balance)
	{
		accountBalance = balance;
	}

	int getAccountBalance() const
	{
		return accountBalance;
	}

	void credit(int cred)
	{
		accountBalance = accountBalance + cred;
	}

	void debit(int deb)
	{
		if (deb > accountBalance)
		{
			cout << "Debit amount exceeded account balance.\n\n";
		}

		if (deb <= accountBalance)
			accountBalance = accountBalance - deb;
	}

private:
	int accountBalance;
}; //end account class

int main()
{
	int balance = 0; //hold user starting amount
	int cred = 0; //hold user credit addition amount
	int deb = 0; //hold user debit subtraction amount

				 //First object
	cout << "Please enter an initial balance for your bank account: $";
	cin >> balance;
	cout << "\n"; //skip a line
	Account account1(balance); //Create first object
	cout << "Please enter a credit to this account (an addition of funds to the account): $";
	cin >> cred;
	cout << "\n"; //skip a line
	cout << "Credit amount: $" << cred << " added to bank account" << "\n\n";
	account1.credit(cred); //pass credit value to credit member function
	cout << "New account balance: $" << account1.getAccountBalance() << "\n\n"; //display account balance after credit added

																				//Second object
	cout << "Please enter an initial balance for your bank account: $";
	cin >> balance;
	cout << "\n"; //skip a line
	Account account2(balance); //Create second object
	cout << "Please enter a debit to this account (a subtraction of funds to the account): $";
	cin >> deb;
	account2.debit(deb); //pass debit value to debit member function
	cout << "New account balance: $" << account2.getAccountBalance() << "\n\n"; //display account balance after debit added



	return 0;
}//end main