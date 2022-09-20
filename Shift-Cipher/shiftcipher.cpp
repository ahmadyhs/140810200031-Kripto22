/*
  Shift Cipher Encryption Program
*/

#include <iostream>
using namespace std;

string enkripsi(string plain_text, int key){
	string cipher_text = "";	
	for(int i = 0; i < plain_text.size(); i++){
		if(isupper(plain_text[i])){
			cipher_text += char(int(plain_text[i] + key - 65) % 26 + 65); //65 = A-Z
		} else if(isspace(plain_text[i])){ // untuk enkrip spasi
			cipher_text += char(int(plain_text[i] + key));
		} else {
			cipher_text += char(int(plain_text[i] + key - 97) % 26 + 97); //97 = a-z
		}
	}
	return cipher_text;
}

string dekripsi(string cipher_text, int key){
	string plain_text="";	
	for(int i = 0; i < cipher_text.size(); i++){
		if(isupper(cipher_text[i])){
			plain_text += char((int(cipher_text[i] - key - 65) % 26 + 26) % 26 + 65);
		} else if(cipher_text[i]<65){
			plain_text += char(int(cipher_text[i] - key));
		} else {
			plain_text+=  char((int(cipher_text[i] - key - 97) % 26 + 26) % 26 + 97);
		}
	}
	return plain_text;
}

int main(){
	string plain_text;
  	int key;

	cout << "\n\t---- Program Enkripsi Shift Cipher ----\n";
	cout << "\nMasukkan plain text : ";
	getline(cin, plain_text);

	cout << "Masukkan nilai kunci K : ";
	cin >> key;
  
	string cipher_text = enkripsi(plain_text, key);
	
	cout << "\n-----Enkripsi-----\n"; 
	cout << "Cipher text	: " << cipher_text << endl;
	
	cout << "\n------Dekripsi-----\n";
	cout << "Plain Text	: "<< dekripsi(cipher_text, key) << endl;
}