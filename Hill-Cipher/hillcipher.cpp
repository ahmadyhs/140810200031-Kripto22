/*
  Hill Cipher Encryption Program
*/

#include <iostream>
using namespace std;

void enkripsi(string plainText, int key[2][2]);
void dekripsi(string cipher_text, int key[2][2]);
int determinan(int key[2][2]);
int invMod(int a, int b);

void enkripsi(string plainText, int key[2][2]){
	string cipherText = "";
	int matriksPesan[2][1];
	for(int i = 0; i<plainText.length()/2; i++){
		for(int j = i*2; j<=i*2+1; j++){
			matriksPesan[j%2][0] = (plainText[j]) % 65;
		}
		for(int k = 0; k<2; k++){
			cipherText += (key[k][0] * matriksPesan[0][0] + key[k][1] * matriksPesan[1][0]) % 26 + 65;
		}
	}
	cout << "Hasil Enkripsi : " <<cipherText;
	dekripsi(cipherText, key);
}

void dekripsi(string cipherText, int key[2][2]){
	int det = determinan(key);
	int iMod = invMod(det, 26);
	int matriksPesan[2][1];
	int dKey[2][2];
	string resultText = "";

	dKey[0][0] = key[1][1] * iMod % 26;
	dKey[0][1] = ((key[0][1] * -iMod) % 26 + 26) % 26;
	dKey[1][0] = ((key[1][0] * -iMod) % 26 + 26) % 26;
	dKey[1][1] = key[0][0] * iMod % 26;

	for(int i = 0; i<cipherText.length()/2; i++){
		for(int j = i*2; j<=i*2+1; j++){
			matriksPesan[j%2][0] = (cipherText[j]) % 65;
		}
		for(int k = 0; k<2; k++){
			resultText += (dKey[k][0] * matriksPesan[0][0] + dKey[k][1] * matriksPesan[1][0]) % 26 + 65;
		}
	}
	cout << "\nHasil Dekripsi : " << resultText;
}

int determinan(int key[2][2]){
	return key[0][0] * key[1][1] - key[0][1] * key[1][0];
}

int invMod(int a, int b){
    for (int i = 1; i < b; i++){
        if (((a % b) * (i % b)) % b == 1) return i;
	}
}

int main(){
	string plainText;
	string cipherText;
	int menu;
  	int key[2][2];

	cout << "\n\t---- Program Enkripsi Hill Cipher (key 2x2) ----\n";
	cout << "\nMenu\n1. Enkripsi dan Dekripsi pesan\n2. Mencari matriks kunci ";
	cout << "\n\nNomor menu : ";
	cin >> menu;
	switch(menu){
		case 1 : 
			cout << "\nMasukkan plain text : ";
			cin >> plainText;

			cout << "Nilai Kunci K\n";
			for(int i = 0; i<2; i++){
				for(int j = 0; j<2; j++){
					cout << "K [" << i << "][" << j << "]	: ";
					cin >> key[i][j];
				}	
			}
			if (determinan(key) == 0) {
				cout << "\ndeterminan = 0!!\n";
				break;
			}
			enkripsi(plainText, key);
			break;

		case 2 :
			cout << "\nMasukkan plain text : ";
			cin >> plainText;
			
			cout << "\nMasukkan cipher text : ";
			cin >> cipherText;
			break;

		default : break;
	}

}