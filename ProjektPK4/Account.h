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

	long accNumber; /**< Zmienna long zawierająca numer konta*/
	string login; /**< Zmienna string zawierająca login do konta*/
	string password; /**< Zmienna string zawierająca hasło do konta*/
	bool isAdmin; /**< Zmienna bool zawierająca informacje czy konto jest adminem lub zwykłym użytkownikiem*/
	static long NextAccNumber; /**< zmienna statyczna zawierająca numer następnego konta*/
public:
	/**Konstruktor bezargumentowy*/
	Account();

	/**Konstruktor argumentowy, ustawiający dane konta*/
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

	/**Metoda getisAdmin zwraca zmienna typu bool zawierajacą informację o typie konta
	@return isAdmin
	*/
	bool getIsAdmin() { return isAdmin; }

	/**Metoda setPassword ustawiwa hasło
	@param newPass nowe haslo
	*/
	void setPassword(string newPass) { password = newPass; }

	/**Metoda statyczna getLastAccountNumber zwraca numer następnego konta
	@return zwraca następny numer konta
	*/
	static long getLastAccountNumber() { return NextAccNumber; }

	/**Metoda statyczna setAccountNumber ustawia zmienną NextAccountNumber na aktualny numer
	@param accountNumber numer konta
	*/
	static void setAccountNumber(long accountNumber) { NextAccNumber = accountNumber; }

	/**Zaprzyjaźniony operator przeładowania ułatwiający czytanie danych z pliku
	@param &ifs źródło strumienia pliku
	@param &acc obiekt klasy do którego wpisujemy z pliku
	*/
	friend std::fstream& operator>>(std::fstream& ifs, Account& acc);

	/**Zaprzyjaźniony operator przeładowania ułatwiający wpisanie danych do pliku
	@param &outfile źródło strumienia pliku
	@param &acc obiekt klasy wpisywany do pliku
	*/
	friend std::fstream& operator<<(std::fstream& outfile, Account& acc);

	/**Zaprzyjaźniony operator przeładowania ułatwiający wypisywanie obiektu na ekran
	@param &os źródło strumienia wypisania
	@param &acc obiekt klasy, który chcemy wypisać
	*/
	friend std::ostream& operator<<(std::ostream& os, Account& acc);
};
#endif