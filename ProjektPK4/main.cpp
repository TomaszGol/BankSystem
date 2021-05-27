#include <iostream>
#include <Windows.h>

#include "Functions.h"

using namespace std;

int main()
{
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\033[21;31mBank\033[0m\n" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	Sleep(500);
	LoginMenu();
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}
