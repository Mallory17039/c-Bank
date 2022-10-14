#include "Account.h"
#include "Contact.h"
#include <iostream>
#include <list>
// transform, remove_if, for_each functions
#include <algorithm>

int Account::next_ID = 0;

Account::Account(): name(""), balance(0), accountID(next_ID++), contact_info(nullptr)
{
}

Account::Account(string name, float balance) :
	name(name), balance(balance), accountID(next_ID++), contact_info(nullptr)
{
}

void Account::create_account(list<Account>& member_list) {
	cout << "Enter the name: ";
	cin >> name;
	cout << "Enter the balance: ";
	cin >> balance;
	cout << "Account Created.";
	accountID += next_ID;

	Account account{ name, balance };

	member_list.push_back(account);
}

void Account::display() const
{
	cout << "Account ID: " << accountID << " Name: " << name << " Balance: $" << balance << endl;
	if (contact_info != nullptr)
	{
		contact_info->cdisplay();
	}
}

list<Account>::iterator find_ID(list<Account>& member_list, int accountID) {
	list<Account>::iterator it;
	for (it = member_list.begin(); it != member_list.end(); it++)
	{
		if (it->get_id() == accountID)
		{
			return it;
		}
	}
	return it;
}

void Account::add_contact() {
	contact_info = std::make_shared<Contact>();
	contact_info->initialize();
}

void Account::display_all(list<Account>& member_list) {
	 list<Account>::iterator it;
	for (it = member_list.begin(); it != member_list.end(); it++)
	{
		it->display();
	}

}

int Account::get_id() const {
	return accountID;
}

void Account::find_account(list<Account>& member_list) {
	cout << "Enter and ID to search for: ";
	cin >> accountID;
	list<Account>::iterator it;
	it = find_ID(member_list, accountID);

	if (it != member_list.end()) {
		// found a member with that ID
		cout << "*** Found the ID ***" << endl;
		it->display();
	}
	else {
		cout << "*** Can't find the ID *** " << endl;
	}
}

float Account::checkbalance()
{
	return balance;
}

float Account::deposit(float amount)
{
	balance += amount;
	return balance;
}

float Account::withdraw(float amount)
{
	balance -= amount;
	return balance;
}

void Account::update_deposit(list<Account>& member_list) {
	cout << "Enter and ID to search for: ";
	cin >> accountID;
	list<Account>::iterator it;
	it = find_ID(member_list, accountID);

	if (it != member_list.end()) {
		// found a member with that ID
		cout << "*** Found the ID ***" << endl;
		it->display();
		cout << "Enter the amount to deposit: ";
		cin >> amount;
		it->deposit(amount);
	
	}
	else {
		cout << "*** Can't find the ID *** " << endl;
	}
}

void Account::update_withdraw(list<Account>& member_list) {
	cout << "Enter and ID to search for: ";
	cin >> accountID;
	list<Account>::iterator it;
	it = find_ID(member_list, accountID);

	if (it != member_list.end()) {
		// found a member with that ID
		cout << "*** Found the ID ***" << endl;
		it->display();
		cout << "Enter the amount to deposit: ";
		cin >> amount;
		it->withdraw(amount);

	}
	else {
		cout << "*** Can't find the ID *** " << endl;
	}
}


void Account::quit()
{
	cout << "*** You have selected quit program ***";
}

// Return Account's deposit
float Account::get_balance() const {
	return balance;
}

// Update balance
void Account::update_balance(float new_balance) {
	balance = new_balance;
}