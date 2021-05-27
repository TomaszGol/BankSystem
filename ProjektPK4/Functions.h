/** @file */
#pragma once
#include <iostream>
#include <conio.h>
#include <cstdio>
#include <map>
#include <regex>

#include "Account.h"
#include "AllAccounts.h"


#ifndef _Functions_H_
#define _Functions_H_

using namespace std;

/**Funkcja LoginMenu ob�usugj�ca menu logowania*/
void LoginMenu();

/**Funkcja AdminMenu ob�usugj�ca menu z poziomu konta admina*/
void AdminMenu();

/**Funkcja UserMenu ob�usugj�ca menu z poziomu konta u�ytkownika*/
void UserMenu(long number);

/**Funkcja checkWithPattern typu bool, s�u�y do sprwadzenia wzoru regex
@param str string do sprawdzenia ze wzorem
@param pattern zmienna regex zawiera wz�r do kt�rego ma by� przyr�wnany string
@return zwraca true lub false w zale�no�ci czy string zgadza si� z wzorem
*/
bool checkWithPattern(string str, regex pattern);

/**Funkcja ReadLoanFromFile typu map, funkcja korzysta z szablonu, s�u�y do wczytania mapy z pliku 
@return zwraca map�, wczytan� z pliku
*/
template<class T, class Y>
map<T, Y> ReadLoanFromFile()
{
	map <T, Y> contener;
	fstream file;
	T a;
	Y b;

	file.open("Loans.txt");
	if (!file)
	{
		cout << "Can't open file" << endl;
	}
	while (!file.eof())
	{
		file >> a;
		file >> b;
		contener.insert(pair<T, Y>(a, b));
	}
	file.close();
	return contener;
}


/**Funkcja SaveMapToFile typu void,  funkcja korzysta z szablonu, s�u�y do zapisania mapy z po�yczkami do pliku
@param loans mapa r�nego typu, korzysta z szablonu z informacjami o po�yczkach
*/
template<class T, class Y>
void SaveMapToFile(map<T, Y> loans)
{
	fstream file;
	file.open("Loans.txt", std::ofstream::out | std::ofstream::trunc);
	typename map<T, Y>::iterator itr;
	for (itr = loans.begin(); itr != loans.end(); itr++)
	{
		file << itr->first << endl;
		file << itr->second << endl;
	}
	file.close();
}

#endif
