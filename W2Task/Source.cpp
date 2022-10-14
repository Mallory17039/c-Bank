#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

class BankAccount {
    double Balance = 0.0;
    char ans;
public:struct Name {
    char Last_Name[50];
    char First_Name[50];
    char Middle_Initial[5];
}Name;
public:struct Account {
    char Type[1];
    int Account_Number;
}Account;
public:
    void CreateAccount();
    void Withdraw();
    void Deposit();
    void Display();
    void ShowInfo();
    int Menu();

};

void BankAccount::CreateAccount() {
    do
    {
        cout << "\nEnter account number: ";
        cin >> Account.Account_Number;
        cout << "\nEnter the last name for the account: ";
        cin.ignore();
        cin.getline(Name.Last_Name, 50);
        cout << "\nEnter the first name for the account: ";
        cin.ignore();
        cin.getline(Name.First_Name, 50);
        cout << "\nEnter the Middle initial for the account: ";
        cin.ignore();
        cin.getline(Name.Middle_Initial, 5);
        cout << "\nEnter the type of account (C/S) : ";
        cin >> Account.Type;
        cout << "\nEnter the initial balance of the account: ";
        cin >> Balance;
        cout << "\n\nAccount Created.";
        cout << "\n\nCreate new account? (Y/N) : ";
        cin >> ans;

        while (ans != 'Y' && ans != 'N') {
            cout << "Invalid input. Create new account? (Y/N) : ";
            cin >> ans;
        }
        cout << endl;
    } while (ans != 'N');
};
void BankAccount::Withdraw() {
    int actNum;
    double amount;
    cout << "Enter the account number for the account that you wish to withdraw funds: ";
    cin >> actNum;
    if (actNum == Account.Account_Number) {
        cout << "Enter the amount you would like to withdraw: ";
        cin >> amount;
        Balance = Balance - amount;
    }
    else if (actNum != Account.Account_Number) {
        cout << "No account found under that number! Try again!";
    }

}
void BankAccount::Deposit() {
    int actNum;
    double amount;
    cout << "Enter the account number for the account that you wish to deposit funds: ";
    cin >> actNum;
    if (actNum == Account.Account_Number) {
        cout << "Enter the amount you would like to deposit: ";
        cin >> amount;
        Balance = Balance + amount;
    }
    else if (actNum != Account.Account_Number) {
        cout << "No account found under that number! Try again!";
    }
}
void BankAccount::Display() {
    int actNum;
    cout << "Enter the account number for the account that you wish to display account information for: ";
    cin >> actNum;
    if (actNum == Account.Account_Number) {
        cout << "Account details for " << Name.First_Name << " " << Name.Middle_Initial << " " << Name.Last_Name << "'s account: " << endl;
        cout << "Account Number: " << Account.Account_Number << endl;
        cout << "Account Type (Checking / Savings): " << Account.Type << endl;
        cout << "Account Balance:  $" << Balance << endl;
    }
    else if (actNum != Account.Account_Number) {
        cout << "No account found under that number! Try again!";
    }

}
void BankAccount::ShowInfo() {
    cout << "Account details for " << Name.First_Name << " " << Name.Middle_Initial << " " << Name.Last_Name << "'s account: " << endl;
    cout << "Account Number: " << Account.Account_Number << endl;
    cout << "Account Type (Checking / Savings): " << Account.Type << endl;
    cout << "Account Balance:  $" << Balance << endl;

}

int main(int argc, char* argv) {
    BankAccount ob;
    char ch;

    cout << "Welcome to Console Banking Application V 1.0!";
    cout << "\nSelect an item from the list below by entering the corresponding letter.";
    do {
        cout << "\n\n A. Create Account \n B. Withdraw \n C. Deposit \n D. Show Account Details \n\n Q. Exit Application\n\n";
        ch = ob.Menu();
        switch (ch) {
        case 'A':
        case 'a': ob.CreateAccount();
            ob.ShowInfo();
            break;
        case 'B':
        case 'b': ob.Withdraw();
            break;
        case 'C':
        case 'c': ob.Deposit();
            break;
        case 'D':
        case 'd': ob.Display();
            break;
        case 'Q':
        case 'q': ob.ShowInfo();
            exit(1);
            break;
        }

    } while (1);
}
int BankAccount::Menu() {
    char ch;
    cout << "Select an option: ";
    cin >> ch;
    return ch;
}