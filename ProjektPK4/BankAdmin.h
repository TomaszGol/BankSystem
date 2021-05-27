/** @file */
#pragma once
#include <iostream>
#include <map>

#include "BankAccount.h"
#include "Bank.h"

using namespace std;

#ifndef _BankAdmin_H_
#define _BankAdmin_H_

/**Klasa BankAdmin zawiera metody do ob³usgi mapy klasy Bank jako admin, dziedziczy po klasie Bank*/
class BankAdmin : public Bank {

public:
	/**Konstruktor bezargumentowy*/
	BankAdmin();
	
	/**Metoda OpenAccount, tworzy nowe konto
	@param fname imie, które pos³u¿y do utworzenia konta BankAccount
	@param lname nazwisko, które pos³u¿y do utworzenia konta BankAccount
	@param balance balans, który pos³u¿y do utworzenia konta BankAccount
	@return zwraca utworzony obiekt BankAccount
	*/
	BankAccount OpenAccount(std::string fname, std::string lname, float balance);

	/**Metoda closeAccount, usuwa konto
	@param accNumber numer konta, które chcemy usun¹æ
	*/
	void closeAccount(long accNumber);

	/**Metoda accInfo, pokazuje informacje o koncie
	@param accNumber numer konta, którego chcemy informacje
	@return obiekt BankAccount
	*/
	BankAccount accInfo(long accNumber);

	/**Metoda Deposit typu BankAccount, s³u¿y do dodania œrodków do konta
	@param accNumber numer konta do którego chcemy wp³aciæ pieni¹dze
	@param balance kwota, któr¹ chcemy wp³aciæ
	@return zwraca konto do którego wp³aciliœmy pieni¹dze
	*/
	BankAccount Deposit(long accNumber, float balance);

	/**Metoda Withdraw typu BankAccount, s³u¿y do odjêcia œrodków z konta
	@param accNumber numer konta z którego chcemy wyp³aciæ pieni¹dze
	@param balance kwota, któr¹ chcemy wyp³aciæ
	@return zwraca konto z którego wyp³aciliœmy pieni¹dze
	*/
	BankAccount Withdraw(long accNumber, float balance);

	/**Metoda wypisuje na ekran wszystkie obiekty klasy*/
	void showAccounts();

	/**Metoda obs³uguj¹ca wnioski o po¿yczkê*/
	void Loans();
};

#endif 