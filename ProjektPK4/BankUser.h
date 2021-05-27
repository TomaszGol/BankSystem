/** @file */
#pragma once
#include <iostream>
#include <map>

#include "BankAccount.h"
#include "Bank.h"

using namespace std;

#ifndef _BankUser_H_
#define _BankUser_H_

/**Klasa BankUser zawiera metody do ob�usgi mapy klasy Bank jako user, dziedziczy po klasie Bank*/
class BankUser : public Bank {

public:
	/**Konstruktor bezargumentowy*/
	BankUser();

	/**Metoda accInfo, pokazuje informacje o koncie
	@param accNumber numer konta, na kt�re jeste�my zalogowani
	@return obiekt BankAccount
	*/
	BankAccount accInfo(long accNumber);

	/**Metoda Deposit typu BankAccount, s�u�y do dodania �rodk�w do konta
	@param accNumber numer konta na kt�re u�ytkownik jest zalogowany
	@param balance kwota, kt�r� chcemy wp�aci�
	@return zwraca konto do kt�rego wp�acili�my pieni�dze
	*/
	BankAccount Deposit(long accNumber, float balance);

	/**Metoda Withdraw typu BankAccount, s�u�y do odj�cia �rodk�w z konta
	@param accNumber numer konta na kt�re u�ytkownik jest zalogowany
	@param balance kwota, kt�r� chcemy wyp�aci�
	@return zwraca konto z kt�rego wyp�acili�my pieni�dze
	*/
	BankAccount Withdraw(long accNumber, float balance);

	/**Metoda Transfer s�u��c do przelania �rodk�w z jednego konta na drugie
	@param sender numer konta osoby zalogowanej, z kt�rego pieni�dze maj� zosta� pobrane
	@param reciver numer konta osoby, kt�ra ma otrzyma� pieni�dze
	@param balance kwota, kt�r� chcemy przela�
	*/
	void Transfer(long sender, long reciver, float balance);

	/**Metoda pozwalaj�ca z�o�y� wniosek o po�yczk�*/
	void Loans(long accNumber);
};

#endif 