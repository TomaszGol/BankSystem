/** @file */
#pragma once
#include <iostream>
#include <string>

#ifndef _Account_H_
#define _Account_H_

using namespace std;

/**Klasa Account zawiera wszystkie informacje o koncie*/
class Account {
private:

	long accNumber; /**< Zmienna long zawieraj�ca numer konta*/
	string login; /**< Zmienna string zawieraj�ca login do konta*/
	string password; /**< Zmienna string zawieraj�ca has�o do konta*/
	bool isAdmin; /**< Zmienna bool zawieraj�ca informacje czy konto jest adminem lub zwyk�ym u�ytkownikiem*/
	static long NextAccNumber; /**< zmienna statyczna zawieraj�ca numer nast�pnego konta*/
public:
	/**Konstruktor bezargumentowy*/
	Account();

	/**Konstruktor argumentowy, ustawiaj�cy dane konta*/
	Account(string aLogin, string aPassword, bool admin);

	/**Metoda getAccNumber zwraca numer konta
	@return numer konta
	*/
	long getAccNumber() { return accNumber; }

	/**Metoda getLogin zwraca login
	@return login konta
	*/
	string getLogin() { return login; }

	/**Metoda getPassword zwraca haslo
	@return haslo konta
	*/
	string getPassword() { return password; }

	/**Metoda getisAdmin zwraca zmienna typu bool zawierajac� informacj� o typie konta
	@return isAdmin
	*/
	bool getIsAdmin() { return isAdmin; }

	/**Metoda setPassword ustawiwa has�o
	@param newPass nowe haslo
	*/
	void setPassword(string newPass) { password = newPass; }

	/**Metoda statyczna getLastAccountNumber zwraca numer nast�pnego konta
	@return zwraca nast�pny numer konta
	*/
	static long getLastAccountNumber() { return NextAccNumber; }

	/**Metoda statyczna setAccountNumber ustawia zmienn� NextAccountNumber na aktualny numer
	@param accountNumber numer konta
	*/
	static void setAccountNumber(long accountNumber) { NextAccNumber = accountNumber; }

	/**Zaprzyja�niony operator prze�adowania u�atwiaj�cy czytanie danych z pliku
	@param &ifs �r�d�o strumienia pliku
	@param &acc obiekt klasy do kt�rego wpisujemy z pliku
	*/
	friend std::fstream& operator>>(std::fstream& ifs, Account& acc);

	/**Zaprzyja�niony operator prze�adowania u�atwiaj�cy wpisanie danych do pliku
	@param &outfile �r�d�o strumienia pliku
	@param &acc obiekt klasy wpisywany do pliku
	*/
	friend std::fstream& operator<<(std::fstream& outfile, Account& acc);

	/**Zaprzyja�niony operator prze�adowania u�atwiaj�cy wypisywanie obiektu na ekran
	@param &os �r�d�o strumienia wypisania
	@param &acc obiekt klasy, kt�ry chcemy wypisa�
	*/
	friend std::ostream& operator<<(std::ostream& os, Account& acc);
};
#endif