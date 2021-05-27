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

	long accNumber; /**< Zmienna long zawieraj¹ca numer konta*/
	string login; /**< Zmienna string zawieraj¹ca login do konta*/
	string password; /**< Zmienna string zawieraj¹ca has³o do konta*/
	bool isAdmin; /**< Zmienna bool zawieraj¹ca informacje czy konto jest adminem lub zwyk³ym u¿ytkownikiem*/
	static long NextAccNumber; /**< zmienna statyczna zawieraj¹ca numer nastêpnego konta*/
public:
	/**Konstruktor bezargumentowy*/
	Account();

	/**Konstruktor argumentowy, ustawiaj¹cy dane konta*/
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

	/**Metoda getisAdmin zwraca zmienna typu bool zawierajac¹ informacjê o typie konta
	@return isAdmin
	*/
	bool getIsAdmin() { return isAdmin; }

	/**Metoda setPassword ustawiwa has³o
	@param newPass nowe haslo
	*/
	void setPassword(string newPass) { password = newPass; }

	/**Metoda statyczna getLastAccountNumber zwraca numer nastêpnego konta
	@return zwraca nastêpny numer konta
	*/
	static long getLastAccountNumber() { return NextAccNumber; }

	/**Metoda statyczna setAccountNumber ustawia zmienn¹ NextAccountNumber na aktualny numer
	@param accountNumber numer konta
	*/
	static void setAccountNumber(long accountNumber) { NextAccNumber = accountNumber; }

	/**ZaprzyjaŸniony operator prze³adowania u³atwiaj¹cy czytanie danych z pliku
	@param &ifs Ÿród³o strumienia pliku
	@param &acc obiekt klasy do którego wpisujemy z pliku
	*/
	friend std::fstream& operator>>(std::fstream& ifs, Account& acc);

	/**ZaprzyjaŸniony operator prze³adowania u³atwiaj¹cy wpisanie danych do pliku
	@param &outfile Ÿród³o strumienia pliku
	@param &acc obiekt klasy wpisywany do pliku
	*/
	friend std::fstream& operator<<(std::fstream& outfile, Account& acc);

	/**ZaprzyjaŸniony operator prze³adowania u³atwiaj¹cy wypisywanie obiektu na ekran
	@param &os Ÿród³o strumienia wypisania
	@param &acc obiekt klasy, który chcemy wypisaæ
	*/
	friend std::ostream& operator<<(std::ostream& os, Account& acc);
};
#endif