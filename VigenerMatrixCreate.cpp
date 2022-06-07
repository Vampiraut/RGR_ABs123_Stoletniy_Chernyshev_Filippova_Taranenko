#include "VigenerMatrixCreate.h"

vector<vector<char>> VigenerMatrixCreate()
{
    vector<char> alf;// = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                      //         'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                          //     '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };

    for (int i = 33; i < 127; i++)
    {
        alf.push_back((char)i);
    }
    vector<vector<char>> vigenerTable;

    for (int i = 0; i < alf.size(); i++)
    {
        vector <char> m;
        vigenerTable.push_back(m);
    }
    for (int i = 0; i < alf.size(); i++)
    {
        for (int j = 0; j < alf.size(); j++)
        {
            vigenerTable[i].push_back(alf[j]);
        }
        char m = alf[0];
        alf.erase(alf.cbegin());
        alf.push_back(m);
    }
    return vigenerTable;
}