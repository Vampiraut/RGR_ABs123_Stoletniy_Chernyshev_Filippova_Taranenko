#include "AtbashCode.h"

void AtbashCode(int code) {
	if (code != 1)
	{
		string bufer = "";
		ifstream fout("Some_text.txt");//������ ���� � ����� �������
		ofstream promeg("Bufer.txt");  //������� ���� bufer.txt � �������� ���� ��� �����
		while (!fout.eof())
		{
			getline(fout, bufer);
			promeg << bufer;
			if (!fout.eof())
			{
				promeg << '\n';
			}
		}
		fout.close();
		promeg.close();

		ofstream fin("Some_text.txt");	 //������� ���� Some_text.txt ���� ������� ������������ ����, � ����� �������� �����
		ifstream promegCopy("bufer.txt");//������ ���� � ������ ������ ������
		while (!promegCopy.eof())
		{
			getline(promegCopy, bufer);
			fin << bufer;
			if (!promegCopy.eof())
			{
				fin << '\n';
			}
		}
		fin.close();
		promegCopy.close();

#ifndef Clear
		system("CLS");
#endif
#ifdef Clear
		cout << endl;
#endif
	}
	string inputString = "";
	string outputString = "";
	bool isEnd = false;                                                   //che�k-flag for continue

	ifstream fout1("Some_text.txt"); //������ ���� � ������ � ����� �������
	ofstream fin2("Str_aft_proc.txt");
#ifndef Clear
	system("CLS");
#endif
	funkPrinciple(1);
	funkTypeName(7);
	cout << "Encrypted string: " << endl;

	getline(fout1, inputString);
	const char seng[27] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	const char beng[27] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	const char srus[34] = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�' };
	const char brus[34] = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�' };
	char c;
	bool flag;
	for (int i = 0; inputString[i] != '\0'; i++) {
		flag = false;
		for (int j = 0; j < 26; j++) {
			if (inputString[i] == beng[j]) {
				c = beng[25 - j];
				flag = true;
				outputString += c;
			}
			if (inputString[i] == seng[j]) {
				c = seng[25 - j];
				flag = true;
				outputString += c;
			}
		}
		for (int j = 0; j < 33; j++) {
			if (inputString[i] == brus[j]) {
				c = brus[32 - j];
				flag = true;
				outputString += c;
			}
			if (inputString[i] == srus[j]) {
				c = srus[32 - j];
				flag = true;
				outputString += c;
			}
		}
		if ( flag == false) {
			outputString += inputString[i];
		}
	}
	cout << outputString << endl;
	fin2 << outputString;
	fout1.close();
	fin2.close();
	cout << endl;
#ifndef Clear
	system("PAUSE");
	system("CLS");
#endif
}