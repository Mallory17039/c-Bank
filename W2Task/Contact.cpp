#include "Contact.h"
#include "Account.h"
#include <iostream>
#include <list>
#include <algorithm>

int Contact::next_contactID = 0;

Contact::Contact() : address(""), city(""), state(""), phone(""),zip_code(""), contactID(next_contactID++)
{
}

Contact::Contact(string address, string city, string state, string phone, string zip_code) :
	address(address), city(city), phone(phone), zip_code(zip_code), contactID(next_contactID++)
{
}

//input method
void Contact::initialize() {
	cout << "Enter Address: ";
	cin >> address;
	cout << "Enter City: ";
	cin >> city;
	cout << "Enter State: ";
	cin >> state;
	cout << "Enter Zip Code: ";
	cin >> zip_code;
	cout << "Enter Phone Number: ";
	cin >> phone;
	cout << "Contact Created.";
	contactID =+ contactID;
}

//output method
void Contact::cdisplay() const
{
	cout <<"+ Contact Information: "<< "Address: " << address << " City: " << city << " State: " << state <<" Zip: "<< zip_code<< " Phone: "<< phone << endl;
}

void Contact::display_all(list<Contact>& member_list) {
	list<Contact>::iterator it;
	for (it = member_list.begin(); it != member_list.end(); it++)
	{
		it->cdisplay();
	}
}