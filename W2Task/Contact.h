#pragma once
#include <string>
#include <iostream>
#include <list>
using namespace std;

class Contact
{
private:
	int contactID = -1;
	static int next_contactID;
	int IDinput;

	string address;
	string city;
	string state;
	string zip_code;
	string phone;
public:

	Contact();
	Contact(string address, string city, string state, string phone, string zip_code);
	void initialize();
	void cdisplay() const;
	void display_all(list<Contact>& member_list);

};