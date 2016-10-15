/* Author: Abuzar Noorali
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
			cout << "Error: Your initial balance cannot be less than 0!" << "\n";	//Display error if user enters negative balance
			accountBalance = 0;
		}

	}
	
	//end constructor

	void setAccountBalance(int balance)
	{
		accountBalance = balance;					//Assign balance to accountBalance variable
	}

	int getAccountBalance() const
	{
		return accountBalance;						//Return accountBalance to main function
	}

	void credit(int cred)
	{
		accountBalance = accountBalance + cred;				//Add credit value to accountBalance
	}

	void debit(int deb)
	{
		if (deb > accountBalance)
		{
			cout << "Debit amount exceeded account balance.\n\n";	//Display error if user tries to withdraw more than what is currently in the account
		}

		if (deb <= accountBalance)
			accountBalance = accountBalance - deb;			//If debit is less than or equal to remaining account balance, subtract debit from accountBalance
	}

private:
	int accountBalance;
}; //end account class

int main()
{
	int balance = 0; 	//hold user starting amount
	int cred = 0; 		//hold user credit addition amount
	int deb = 0; 		//hold user debit subtraction amount

	//First object
	
	cout << "Please enter an initial balance for your bank account: $";
	cin >> balance;
	cout << "\n"; 							//skip a line
	Account account1(balance); 					//Create first object
	
	//Get a credit amount from the user
	
	cout << "Please enter a credit to this account (an addition of funds to the account): $";
	cin >> cred;
	cout << "\n"; 							//skip a line
	
	//Display how much credit was added to the balance
	
	cout << "Credit amount: $" << cred << " added to bank account" << "\n\n";
	account1.credit(cred); 						//pass credit value to credit member function
	
	//display new amount balance after credit has been added
	
	cout << "New account balance: $" << account1.getAccountBalance() << "\n\n"; 

			
	//Second object
	
	cout << "Please enter an initial balance for your bank account: $";	//Get an initial balance from the user
	cin >> balance;
	cout << "\n"; 								//skip a line
	Account account2(balance); 						//Create second object
	
	//Get a debit from the user
	
	cout << "Please enter a debit to this account (a subtraction of funds to the account): $";
	cin >> deb;
	
	account2.debit(deb); 							//pass debit value to debit member function
	
	//display new account balance after debit subtracted
	
	cout << "New account balance: $" << account2.getAccountBalance() << "\n\n"; 


	cout << endl;
	return 0;
}								//end main
