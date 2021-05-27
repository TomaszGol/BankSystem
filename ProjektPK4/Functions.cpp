#include <iostream>
#include <conio.h>
#include <cstdio>
#include <Windows.h>
#include <limits>
#include <regex>

#include "Account.h"
#include "AllAccounts.h"
#include "Functions.h"
#include "Bank.h"
#include "BankAccount.h"
#include "BankAdmin.h"
#include "BankUser.h"

using namespace std;

void LoginMenu()
{
    system("cls");
    string login, password;
    cout << "Hello, Please Log In: " << endl;
    cout << "Login: ";
    cin >> login;
    cout << "Password: ";
    cin >> password;
    AllAccounts a;
    a.checkIfExist(login, password);
}

bool checkWithPattern(string str, regex pattern) {
	if (regex_match(str, pattern)) {
		return true;
	}
	return false;
}

void AdminMenu()
{
    system("cls");
	BankAdmin accounts;
	BankAccount acc;
	AllAccounts a;
    int userChoice;
    string fname, lname, accLogin, accPass;
    float balance;
    long accNumb;
	bool adminAcc;
	regex ptrn("[A-Z]{1}[a-z]{1,15}");
    do {
		cout << "\t\t\t\t1. Open an account" << endl;
		cout << "\t\t\t\t2. Close an account" << endl;
		cout << "\t\t\t\t3. Account information" << endl;
		cout << "\t\t\t\t4. Deposit" << endl;
		cout << "\t\t\t\t5. Withdraw" << endl;
		cout << "\t\t\t\t6. Show accounts" << endl;
		cout << "\t\t\t\t7. Show loans applications" << endl;
		cout << "\t\t\t\t8. Exit" << endl;
		userChoice = _getch();
		switch (userChoice)
		{
		case 49://1
			cout << "=================================================================================================" << endl;
			cout << "\t\t\t\tEnter your name: " << endl;
			cin >> fname;
			if (!checkWithPattern(fname, ptrn)) {
				cout << "Wrong input!" << endl;
				Sleep(1500);
				break;
			}
			cout << "\t\t\t\tEnter your last name: " << endl;
			cin >> lname;
			if (!checkWithPattern(lname, ptrn)) {
				cout << "Wrong input!" << endl;
				Sleep(1500);
				break;
			}
			cout << "\t\t\t\tEnter account ballance: " << endl;
			try {
				cin >> balance;
				if (cin.fail())
					throw -1;
				if (balance < 0)
					throw -2;
			}
			catch (int error)
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				if (error == -1)
					cout << error << " " << "Wrong input" << endl;
				else if(error == -2)
					cout << error << " " << "Negative balance" << endl;
				Sleep(1000);
				system("cls");
				break;
			}
			cout << "\t\t\t\tEnter a login to account: " << endl;
			cin >> accLogin;
			cout << "\t\t\t\tEnter a password: " << endl;
			cin >> accPass;
			cout << "\t\t\t\tEnter whether the account is to be admin or not: " << endl;
			cin >> adminAcc;
			acc = accounts.OpenAccount(fname, lname, balance);
			a.OpenAccount(accLogin, accPass, adminAcc);
			cout << "\t\t\t\033[21;32mAccount is Created\033[0m\n" << endl;
			cout << acc;
			break;
		case 50://2
			cout << "=================================================================================================" << endl;
			cout << "\t\t\tEnter the number of the account you want to close: " << endl;
			cin >> accNumb;
			accounts.closeAccount(accNumb);
			a.CloseAccount(accNumb);
			break;
		case 51://3
			cout << "=================================================================================================" << endl;
			cout << "\t\t\tEnter account number: " << endl;
			cin >> accNumb;
			acc = accounts.accInfo(accNumb);
			cout << "Account details: " << endl;
			cout << acc;
			a.showAcc(accNumb);
			break;
		case 52://4
			cout << "=================================================================================================" << endl;
			cout << "\t\t\tEnter account number: " << endl;
			cin >> accNumb;
			cout << "\t\t\tEnter the ammount you want to deposit: " << endl;
			try {
				cin >> balance;
				if (cin.fail())
					throw -1;
				if (balance < 0)
					throw - 2;
			}
			catch (int error)
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				if (error == -1)
					cout << error << " " << "Wrong input" << endl;
				else if (error == -2)
					cout << error << " " << "Negative balance" << endl;
				Sleep(1000);
				system("cls");
				break;
			}
			acc = accounts.Deposit(accNumb, balance);
			cout << acc;
			break;
		case 53://5
			cout << "=================================================================================================" << endl;
			cout << "\t\t\tEnter account number: " << endl;
			cin >> accNumb;
			cout << "\t\t\tEnter the ammount you want to withdraw: " << endl;
			try {
				cin >> balance;
				if (cin.fail())
					throw - 1;
				if (balance < 0)
					throw - 2;
			}
			catch (int error)
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				if (error == -1)
					cout << error << " " << "Wrong input" << endl;
				else if (error == -2)
					cout << error << " " << "Negative balance" << endl;
				Sleep(1000);
				system("cls");
				break;
			}
			acc = accounts.Withdraw(accNumb, balance);
			cout << acc;
			break;
		case 54://6
			cout << "=================================================================================================" << endl;
			accounts.showAccounts();
			cout << "=================================================================================================" << endl;
			break;
		case 55://7
			cout << "=================================================================================================" << endl;
			accounts.Loans();
			break;
		case 56://8
			system("cls"); break;
		default: system("cls");  break;
		}
    } while (userChoice != 56);
	accounts.ToFile();
	a.ToFile();
}

void UserMenu(long number)
{
	system("cls");
	BankUser accounts;
	BankAccount acc;
	AllAccounts a;
	string oldPass, newPass;
	int userChoice;
	float balance;
	long accNumb;
	do {
		cout << "\t\t\t\t1. Account information" << endl;
		cout << "\t\t\t\t2. Deposit" << endl;
		cout << "\t\t\t\t3. Withdraw" << endl;
		cout << "\t\t\t\t4. Transfer" << endl;
		cout << "\t\t\t\t5. Apply for a loan" << endl;
		cout << "\t\t\t\t6. Change password" << endl;
		cout << "\t\t\t\t7. Exit" << endl;
		userChoice = _getch();
		switch (userChoice)
		{
		case 49://1
			acc = accounts.accInfo(number);
			cout << acc;
			break;
		case 50://2
			cout << "=================================================================================================" << endl;
			cout << "\t\t\tEnter the amount you want to deposit: " << endl;
			try {
				cin >> balance;
				if (cin.fail())
					throw - 1;
				if (balance < 0)
					throw - 2;
			}
			catch (int error)
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				if (error == -1)
					cout << error << " " << "Wrong input" << endl;
				else if (error == -2)
					cout << error << " " << "Negative balance" << endl;
				Sleep(1000);
				system("cls");
				break;
			}
			acc = accounts.Deposit(number, balance);
			cout << acc;
			break;
		case 51://3
			cout << "=================================================================================================" << endl;
			cout << "\t\t\tEnter the amount you want to withdraw: " << endl;
			try {
				cin >> balance;
				if (cin.fail())
					throw - 1;
				if (balance < 0)
					throw - 2;
			}
			catch (int error)
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				if (error == -1)
					cout << error << " " << "Wrong input" << endl;
				else if (error == -2)
					cout << error << " " << "Negative balance" << endl;
				Sleep(1000);
				system("cls");
				break;
			}
			acc = accounts.Withdraw(number, balance);
			cout << acc;
			break;
		case 52://4
			cout << "=================================================================================================" << endl;
			cout << "\t\t\tEnter the amount you want to tranfer: " << endl;
			try {
				cin >> balance;
				if (cin.fail())
					throw - 1;
				if (balance < 0)
					throw - 2;
			}
			catch (int error)
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				if (error == -1)
					cout << error << " " << "Wrong input" << endl;
				else if (error == -2)
					cout << error << " " << "Negative balance" << endl;
				Sleep(1000);
				system("cls");
				break;
			}
			cout << "\t\t\tEnter the account number to which you want to tranfer money: " << endl;
			cin >> accNumb;
			accounts.Transfer(number, accNumb, balance);
			cout << "\033[21;32mMoney transfered\033[0m\n" << endl;
			break;
		case 53://5
			cout << "=================================================================================================" << endl;
			accounts.Loans(number);
			break;
		case 54://6
			cout << "=================================================================================================" << endl;
			cout << "Enter old password: " << endl;
			cin >> oldPass;
			a.ChangePassword(oldPass, number);
			break;
		case 55://7
			system("cls"); break;
		default: system("cls");  break;
		}
	} while (userChoice != 55);
	accounts.ToFile();
	a.ToFile();
}

//template<class T, class Y>
//map<T, Y> ReadLoanFromFile()
//{
//	map <T, Y> contener;
//	fstream file;
//	T a;
//	Y b;
//
//	file.open("Loans.txt");
//	if (!file)
//	{
//		cout << "Can't open file" << endl;
//	}
//	while (!file.eof())
//	{
//		file >> a;
//		file >> b;
//		contener.insert(pair<T, Y>(a, b));
//	}
//	file.close();
//	return contener;
//}

//template<typename Map>
//void SaveMapToFile(const Map& loans)
//template<typename T, typename Y>
//void SaveMapToFile(map<T, Y> loans)
//{
//	fstream file;
//	file.open("Loans.txt", std::ofstream::out | std::ofstream::trunc);
//	typename map<T, Y>::iterator itr;
//	for (itr = loans.begin(); itr != loans.end(); itr++)
//	{
//		file << itr->first;
//		file << itr->second;
//	}
//	file.close();
//}

//void SaveMapToFile2(map<long, float> loans)
//{
//	fstream file;
//	file.open("Loans.txt", std::ofstream::out | std::ofstream::trunc);
//	map<long, float>::iterator itr;
//	for (itr = loans.begin(); itr != loans.end(); itr++)
//	{
//		file << itr->first << endl;
//		file << itr->second << endl;
//	}
//	file.close();
//}