/** @file */
#pragma once
#include <iostream>

#ifndef _BankAccount_H_
#define _BankAccount_H_

using namespace std;
/**Klasa BankAccount zawiera wszystkie informacje o koncie bankowym*/
class BankAccount {
	string name; /**< zmienna zawieraj�ca imie w�a�ciciela konta*/
	string lastName; /**< zmienna zawieraj�ca nazwisko w�a�ciciela konta*/
	long accountNumber; /**< Zmienna long zawieraj�ca numer konta*/
	float balance; /**< zmienna zawieraj�ca balans konta*/
	static long NextAccountNumber; /**< zmienna statyczna zawieraj�ca numer nast�pnego konta*/
public:
	/**Konstruktor bezargumentowy*/
	BankAccount();

	/**Konstruktor argumentowy, ustawiaj�cy dane konta*/
	BankAccount(string fname, string lname, float balance);

	/**Metoda getName zwraca imie osoby
	@return imie osoby
	*/
	string getName() { return name; }

	/**Metoda getLastName zwraca nazwisko osoby
	@return nazwisko osoby
	*/
	string getLastName() { return lastName; }

	/**Metoda getAccountNumber zwraca numer konta
	@return numer konta
	*/
	long getAccountNumber() { return accountNumber; }

	/**Metoda getBalance zwraca aktualny balans konta
	@return aktualny balans konta
	*/
	float getBalance() { return balance; }

	/**Metoda statyczna getLastAccountNumber zwraca numer nast�pnego konta
	@return zwraca nast�pny numer konta
	*/
	static long getLastAccountNumber() { return NextAccountNumber; }

	/**Metoda statyczna setAccountNumber ustawia zmienn� NextAccountNumber na aktualny numer
	@param accountNumber numer konta
	*/
	static void setAccountNumber(long accountNumber) { NextAccountNumber = accountNumber; }

	/**Metoda Deposit dodaje do aktualnego balansu okre�lon� warto��
	@param ammount kwota, kt�r� dodajemy do aktualnego balansu.
	*/
	void Deposit(float ammount);

	/**Metoda Withdraw odejmuje od aktualnego balansu okre�oln� warto��
	@param ammount kwota, kt�r� odejmujemy od aktualnego balansu.
	*/
	void Withdraw(float ammount);

	/**Zaprzyja�niony operator prze�adowania u�atwiaj�cy czytanie danych z pliku
	@param &ifs �r�d�o strumienia pliku
	@param &acc obiekt klasy do kt�rego wpisujemy z pliku
	*/
	friend std::fstream& operator>>(std::fstream& ifs, BankAccount& acc);

	/**Zaprzyja�niony operator prze�adowania u�atwiaj�cy wpisanie danych do pliku
	@param &outfile �r�d�o strumienia pliku
	@param &acc obiekt klasy wpisywany do pliku
	*/
	friend std::fstream& operator<<(std::fstream& outfile, BankAccount& acc);

	/**Zaprzyja�niony operator prze�adowania u�atwiaj�cy wypisywanie obiektu na ekran
	@param &os �r�d�o strumienia wypisania
	@param &acc obiekt klasy, kt�ry chcemy wypisa�
	*/
	friend std::ostream& operator<<(std::ostream& os, BankAccount& acc);
};
#endif 
