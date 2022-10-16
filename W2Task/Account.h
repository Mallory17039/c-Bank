#pragma once
#include "Contact.h"
#include <string>
#include <iostream>
#include <list>
using namespace std;

class Account
{
private:

int IDinput;
string name;
float amount;
float balance;
int accountID = 1;
static int next_ID;
float new_balance;

int choice;
string confirm = "n";

std::shared_ptr<Contact> contact_info;

//constructor
public: 

	Account();

	Account(string name, float balance);

	int get_id() const;

	void find_account(list<Account>& member_list);

	void create_account(list<Account>& member_list);

	void display() const;

	void add_contact(list<Account>& member_list);

	void display_all(list<Account>& member_list);

	float checkbalance();

	float deposit(float amount);

	float withdraw(float amount);
	
	void update_deposit(list<Account>& member_list);

	void update_withdraw(list<Account>& member_list);

	void quit();

	float get_balance() const;

	void update_balance(float new_balance);

};

