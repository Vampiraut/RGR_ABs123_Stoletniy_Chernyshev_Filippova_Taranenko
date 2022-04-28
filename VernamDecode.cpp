#include "VernamDecode.h"


void VernamDecode(){
	srand(0);

	ifstream fout("Some_text.txt");
	ofstream fin("Str_aft_proc.txt");

	cout << "Decrypted string:" << endl;
	while (!fout.eof()){
		string oStr = "";
		getline(fout, oStr);

		string key = "";
		int i = 0;
		for (i = 0; oStr[i] != '\0'; i++){
			key += (char)(rand() % 127);
		}

		string shStr = "";
		for (i = 0; oStr[i] != '\0'; i++){
			shStr += (oStr[i] ^ key[i]);
		}

		fin << shStr;
		cout << shStr << endl;
		if (!fout.eof()){
			fin << endl;
		}

	}
}

