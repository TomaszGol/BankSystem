#include <iostream>
#include <map>
#include <fstream>

#include "Bank.h"
#include "BankAccount.h"

using namespace std;

Bank::Bank() {
	BankAccount account;
	fstream file;
	file.open("Bank.txt");
	if (!file)
	{
		cout << "Can't open file" << endl;
	}
	while (!file.eof())
	{
		file >> account;
		bank.insert(pair<long, BankAccount>(account.getAccountNumber(), account));
	}
	file.close();
	BankAccount::setAccountNumber(account.getAccountNumber());
}

void Bank::ToFile() 
{
	fstream file;
	file.open("Bank.txt", std::ofstream::out | std::ofstream::trunc);
	map<long, BankAccount>::iterator itr;
	for (itr = bank.begin(); itr != bank.end(); itr++)
	{
		file << itr->second;
	}
	file.close();
}

void Bank::Loans()
{
	cout << "This is Loans function" << endl;
}