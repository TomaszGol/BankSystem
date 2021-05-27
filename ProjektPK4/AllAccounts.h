/** @file */
#pragma once
#include <map>
#include <fstream>
#include "Account.h"

#ifndef _AllAccounts_H_
#define _AllAccounts_H_

using namespace std;

/**Klasa AllAccount zawiera mape z wszystkimi utworzonymi kontami i metodami obs�uguj�cymi mape*/
class AllAccounts {
private:
	map<long, Account> accounts; /**< Mapa z wszystkimi kontami klasy Account*/
public:
	/**Konstruktor bezargumentowy */
	AllAccounts();

	/**Matoda s�u��ca do wypsania calej mapy */
	void showMap();

	/**Meotda void s�u��ca do sprawdzenia czy konto wprowadzone przez uzytkownika istnieje.
	@param login login wprowadzony przez uzytkownika
	@param pass haslo wprowadzone przez uzytkownika
	*/
	void checkIfExist(string login, string pass);

	/**Meotda void s�u��ca do utworzenia nowego konta
	@param accLogin login wprowadzony przez uzytkownika
	@param accPpass haslo wprowadzone przez uzytkownika
	@param adminAcc zmienna bool informujaca czy konto ma byc adminem
	*/
	void OpenAccount(string accLogin, string accPass, bool adminAcc);

	/**Meotda void s�u��ca do usuni�cia konta
	@param accNumb numer konta, kt�re ma zostac usuni�te
	*/
	void CloseAccount(long accNumb);

	/**Meotda void s�u��ca do zapisania mapy do pliku
	*/
	void ToFile();

	/**Meotda void s�u��ca do pokazania informacji o konkretnym koncie
	@param accNumb numer konta
	*/
	void showAcc(long accNumb);

	/**Meotda void s�u��ca do zmienienia has�a konta
	@param newPass nowe haslo
	@param accNumb numer konta, kt�rego has�o chcemy zmieni�
	*/
	void ChangePassword(string newPass, long accNumb);
};
#endif