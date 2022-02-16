#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>
#include <windows.h>

using namespace std;

void funktypename(string cryptotype)				//the function of writing the encryption type
{
	if (cryptotype == "1")
	{
		cout << "1)" << endl;
	}
	else if (cryptotype == "2")
	{
		cout << "2)" << endl;
	}
	else if (cryptotype == "3")
	{
		cout << "3)" << endl;
	}
	else if (cryptotype == "4")
	{
		cout << "4)" << endl;
	}
	else if (cryptotype == "5")
	{
		cout << "5)" << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");						//Russian localization

	string cryptotype;								//encryption selection
	cout << "Encoding types:" << endl << "1)" << endl << "2)" << endl << "3)" << endl << "4)" << endl << "5)" << endl << "What type you want: ";
	cin >> cryptotype;

	if (cryptotype != "1" && cryptotype != "2" && cryptotype != "3" && cryptotype != "4" && cryptotype != "5")	//protection against an incorrectly entered encryption type
	{
		while (cryptotype != "1" && cryptotype != "2" && cryptotype != "3" && cryptotype != "4" && cryptotype != "5")
		{
			system("CLS");
			cout << "Error. Write \"1\" or \"2\" or \"3\" or \"4\" or \"5\" only." << endl;
			cout << "Encoding types:" << endl << "1)" << endl << "2)" << endl << "3)" << endl << "4)" << endl << "5)" << endl << "What type you want: ";
			cin >> cryptotype;
		}
	}

	system("CLS");
	funktypename(cryptotype);

	string funk;									//сhoosing the principle of operation
	cout << "Code or Decode: ";									
	cin >> funk;												

	if (funk != "Code" && funk != "Decode")																		//Protection against an incorrectly entered principle of operation
	{
		while (funk != "Code" && funk != "Decode")
		{
			system("CLS");
			funktypename(cryptotype);
			cout << "Error. Write \"Code\" or \"Decode\" only." << endl;
			cout << "Code or Decode: ";
			cin >> funk;
		}
	}

	system("CLS");
	funktypename(cryptotype);

	if (cryptotype == "1")							//conditions for performing encryption for the selected type and principle of operation
	{
		cout << "1)" << endl;
	}
	else if (cryptotype == "2")
	{
		cout << "2)" << endl;
	}
	else if (cryptotype == "3")
	{
		cout << "3)" << endl;
	}
	else if (cryptotype == "4")
	{
		cout << "4)" << endl;
	}
	else if (cryptotype == "5")
	{
		cout << "5)" << endl;
	}
	return 0;
}