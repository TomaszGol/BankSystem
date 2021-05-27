#include <iostream>
#include <fstream>
#include <string>

#include "Account.h"

using namespace std;

long Account::NextAccNumber = 0;

Account::Account() {}

Account::Account(string aLogin, string aPassword, bool admin)
{
	login = aLogin;
	password = aPassword;
	isAdmin = admin;
	NextAccNumber++;
	accNumber = NextAccNumber;
}

std::fstream& operator>>(std::fstream& ifs, Account& acc)
{
	ifs >> acc.accNumber;
	ifs >> acc.login;
	ifs >> acc.password;
	ifs >> acc.isAdmin;
	return ifs;
}

std::fstream& operator<<(std::fstream& outfile, Account& acc)
{
	outfile << acc.getAccNumber() << endl;
	outfile << acc.getLogin() << endl;
	outfile << acc.getPassword() << endl;
	outfile << acc.getIsAdmin() << endl;
	return outfile;
}

std::ostream& operator<<(std::ostream& os, Account& acc)
{
	os << "Account number: " << acc.accNumber << std::endl;
	os << "Login: " << acc.login << std::endl;
	os << "Is Admin: " << acc.isAdmin << std::endl;
	return os;
}