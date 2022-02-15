#include <iostream>
#include <cstdlib>
#include <locale>
#include <string>


using namespace std;

char* memorylock(int n)
{
	char* B;
	B = static_cast <char*> (calloc(n, sizeof(char)));
	return B;
}

void CODE(char* a, int num)
{
	string inputstring;

	int n = 2;

	char* outputstring = memorylock(n);
	char* outputstring_cop = memorylock(n);

	cout << "Enter coding string: ";
	cin.ignore();
	getline(cin, inputstring);

	for (int i = 0; inputstring[i] != '\0'; i++)
	{
		for (int j = 0; j != num; j++)
		{
			if (inputstring[i] == a[j])
			{
				int smena = j + 2;

				if (smena == num)
				{
					smena = 0;
				}

				else if (smena == num + 1)
				{
					smena = 1;
				}

				outputstring[i] = a[smena];

				for (int g = 0; g < n; g++)
				{
					outputstring_cop[g] = outputstring[g];
				}

				n++;

				free(outputstring);
				outputstring = memorylock(n);

				for (int g = 0; g < n - 1; g++)
				{
					outputstring[g] = outputstring_cop[g];
				}

				free(outputstring_cop);
				outputstring_cop = memorylock(n);

				break;
			}
		}
	}

	system("CLS");

	cout << "Coding string: ";
	for (int g = 0; g < n - 1; g++)
	{
		cout << outputstring[g];
	}
	free(outputstring);
	free(outputstring_cop);
}

void DECODE(char* a, int num)
{
	string inputstring;

	int n = 2;

	char* outputstring = memorylock(n);
	char* outputstring_cop = memorylock(n);

	cout << "Enter decoding string: ";
	cin.ignore();
	getline(cin, inputstring);

	for (int i = 0; inputstring[i] != '\0'; i++)
	{
		for (int j = 0; j != num; j++)
		{
			if (inputstring[i] == a[j])
			{
				int smena = j - 2;

				if (smena == -2)
				{
					smena = num - 2;
				}

				else if (smena == -1)
				{
					smena = num - 1;
				}

				outputstring[i] = a[smena];

				for (int g = 0; g < n; g++)
				{
					outputstring_cop[g] = outputstring[g];
				}

				n++;

				free(outputstring);
				outputstring = memorylock(n);

				for (int g = 0; g < n - 1; g++)
				{
					outputstring[g] = outputstring_cop[g];
				}

				free(outputstring_cop);
				outputstring_cop = memorylock(n);

				break;
			}
		}
	}

	system("CLS");

	cout << "Decoding string: ";
	for (int g = 0; g < n - 1; g++)
	{
		cout << outputstring[g];
	}
	free(outputstring);
	free(outputstring_cop);
}

void main()
{
	setlocale(LC_ALL, "Rus");

	int num = 27;                                    
	char A[28] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 


	char* a_A = A;

	string funk;
	cout << "Code or Decode: ";
	cin >> funk;


	if (funk != "Code" || funk != "Decode")
	{
		while (funk != "Code" && funk != "Decode")
		{
			system("CLS");
			cout << "Error. Write \"Code\" or \"Decode\" only." << endl;
			cout << "Code or Decode: ";
			cin >> funk;
		}
	}
	system("CLS");

	if (funk == "Code")
	{
		CODE(a_A, num);
	}

	else if (funk == "Decode")
	{
		DECODE(a_A, num);
	}
}