void encryptionStart(int, int);					//Conditions for performing encryption for the selected type and principle of operation

void GronsfeldDecode(int);						//Decryption with the Gronsfeld cipher		
void GronsfeldCode(int);						//Encryption with the Gronsfeld cipher

void RSAKeyGeneration(int);						//Key generation function for RSA encryption
void RSACode();									//Encryption with RSA cipher
void RSADecode();								//Decryption with RSA cipher

void VernamDecode();							//Decryption with Vernam cipher
void VernamCode();								//Encryption with Vernam cipher

void SimpleTablePermutationDecode(int);
void SimpleTablePermutationCode(int);

void AtbashDecode(int);
void AtbashCode(int);