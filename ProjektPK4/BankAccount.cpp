#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip> // do setprcision
#include <Windows.h>

#include "BankAccount.h"
#include "BankAdmin.h"
#include "Bank.h"

using namespace std;

long BankAccount::NextAccountNumber = 0;

BankAccount::BankAccount() {}

BankAccount::BankAccount(std::string fname, std::string lname, float accbalance)
{
	name = fname;
	lastName = lname;
	balance = accbalance;
	NextAccountNumber++;
	accountNumber = NextAccountNumber;
}

void BankAccount::Deposit(float ammount)
{
	balance = balance + ammount;
	cout << "\033[21;32mSuccessfully deposited money\033[0m\n" << endl;
	Sleep(1500);
}

void BankAccount::Withdraw(float ammount)
{
	try {

		if (balance - ammount < 0) {
			throw -2;
		}
		else {
			balance = balance - ammount;
			cout << "\033[21;32mSuccessfully withdrawed money!\033[0m\n" << endl;
			Sleep(1500);
		}
	} catch (int e) {
		cout << e <<"\033[21;31mYou can't withdraw that ammount of money!\033[0m\n" << endl;
		Sleep(1500);
	}	
}

std::fstream& operator>>(std::fstream& infile, BankAccount& acc) // przeczytanie z pliku
{

	infile >> acc.name;
	infile >> acc.lastName;
	infile >> acc.accountNumber;
	infile >> std::fixed >> std::setprecision(2);
	infile >> acc.balance;
	return infile;
}
std::fstream& operator<<(std::fstream& outfile, BankAccount& acc) // wpisanie do pliku
{
	outfile << "\n" << acc.getName() << std::endl;
	outfile << acc.getLastName() << std::endl;
	outfile << acc.getAccountNumber() << std::endl;
	outfile << acc.getBalance();
	return outfile;
}
std::ostream& operator<<(std::ostream& os, BankAccount& acc) // wypisanie na ekran
{
	os << "Account number: " << acc.accountNumber << std::endl;
	os << "First name: " << acc.name << std::endl;
	os << "Last Name: " << acc.lastName << std::endl;
	os << std::fixed << std::setprecision(2);
	os << "Balance: " << acc.balance << std::endl;
	return os;
}