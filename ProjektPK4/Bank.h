/** @file */
#pragma once
#include <iostream>
#include <map>

#include "BankAccount.h"

using namespace std;

#ifndef _Bank_H_
#define _Bank_H_
/**Klasa Bank zawiera mape z wszystkimi utworzonymi kontami bankowymi i metodami obs³uguj¹cymi mape*/
class Bank {
protected:
	map<long, BankAccount> bank; /**< Mapa z kontami bankowymi*/
public:
	/** Konstruktor bezargumentowy*/
	Bank();
	/** Virtualna metoda depozytu œrodków na koncie*/
	virtual BankAccount Deposit(long accNumber, float balance) = 0;
	/** Virtualna metoda wyp³aty œrodków z konta*/
	virtual BankAccount Withdraw(long accNumber, float balance) = 0;
	/** Virtualna metoda pokazuj¹ca informacje o koncie*/
	virtual BankAccount accInfo(long accNumber) = 0;
	/** Metoda ob³usguj¹ca po¿yczki*/
	void Loans();
	/** Metoda s³u¿¹ca zapisania mapy do pliku*/
	void ToFile();
};
#endif 
