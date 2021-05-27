#include <iostream>
#include <fstream>
#include <Windows.h>

#include "AllAccounts.h"
#include "Account.h"
#include "Functions.h"

using namespace std;

AllAccounts::AllAccounts() {
	Account acc;
	fstream file;
	file.open("Account.txt");
	if (!file)
	{
		cout << "Can't open file" << endl;
	}
	while (!file.eof())
	{
		file >> acc;
		accounts.insert(pair<long, Account>(acc.getAccNumber(), acc));
	}
	file.close();
	Account::setAccountNumber(acc.getAccNumber());
}

void AllAccounts::showMap()
{
	map<long, Account>::iterator itr;
	for (itr = accounts.begin(); itr != accounts.end(); itr++)
	{
		cout << itr->first << " " << itr->second << "\n";
	}
}

void AllAccounts::checkIfExist(string login, string pass)
{
	bool logged = false;
	map<long, Account>::iterator itr;
	for (itr = accounts.begin(); itr != accounts.end(); itr++)
	{
		if (login == itr->second.getLogin())
		{
			if (pass == itr->second.getPassword())
			{
				cout << "\033[21;32mSucces!\033[0m\n" << endl;
				Sleep(1000);
				if (itr->second.getIsAdmin())
				{
					AdminMenu();
					logged = true;
				}
				else
				{
					UserMenu(itr->second.getAccNumber());
					logged = true;
				}
			}
			else {
				cout << "\033[21;31mWrong Password!\033[0m\n" << endl;
				Sleep(1000);
				LoginMenu();
			}
		}
	}
	if (logged == false)
	{
		cout << "\033[21;31mThis account doesn't exist!\033[0m\n" << endl;
		Sleep(1000);
		LoginMenu();
	}
}

void AllAccounts::OpenAccount(string accLogin, string accPass, bool adminAcc)
{
	fstream outfile;
	Account account(accLogin, accPass, adminAcc);
	accounts.insert(pair<long, Account>(account.getAccNumber(), account));

	outfile.open("Account.txt");
	map<long, Account>::iterator itr;
	for (itr = accounts.begin(); itr != accounts.end(); itr++)
	{
		outfile << itr->second;
	}
	outfile.close();
}

void AllAccounts::CloseAccount(long accNumb)
{
	if (accounts.find(accNumb) == accounts.end()) {
		cout << "Account not found!" << endl;
		Sleep(2000);
	}
	else {
		map<long, Account>::iterator itr = accounts.find(accNumb);
		cout << itr->second;
		accounts.erase(accNumb);
	}
	ToFile();
}

void AllAccounts::ToFile()
{
	fstream file;
	file.open("Account.txt", std::ofstream::out | std::ofstream::trunc);
	map<long, Account>::iterator itr;
	for (itr = accounts.begin(); itr != accounts.end(); itr++)
	{
		file << itr->second;
	}
	file.close();
}

void AllAccounts::showAcc(long accNumb)
{
	if (accounts.find(accNumb) == accounts.end()) {
		std::cout << "Account not found!" << std::endl;
		Sleep(2000);
	}
	else {
		cout << accounts.find(accNumb)->second;
	}
}

void AllAccounts::ChangePassword(string oldPass, long accNumb)
{
	map<long, Account>::iterator itr = accounts.find(accNumb);
	if (oldPass == itr->second.getPassword())
	{
		string newPass;
		cout << "Enter new password: " << endl;
		cin >> newPass;
		map<long, Account>::iterator itr = accounts.find(accNumb);
		itr->second.setPassword(newPass);
		cout << "\033[21;32mPassword changed\033[0m\n" << endl;
	}
	else {
		cout << "\033[21;31mOld password is incorrect!\033[0m\n" << endl;
	}
	ToFile();
}