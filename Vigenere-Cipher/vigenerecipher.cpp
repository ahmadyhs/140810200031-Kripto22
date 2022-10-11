/*
  Vigenere Cipher Encryption Program
  AHMAD YAHYA SALIM - 140810200031
*/

#include <iostream>
using namespace std;

void enkripsi(string plainText, string key);
void dekripsi(string cipherText, string key);

void enkripsi(string plainText, string key){
	string cipherText = "";

    for(int i = 0; i < plainText.length(); i++){
        if (isupper(plainText[i])) cipherText += char((int(plainText[i]) + int(key[i]) - 130) % 26 + 65);
        else cipherText += char((int(plainText[i]) + int(key[i]) - 194) % 26 + 97);
	}
	
	cout << "Hasil Enkripsi : " << cipherText;
	dekripsi(cipherText, key);
}

void dekripsi(string cipherText, string key){
	string resultText = "";

    for(int i = 0; i < cipherText.length(); i++){
        if (isupper(cipherText[i])) resultText += char(((int(cipherText[i]) - 65) - (int(key[i]) - 65) + 26) % 26 + 65);
        else resultText += char(((int(cipherText[i]) - 97) - (int(key[i]) - 97) + 26) % 26 + 97);
	}
	
	cout << "\n\nHasil Dekripsi : " << resultText << endl;
}

int main(){
	string plainText;
	string cipherText;
    string key;
    string fullKey = "";
    int kSize;

	cout << "\n\t---- Program Enkripsi Vigenere Cipher ----\n";

	cout << "\nMasukkan plain text : ";
	cin >> plainText;

	cout << "\nKey : ";
    cin >> key;
    kSize = key.length();

    for(int i = 0; i < plainText.length() - kSize; i++){
        key += key[i%kSize];
    }
    
    
    enkripsi(plainText, key);

}