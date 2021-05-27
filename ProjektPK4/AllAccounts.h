/** @file */
#pragma once
#include <map>
#include <fstream>
#include "Account.h"

#ifndef _AllAccounts_H_
#define _AllAccounts_H_

using namespace std;

/**Klasa AllAccount zawiera mape z wszystkimi utworzonymi kontami i metodami obs³uguj¹cymi mape*/
class AllAccounts {
private:
	map<long, Account> accounts; /**< Mapa z wszystkimi kontami klasy Account*/
public:
	/**Konstruktor bezargumentowy */
	AllAccounts();

	/**Matoda s³u¿¹ca do wypsania calej mapy */
	void showMap();

	/**Meotda void s³u¿¹ca do sprawdzenia czy konto wprowadzone przez uzytkownika istnieje.
	@param login login wprowadzony przez uzytkownika
	@param pass haslo wprowadzone przez uzytkownika
	*/
	void checkIfExist(string login, string pass);

	/**Meotda void s³u¿¹ca do utworzenia nowego konta
	@param accLogin login wprowadzony przez uzytkownika
	@param accPpass haslo wprowadzone przez uzytkownika
	@param adminAcc zmienna bool informujaca czy konto ma byc adminem
	*/
	void OpenAccount(string accLogin, string accPass, bool adminAcc);

	/**Meotda void s³u¿¹ca do usuniêcia konta
	@param accNumb numer konta, które ma zostac usuniête
	*/
	void CloseAccount(long accNumb);

	/**Meotda void s³u¿¹ca do zapisania mapy do pliku
	*/
	void ToFile();

	/**Meotda void s³u¿¹ca do pokazania informacji o konkretnym koncie
	@param accNumb numer konta
	*/
	void showAcc(long accNumb);

	/**Meotda void s³u¿¹ca do zmienienia has³a konta
	@param newPass nowe haslo
	@param accNumb numer konta, którego has³o chcemy zmieniæ
	*/
	void ChangePassword(string newPass, long accNumb);
};
#endif