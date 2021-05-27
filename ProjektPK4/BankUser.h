/** @file */
#pragma once
#include <iostream>
#include <map>

#include "BankAccount.h"
#include "Bank.h"

using namespace std;

#ifndef _BankUser_H_
#define _BankUser_H_

/**Klasa BankUser zawiera metody do ob³usgi mapy klasy Bank jako user, dziedziczy po klasie Bank*/
class BankUser : public Bank {

public:
	/**Konstruktor bezargumentowy*/
	BankUser();

	/**Metoda accInfo, pokazuje informacje o koncie
	@param accNumber numer konta, na które jesteœmy zalogowani
	@return obiekt BankAccount
	*/
	BankAccount accInfo(long accNumber);

	/**Metoda Deposit typu BankAccount, s³u¿y do dodania œrodków do konta
	@param accNumber numer konta na które u¿ytkownik jest zalogowany
	@param balance kwota, któr¹ chcemy wp³aciæ
	@return zwraca konto do którego wp³aciliœmy pieni¹dze
	*/
	BankAccount Deposit(long accNumber, float balance);

	/**Metoda Withdraw typu BankAccount, s³u¿y do odjêcia œrodków z konta
	@param accNumber numer konta na które u¿ytkownik jest zalogowany
	@param balance kwota, któr¹ chcemy wyp³aciæ
	@return zwraca konto z którego wyp³aciliœmy pieni¹dze
	*/
	BankAccount Withdraw(long accNumber, float balance);

	/**Metoda Transfer s³u¿¹c do przelania œrodków z jednego konta na drugie
	@param sender numer konta osoby zalogowanej, z którego pieni¹dze maj¹ zostaæ pobrane
	@param reciver numer konta osoby, która ma otrzymaæ pieni¹dze
	@param balance kwota, któr¹ chcemy przelaæ
	*/
	void Transfer(long sender, long reciver, float balance);

	/**Metoda pozwalaj¹ca z³o¿yæ wniosek o po¿yczkê*/
	void Loans(long accNumber);
};

#endif 