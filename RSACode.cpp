#include "Header.h"

void RSACode()
{
	string publicExponStr = "";
	string privateExponStr = "";
	string modulStr = "";
	string bufer = "";
	string inputString = "";

	ifstream fout("Some_text.txt"); //������ ���� � ������ � ����� �������
	getline(fout, publicExponStr, ' ');
	getline(fout, privateExponStr, ' ');
	getline(fout, modulStr);
	
	while (!fout.eof())
	{
		getline(fout, bufer);
		inputString = inputString + bufer;
		if (!fout.eof())
		{
			inputString = inputString + '\n';
		}
	}
	fout.close();

	uint64_t publicExpon = 0;
	uint64_t privateExpon = 0;
	uint64_t modul = 0;

	for (int i = 0; publicExponStr[i] != '\0'; i++)
	{
		publicExpon = publicExpon * 10 + (publicExponStr[i] - 48);
	}
	for (int i = 0; privateExponStr[i] != '\0'; i++)
	{
		privateExpon = privateExpon * 10 + (privateExponStr[i] - 48);
	}
	for (int i = 0; modulStr[i] != '\0'; i++)
	{
		modul = modul * 10 + (modulStr[i] - 48);
	}

	funkPrinciple(1);
	funkTypeName(5);
	ofstream fin("Str_aft_proc.txt");
	fin << publicExpon << " " << privateExpon << " " << modul << endl;
	cout << "Encryption string: " << endl;
	for (int i = 0; inputString[i] != '\0'; i++)
	{
		uint64_t charASKII = inputString[i];
		uint64_t smenaASKII = 1;
		for (uint64_t j = 0; j < publicExpon; j++)
		{
			smenaASKII = (smenaASKII * charASKII) % modul;
		}
		fin << smenaASKII << '�';
		cout << smenaASKII << '�';
	}
	/*����� ����������� ��������� �������: � ������ ���������� ����� smenaASKII ������� �� 256 ������ (������� ��������� ����� Y)
	� �� ����� �� ����� �������� ������� �� ������� �� 256 (��������� ����� X),
	��� ����� �� ����� �������� ��������� ��� �� 0 �� 256 ��� X � ������������ ��� �� �����. ��� Y �� ����� �������� ����� � �������� 0<Y<256 ��� ������.
	���� ������ => ��������� �������� ���� Y �� ������ � �������� 0<Y<256, �� ������ ����� ���� ������� ����� ���� Y1,Y2 ... Yn.
	������� �������� �������� ��� Yn ... Y2,Y1,Y ���������� �� ����� �������(�������� �� �� �����: (n+1)Yn ... Y2,Y1,Y,X
	���������� ������������������ ���� ����� ���������� ���� �������� ������ � �������� ���������.
	�������� ���������� �������� �������. �������� ������ ������ ��������� ������ ������, ������� �������� �� ��� ���� ����� � �����������.
	��������, ������������ ��������� �� �����: 3678*/
	fin.close();
	cout << endl;
#ifndef Clear
	system("PAUSE");
	system("CLS");
#endif
#ifdef Clear
	cout << endl;
#endif
}