#include "VigenerCode.h"

void VigenerCode(vector<vector<char>> vigenerTable, int codeCheck)
{
    vector<char> alfForCod = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                               'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                               '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
    if (codeCheck != 1)
    {
        string bufer = "";
        ifstream fout("Some_text.txt");//читает файл с нашим текстом
        ofstream promeg("Bufer.txt");  //очищает файл bufer.txt и копирует туда наш текст
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

        string someKey = "";
        cout << "Enter code word" << endl << ": ";
        getline(cin, someKey);

        ofstream fin("Some_text.txt");	 //очищает файл Some_text.txt куда сначала записывается ключ, а затем исходный текст
        ifstream promegCopy("bufer.txt");//читает файл с копией нашего текста
        fin << someKey << endl;
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

    string inputString = "";                                         //input string
    string outputString = "";										//output string
    string key = "";

    ifstream fout1("Some_text.txt"); //читает файл с ключом и нашим текстом
    getline(fout1, key);
    ofstream fin2("Str_aft_proc.txt");
    fin2 << key << endl;
#ifndef Clear
    system("CLS");
#endif
    funkPrinciple(1);
    funkTypeName(10);

    if (codeCheck == 1)
    {
        cout << "Your KEY: " << key << endl;
    }
    cout << "Encrypted string: " << endl;

    int p = 0;
    while (!fout1.eof())
    {
        inputString = "";
        outputString = "";
        getline(fout1, inputString);

        for (int i = 0; i < inputString.size(); i++)
        {
            char codInpStr = inputString[i];
            if (codInpStr == ' ')
            {
                outputString += codInpStr;
                continue;
            }

            char codKey = key[p];
            p++;
            if (p >= key.size())
            {
                p = 0;
            }

            int y = 0;
            for (int k = 0; k < alfForCod.size(); k++)
            {
                if (codKey == alfForCod[k])
                {
                    y = k;
                }
            }

            int x = 0;
            for (int k = 0; k < alfForCod.size(); k++)
            {
                if (codInpStr == alfForCod[k])
                {
                    x = k;
                }
            }
            outputString += vigenerTable[y][x];
        }
        fin2 << outputString;											//output of encrypted string
        cout << outputString << endl;
        if (!fout1.eof())
        {
            fin2 << endl;
        }
    }
    fout1.close();
    fin2.close();
    cout << endl;
#ifndef Clear
    system("PAUSE");
    system("CLS");
#endif
}
