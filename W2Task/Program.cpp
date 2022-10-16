// W2Task.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Account.h"
#include <list>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	Account acc;
	int choice;
	string name;
	//int accountID;
	//float balance;
	//float amount;
	list<Account> members;
	int IDinput;

	do
	{
		cout << "\n";
		cout << "===================================================== \n";
		cout << " \t\t ACCOUNT MENU \t \n ";
		cout << "==================================================== \n";
		cout << " 0. Quit Program \n";
		cout << " 1. Display Account Information\n";
		cout << " 2. Add a deposit to an account\n";
		cout << " 3. Withdraw from an account\n";
		cout << " 4. Add new account\n";
		cout << " 5. Find account by ID\n";
		cout << " 6. Remove account\n";
		cout << " 7. Show total balance for all accounts\n";
		cout << " 8. Add a dividend to all accounts\n";
		cout << " 9. Add contact information to an account\n";
		cout << "Your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			// acc.display_all(members);
			for_each(members.begin(), members.end(),
				[](auto& acc) {
					acc.display();
				}
			);
			break;
		case 2:
			acc.update_deposit(members);
			break;
		case 3:
			acc.update_withdraw(members);
			break;
		case 4:
			acc.create_account(members);
			break;
		case 5:
			acc.find_account(members);
			break;
		case 6:
		{	//remove account
			float remove_id;
			cout << "Enter account ID to remove: ";
			cin >> remove_id;
			auto new_end = remove_if(members.begin(), members.end(), [remove_id](auto& acc) {
				return acc.get_id() == remove_id;
				}
			);
			members.erase(new_end, members.end());
			break;
		}
		case 7:
		{	// total balance for all accounts
			float total_balance = accumulate(members.begin(), members.end(), 0.0f,
				[](auto accumulator, auto& acc) {
					return accumulator + acc.get_balance();
				}
			);
			cout << "Total Balance: " << total_balance << endl;
			break;
		}
		case 8:
		{	
			float dividend;
			cout << "Enter the vididend as a percentage (%): ";
			cin >> dividend;
			dividend = 0.01 * dividend;
			transform(members.begin(), members.end(), members.begin(),
				[dividend](auto& acc) {
					acc.update_balance(acc.get_balance() + (acc.get_balance() * dividend));
					return acc;
				}
			);
			break;
		}
		case 9:
			// add contact info
			acc.add_contact(members);
			break;
		case 0:
			acc.quit();
			break;
		}
	} while (choice != 0);
	return 0;
}

