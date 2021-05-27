#include <iostream>
#include <map>
#include <fstream>
#include <Windows.h>

#include "BankAccount.h"
#include "Bank.h"
#include "BankAdmin.h"
#include "Account.h"
#include "AllAccounts.h"
#include "Functions.h"
#include "BankUser.h"

using namespace std;

BankUser::BankUser() : Bank() {}

BankAccount BankUser::accInfo(long accNumber)
{
	BankAccount a;
	a = bank.find(accNumber)->second;
	return a;
}

BankAccount BankUser::Deposit(long accNumber, float balance)
{
	map<long, BankAccount>::iterator itr = bank.find(accNumber);
	itr->second.Deposit(balance);
	return itr->second;
}

BankAccount BankUser::Withdraw(long accNumber, float balance)
{
	map<long, BankAccount>::iterator itr = bank.find(accNumber);
	itr->second.Withdraw(balance);
	return itr->second;
}

void BankUser::Transfer(long sender, long reciver, float balance)
{
	map<long, BankAccount>::iterator itr = bank.find(sender);
	map<long, BankAccount>::iterator itr2 = bank.find(reciver);
	itr->second.Withdraw(balance);
	itr2->second.Deposit(balance);
}

void BankUser::Loans(long accNumber)
{
	map<long, float> loans;
	loans = ReadLoanFromFile<long, float>();
	float balance;
	cout << "Credit application: " << endl;
	cout << "How much do you want to loan?" << endl;
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
			balance = balance * (-1);
		Sleep(1000);
		system("cls");
	}
	loans.insert(pair<long, float>(accNumber, balance));
	cout << "\033[21;32mThe application has been successfully submitted\033[0m\n" << endl;
	SaveMapToFile(loans);
}
