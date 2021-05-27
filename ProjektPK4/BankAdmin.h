/** @file */
#pragma once
#include <iostream>
#include <map>

#include "BankAccount.h"
#include "Bank.h"

using namespace std;

#ifndef _BankAdmin_H_
#define _BankAdmin_H_

/**Klasa BankAdmin zawiera metody do ob�usgi mapy klasy Bank jako admin, dziedziczy po klasie Bank*/
class BankAdmin : public Bank {

public:
	/**Konstruktor bezargumentowy*/
	BankAdmin();
	
	/**Metoda OpenAccount, tworzy nowe konto
	@param fname imie, kt�re pos�u�y do utworzenia konta BankAccount
	@param lname nazwisko, kt�re pos�u�y do utworzenia konta BankAccount
	@param balance balans, kt�ry pos�u�y do utworzenia konta BankAccount
	@return zwraca utworzony obiekt BankAccount
	*/
	BankAccount OpenAccount(std::string fname, std::string lname, float balance);

	/**Metoda closeAccount, usuwa konto
	@param accNumber numer konta, kt�re chcemy usun��
	*/
	void closeAccount(long accNumber);

	/**Metoda accInfo, pokazuje informacje o koncie
	@param accNumber numer konta, kt�rego chcemy informacje
	@return obiekt BankAccount
	*/
	BankAccount accInfo(long accNumber);

	/**Metoda Deposit typu BankAccount, s�u�y do dodania �rodk�w do konta
	@param accNumber numer konta do kt�rego chcemy wp�aci� pieni�dze
	@param balance kwota, kt�r� chcemy wp�aci�
	@return zwraca konto do kt�rego wp�acili�my pieni�dze
	*/
	BankAccount Deposit(long accNumber, float balance);

	/**Metoda Withdraw typu BankAccount, s�u�y do odj�cia �rodk�w z konta
	@param accNumber numer konta z kt�rego chcemy wyp�aci� pieni�dze
	@param balance kwota, kt�r� chcemy wyp�aci�
	@return zwraca konto z kt�rego wyp�acili�my pieni�dze
	*/
	BankAccount Withdraw(long accNumber, float balance);

	/**Metoda wypisuje na ekran wszystkie obiekty klasy*/
	void showAccounts();

	/**Metoda obs�uguj�ca wnioski o po�yczk�*/
	void Loans();
};

#endif 