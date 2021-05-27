#include <iostream>
#include <map>
#include <fstream>
#include <Windows.h>
#include <regex>

#include "BankAccount.h"
#include "Bank.h"
#include "BankAdmin.h"
#include "Account.h"
#include "AllAccounts.h"
#include "Functions.h"
#include "BankUser.h"

using namespace std;

BankAdmin::BankAdmin() : Bank() {}

BankAccount BankAdmin::OpenAccount(string fname, string lname, float balance)
{
	fstream outfile;
	BankAccount account(fname, lname, balance);
	bank.insert(pair<long, BankAccount>(account.getAccountNumber(), account));

	outfile.open("Bank.txt");
	map<long, BankAccount>::iterator itr;
	for (itr = bank.begin(); itr != bank.end(); itr++)
	{
		outfile << itr->second;
	}
	outfile.close();
	return account;
}

void BankAdmin::closeAccount(long accNumber)
{
	if (bank.find(accNumber) == bank.end()) {
		cout << "\033[21;31mAccount not found!!\033[0m\n" << endl;
		Sleep(2000);
	}
	else {
		map<long, BankAccount>::iterator itr = bank.find(accNumber);
		cout << "\033[21;32mAccount Deleted\033[0m\n" << endl << itr->second;
		bank.erase(accNumber);
		ToFile();
	}
}	

BankAccount BankAdmin::accInfo(long accNumber)
{
	BankAccount a;
	if (bank.find(accNumber) == bank.end()) {
		cout << "\033[21;31mAccount not found!!\033[0m\n" << endl;
		Sleep(2000);
		cout << "Account with the highest number: " << endl;
		return bank.rbegin()->second;
	}
	else {
		a = bank.find(accNumber)->second;
		return a;
	}
}

BankAccount BankAdmin::Deposit(long accNumber, float balance)
{
	if (bank.find(accNumber) == bank.end()) {
		cout << "\033[21;31mAccount not found!!\033[0m\n" << endl;
		Sleep(2000);
		//AdminMenu();
		cout << "Account with the highest number: " << endl;
		return bank.rbegin()->second;
	} else {
		map<long, BankAccount>::iterator itr = bank.find(accNumber);
		itr->second.Deposit(balance);
		ToFile();
		return itr->second;
	}
}

BankAccount BankAdmin::Withdraw(long accNumber, float balance)
{
	if (bank.find(accNumber) == bank.end()) {
		cout << "\033[21;31mAccount not found!!\033[0m\n" << endl;
		Sleep(2000);
		cout << "Account with the highest number: " << endl;
		return bank.rbegin()->second;
	}
	else {
		map<long, BankAccount>::iterator itr = bank.find(accNumber);
		itr->second.Withdraw(balance);
		ToFile();
		return itr->second;
	}
}

void BankAdmin::showAccounts()
{
	map<long, BankAccount>::iterator itr;
	for (itr = bank.begin(); itr != bank.end(); itr++)
	{
		cout << itr->second << "\n";
	}
}

void BankAdmin::Loans()
{
	map<long, float> loans;
	loans = ReadLoanFromFile<long, float>();
	BankAccount acc;
	map<long, float>::iterator itr;
	map<long, BankAccount>::iterator itr2;
	map<long, BankAccount>::iterator itr3;
	long accNumb;
	int choice;
	float balance;
	for (itr = loans.begin(); itr != loans.end(); )
	{
		accNumb = itr->first;
		acc = bank.find(accNumb)->second;
		balance = itr->second;
		cout << "*************************************************************************************************" << endl;
		cout << "Loan form: " << endl;
		cout << acc;
		cout << "Expected loan amount: " << itr->second << endl;
		cout << "\n";
		cout << "1. Accept\t\t2. Reject\t\t3. Skip" << endl;
		cout << "\n";
		choice = _getch();
		switch (choice)
		{
			case 49://1
				itr2 = bank.find(1);
				itr3 = bank.find(accNumb);
				itr2->second.Withdraw(balance);
				itr3->second.Deposit(balance);
				cout << "\033[21;32mSuccessful transaction\033[0m\n" << endl;
				loans.erase(itr++);
				break;
			case 50://2
				cout << "Application was rejected" << endl;
				loans.erase(itr++);
				break;
			case 51://3
				++itr;
				break;
			default: break;
		}
		//SaveMapToFile<long, float>(loans);
		SaveMapToFile(loans);
	}
	system("cls");
}