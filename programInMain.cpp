#include "programInMain.h"
#include "Encryption.h"
#include "Decryption.h"

//Password verification function
void passwordCheñk()
{
	string password = "";
	cout << "Enter password" << endl << ": ";
	getline(cin, password);
	while (password != PASSWORD)
	{
		system("CLS");
		cout << "Wrong password!" << endl << "Try again." << endl << ": ";
		getline(cin, password);
	}
	system("CLS");
	cout << "Authorization success!" << endl;;
	Sleep(500);
	system("CLS");
}

//Entering a string and saving it to a file or copying and encrypting your file
void inputStrToTxt()
{
	string fileCreate = "";
	bool isGood = false;
	do
	{
		try
		{
			cout << "Do you want to encrypt your file or create a new one?" << endl << "<1>Your file" << endl << "<2>A new file" << endl << ": ";
			getline(cin, fileCreate);
			if (fileCreate == "")
			{
				throw runtime_error("An empty string has been entered.\nTry again.\n");
			}
			if (fileCreate != "1" && fileCreate != "2")
			{
				string err;
				err = "Invalid input.\nYou have entered \"" + fileCreate + "\", when \"1\" or \"2\" was expected.\nTry again.\n";
				throw runtime_error(err);
			}
			isGood = true;
		}
		catch (const std::exception& error)
		{
			system("CLS");
			cerr << error.what();
		}
	} while (isGood == false);
	system("CLS");
	if (fileCreate == "1")
	{
		ofstream fin("Some_text.txt");
		ifstream fout;
		isGood = false;
		string path = "";
		do
		{
			cout << "Enter the path to the file (remember, the file must be ANSI or Windows-1251 encoded)" << endl << ": ";
			getline(cin, path);
			try
			{
				fout.open(path);
				if (!fout.is_open())
				{
					throw runtime_error("Unknown file path.\nTry again.\n");
				}
				string bufer = "";
				while (!fout.eof())
				{
					getline(fout, bufer);
					if (bufer == "")
					{
						throw runtime_error("The file is empty.\nTry again.\n");
					}
					for (int i = 0; i < bufer.length(); i++)
					{
						if ((int)bufer[i] < 32 || (int)bufer[i] > 126)
						{
							throw runtime_error("There are excluded characters in the text.\nLatin alphabet characters punctuation marks and special characters are expected.\nTry again.\n");
						}
					}
					fin << bufer;
					if (!fout.eof())
					{
						fin << endl;
					}
				}
				isGood = true;
			}
			catch (const exception& error)
			{
				system("CLS");
				cerr << error.what();
			}
		} while (isGood == false);
		fin.close();
		fout.close();
		system("CLS");
	}
	else if (fileCreate == "2")
	{
		isGood = false;
		string inputStr = "";
		do
		{
			cout << "Enter a line for encryption" << endl << ": ";
			try
			{
				getline(cin, inputStr);
				if (inputStr == "")
				{
					throw runtime_error("An empty text has been entered.\nTry again.\n");
				}
				for (int i = 0; i < inputStr.length(); i++)
				{
					if ((int)inputStr[i] < 32 || (int)inputStr[i] > 126)
					{
						throw runtime_error("There are excluded characters in the text.\nLatin alphabet characters punctuation marks and special characters are expected.\nTry again.\n");
					}
				}
				isGood = true;
			}
			catch (const exception& error)
			{
				system("CLS");
				cerr << error.what();
			}
		} while (isGood == false);
		ofstream fin("Some_text.txt");
		fin << inputStr;
		fin.close();
		system("CLS");
	}
}

//Choosing the principle of operation
int principleOfOperation()
{
	string strNumPrinciple = "";
	bool isGood = false;
	do
	{
		//Protection against incorrectly entered operating principle
		cout << "Choose the principle of operation: " << endl << "<1>Encryption" << endl << "<2>Decryption" << endl << ": ";
		try
		{
			getline(cin, strNumPrinciple);
			if (strNumPrinciple == "")
			{
				throw runtime_error("An empty string has been entered.\nTry again.\n");
			}
			if (strNumPrinciple != "1" && strNumPrinciple != "2")
			{
				string err;
				err = "Invalid input.\nYou have entered \"" + strNumPrinciple + "\", when \"1\" or \"2\" was expected.\nTry again.\n";
				throw runtime_error(err);
			}
			isGood = true;
		}
		catch (const exception& error)
		{
			system("CLS");
			cerr << error.what();
		}
	} while (isGood == false);

	int intNumPrinciple = strNumPrinciple[0] - 48;

	system("CLS");
	return intNumPrinciple;
}

//Encryption type select
int cryptoTypeSelect(int funkType)
{
	funkPrinciple(funkType);
	string strNumType = "";
	bool isGood = false;
	do
	{
		try //Protection against an incorrectly entered encryption type
		{
			cout << "Select the encryption/decryption type: " << endl << "<1>Gronsfeld Cipher" << endl << "<2>RSA Cipher" << endl << "<3>Morse Cipher" << endl
				<< "<4>Vernam Cipher" << endl << "<5>ElGamal Cipher" << endl << "<6>Gibberish letter"
				<< endl << "<7>Atbash Cipher" << endl << "<8>Simple Table Permutation" << endl << "<9>Shamir Cipher"
				<< endl << "<10>Vigener Cipher" << endl << "<11>Binary Cipher" << endl << "<12>"
				<< endl << ": ";
			getline(cin, strNumType);
			if (strNumType == "")
			{
				throw runtime_error("An empty string has been entered.\nTry again.\n");
			}
			if (strNumType != "1" && strNumType != "2" && strNumType != "3" && strNumType != "4" && strNumType != "5" && strNumType != "6"
				&& strNumType != "7" && strNumType != "8" && strNumType != "9" && strNumType != "10" && strNumType != "11" && strNumType != "12")
			{
				string err;
				err = "Invalid input.\nYou have entered \"" + strNumType + "\", when \"1\" or \"2\" or \"3\" or \"4\" or \"5\" or \"6\" or \"7\" or \"8\" or \"9\" or \"10\" or \"11\" or \"12\" was expected.\nTry again.\n";
				throw runtime_error(err);
			}
			isGood = true;
		}
		catch (const exception& error)
		{
			system("CLS");
			cerr << error.what();
		}
	} while (isGood == false);

	int intNumType = 0;
	for (int i = 0; strNumType[i] != '\0'; i++)
	{
		intNumType = (intNumType * 10) + (strNumType[i] - 48);
	}

	system("CLS");
	return intNumType;
}

//Conditions for performing encryption for the selected type and principle of operation
void encryptionStart(int cryptoType, int funkType)
{
	switch (Ciphers(cryptoType))
	{
	case Ciphers::Gronsfeld:
		switch (Principle(funkType))
		{
		case Principle::Encription:
			GronsfeldCode(0);
			break;
		case Principle::Decription:
			GronsfeldDecode(0);
			break;
		}
		break;
	case Ciphers::RSA:
		switch (Principle(funkType))
		{
		case Principle::Encription:
			RSAKeyGeneration(0);
			RSACode();
			break;
		case Principle::Decription:
			RSAKeyGeneration(1);
			RSADecode();
			break;
		}
		break;
	case Ciphers::Morse:
		switch (Principle(funkType))
		{
		case Principle::Encription:
			MorseCode();
			break;
		case Principle::Decription:
			MorseDecode();
			break;
		}
		break;
	case Ciphers::Vernam:
		switch (Principle(funkType))
		{
		case Principle::Encription:
			VernamCode();
			break;
		case Principle::Decription:
			VernamDecode();
			break;
		}
		break;
	case Ciphers::ElGamal:
		switch (Principle(funkType))
		{
		case Principle::Encription:
			ElGamalCode();
			break;
		case Principle::Decription:
			ElGamalDecode();
			break;
		}
		break;
	case Ciphers::Gibberish:
		switch (Principle(funkType))
		{
		case Principle::Encription:
			GibberishCode();
			break;
		case Principle::Decription:
			GibberishDecode();
			break;
		}
		break;
	case Ciphers::Atbash:
		switch (Principle(funkType))
		{
		case Principle::Encription:
			AtbashCode(0);
			break;
		case Principle::Decription:
			AtbashDecode(0);
			break;
		}
		break;
	case Ciphers::SimpleTablePermutation:
		switch (Principle(funkType))
		{
		case Principle::Encription:
			SimpleTablePermutationCode(0);
			break;
		case Principle::Decription:
			SimpleTablePermutationDecode(0);
			break;
		}
		break;
	case Ciphers::Shamir:
		switch (Principle(funkType))
		{
		case Principle::Encription:
			ShamirKeygen(0);
			ShamirCode();
			break;
		case Principle::Decription:
			ShamirKeygen(1);
			ShamirDecode();
			break;
		}
		break;
	case Ciphers::Vigener:
		switch (Principle(funkType))
		{
		case Principle::Encription:
			VigenerCode(VigenerMatrixCreate(), 0);
			break;
		case Principle::Decription:
			VigenerDecode(VigenerMatrixCreate(), 0);
			break;
		}
		break;
	case Ciphers::Binary:
		switch (Principle(funkType))
		{
		case Principle::Encription:
			BinaryCode();
			break;
		case Principle::Decription:
			BinaryDecode();
			break;
		}
		break;
	case Ciphers::some:
		switch (Principle(funkType))
		{
		case Principle::Encription:
			
			break;
		case Principle::Decription:

			break;
		}
		break;
	}
}

//The function of starting the encryption check
void encryptionCheck(int cryptoType, int funkType)
{
	string codeCheck = "";
	bool isGood = false;
	do
	{
		try
		{
			cout << "Do you want to check the encryption?" << endl << "<1>Yes" << endl << "<2>No" << endl << ":";
			getline(cin, codeCheck);
			if (codeCheck == "")
			{
				throw runtime_error("An empty string has been entered.\nTry again.\n");
			}
			if (codeCheck != "1" && codeCheck != "2")
			{
				string err;
				err = "Invalid input.\nYou have entered \"" + codeCheck + "\", when \"1\" or \"2\" was expected.\nTry again.\n";
				throw runtime_error(err);
			}
			isGood = true;
		}
		catch (const exception& error)
		{
			system("CLS");
			cerr << error.what();
		}
	} while (isGood == false);
	system("CLS");
	if (codeCheck == "1")
	{
		string bufer = "";
		ofstream fin("Some_text.txt");   //if - ÷òåíèå, of - çàïèñü
		ifstream fout("Str_aft_proc.txt");
		while (!fout.eof())
		{
			getline(fout, bufer);
			fin << bufer;
			if (!fout.eof())
			{
				fin << '\n';
			}
		}
		fin.close();
		fout.close();

		passwordCheñk();
		//Conditions for performing encryption for the selected type and principle of operation
		switch (Ciphers(cryptoType))
		{
		case Ciphers::Gronsfeld:
			switch (Principle(funkType))
			{
			case Principle::Encription:
				GronsfeldDecode(1);
				break;
			case Principle::Decription:
				GronsfeldCode(1);
				break;
			}
			break;
		case Ciphers::RSA:
			switch (Principle(funkType))
			{
			case Principle::Encription:
				RSADecode();
				break;
			case Principle::Decription:
				RSACode();
				break;
			}
			break;
		case Ciphers::Morse:
			switch (Principle(funkType))
			{
			case Principle::Encription:
				MorseDecode();
				break;
			case Principle::Decription:
				MorseCode();
				break;
			}
			break;
		case Ciphers::Vernam:
			switch (Principle(funkType))
			{
			case Principle::Encription:
				VernamDecode();
				break;
			case Principle::Decription:
				VernamCode();
				break;
			}
			break;
		case Ciphers::ElGamal:
			switch (Principle(funkType))
			{
			case Principle::Encription:
				ElGamalDecode();
				break;
			case Principle::Decription:
				ElGamalCode();
				break;
			}
			break;
		case Ciphers::Gibberish:
			switch (Principle(funkType))
			{
			case Principle::Encription:
				GibberishDecode();
				break;
			case Principle::Decription:
				GibberishCode();
				break;
			}
			break;
		case Ciphers::Atbash:
			switch (Principle(funkType))
			{
			case Principle::Encription:
				AtbashDecode(1);
				break;
			case Principle::Decription:
				AtbashCode(1);
				break;
			}
			break;
		case Ciphers::SimpleTablePermutation:
			switch (Principle(funkType))
			{
			case Principle::Encription:
				SimpleTablePermutationDecode(1);
				break;
			case Principle::Decription:
				SimpleTablePermutationCode(1);
				break;
			}
			break;
		case Ciphers::Shamir:
			switch (Principle(funkType))
			{
			case Principle::Encription:
				ShamirDecode();
				break;
			case Principle::Decription:
				ShamirCode();
				break;
			}
			break;
		case Ciphers::Vigener:
			switch (Principle(funkType))
			{
			case Principle::Encription:
				VigenerDecode(VigenerMatrixCreate(), 1);
				break;
			case Principle::Decription:
				VigenerCode(VigenerMatrixCreate(), 1);
				break;
			}
			break;
		case Ciphers::Binary:
			switch (Principle(funkType))
			{
			case Principle::Encription:
				BinaryDecode();
				break;
			case Principle::Decription:
				BinaryCode();
				break;
			}
			break;
		case Ciphers::some:
			switch (Principle(funkType))
			{
			case Principle::Encription:

				break;
			case Principle::Decription:

				break;
			}
			break;
		}
	}
	system("CLS");
}