/** @file */
#pragma once
#include <iostream>

#ifndef _BankAccount_H_
#define _BankAccount_H_

using namespace std;
/**Klasa BankAccount zawiera wszystkie informacje o koncie bankowym*/
class BankAccount {
	string name; /**< zmienna zawieraj¹ca imie w³aœciciela konta*/
	string lastName; /**< zmienna zawieraj¹ca nazwisko w³aœciciela konta*/
	long accountNumber; /**< Zmienna long zawieraj¹ca numer konta*/
	float balance; /**< zmienna zawieraj¹ca balans konta*/
	static long NextAccountNumber; /**< zmienna statyczna zawieraj¹ca numer nastêpnego konta*/
public:
	/**Konstruktor bezargumentowy*/
	BankAccount();

	/**Konstruktor argumentowy, ustawiaj¹cy dane konta*/
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

	/**Metoda statyczna getLastAccountNumber zwraca numer nastêpnego konta
	@return zwraca nastêpny numer konta
	*/
	static long getLastAccountNumber() { return NextAccountNumber; }

	/**Metoda statyczna setAccountNumber ustawia zmienn¹ NextAccountNumber na aktualny numer
	@param accountNumber numer konta
	*/
	static void setAccountNumber(long accountNumber) { NextAccountNumber = accountNumber; }

	/**Metoda Deposit dodaje do aktualnego balansu okreœlon¹ wartoœæ
	@param ammount kwota, któr¹ dodajemy do aktualnego balansu.
	*/
	void Deposit(float ammount);

	/**Metoda Withdraw odejmuje od aktualnego balansu okreœoln¹ wartoœæ
	@param ammount kwota, któr¹ odejmujemy od aktualnego balansu.
	*/
	void Withdraw(float ammount);

	/**ZaprzyjaŸniony operator prze³adowania u³atwiaj¹cy czytanie danych z pliku
	@param &ifs Ÿród³o strumienia pliku
	@param &acc obiekt klasy do którego wpisujemy z pliku
	*/
	friend std::fstream& operator>>(std::fstream& ifs, BankAccount& acc);

	/**ZaprzyjaŸniony operator prze³adowania u³atwiaj¹cy wpisanie danych do pliku
	@param &outfile Ÿród³o strumienia pliku
	@param &acc obiekt klasy wpisywany do pliku
	*/
	friend std::fstream& operator<<(std::fstream& outfile, BankAccount& acc);

	/**ZaprzyjaŸniony operator prze³adowania u³atwiaj¹cy wypisywanie obiektu na ekran
	@param &os Ÿród³o strumienia wypisania
	@param &acc obiekt klasy, który chcemy wypisaæ
	*/
	friend std::ostream& operator<<(std::ostream& os, BankAccount& acc);
};
#endif 
