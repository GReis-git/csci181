/*
	Gordon Reis
	CSCI 181 Assignment 1
	1/12/2022
*/

#include <string>
#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;
/* realize i used the name cipherText instead of plainText this whole code segment too. oops!
string encode(string cipherText, string keyword) {
	int iterations = (cipherText.size()/keyword.size())+1;
	cout << cipherText[0] << "\n";
	for(int i = 0; i < iterations; i++) {
		int offset = keyword.size()*i;
		for(int j = 0; j < keyword.size(); j++) {
			cout << "offset: " << offset << " j: " << j << " text: " << cipherText[offset+j] << "\n";
			if((cipherText[offset+j]-65) + (keyword[j]-65) > 25) {
				cipherText[offset+j] += keyword[j]-90;
				cout << "1 - replacing " << cipherText[offset+j] << " with " << cipherText[offset+j] + keyword[j]-90 << "\n";
			}
			else {
				cipherText[offset+j] += keyword[j]-65;
				cout << "2 - replacing " << cipherText[offset+j] << " with " << cipherText[offset+j] + keyword[j]-90 << "\n";
			}
		}
	}
	return cipherText;
}
*/

/*
Uses the Vigenere cipher method to encode plaintext using a given keyword

Preconditions: inputs are sanitized to be ONLY uppercase characters with no spaces
Postcondition: the now encoded ciphertext is returned in uppercase
*/
string encode(string plainText, string keyword) {
	
	string cipherText = "";
	for(int i = 0; i < plainText.size(); i++) {
		if (plainText[i]+(keyword[i%keyword.size()]-65) > 90) {
			cipherText += plainText[i]+keyword[i%keyword.size()]-91;
			//cout << "1- cipherText[i]: " << cipherText[i] << " plainText[i]: " << plainText[i] << " keyword[i]: " << keyword[i%keyword.size()] << "\n";
		}
		else {
			cipherText += plainText[i]+keyword[i%keyword.size()]-65;
			//cout << "2- cipherText[i]: " << cipherText[i] << " plainText[i]: " << plainText[i] << " keyword[i]: " << keyword[i%keyword.size()] << "\n";
		}
	}
	return cipherText;
}
/*
Uses the Vigenere cipher method to decode ciphertext using a given keyword

Preconditions: inputs are sanitized to be ONLY uppercase characters with no spaces
Postcondition: the now decoded plaintext is returned in uppercase
*/
string decode(string cipherText, string keyword) {
	string plainText = "";
	for(int i = 0; i < cipherText.size(); i++) {
		if (cipherText[i]-(keyword[i%keyword.size()]-65) < 65) {
			plainText += cipherText[i]-keyword[i%keyword.size()]+91;
			//cout << "1- cipherText[i]: " << (int) cipherText[i] << " plainText[i]: " << (int) plainText[i] << " keyword[i]: " << (int) keyword[i%keyword.size()] << "\n";
		}
		else {
			plainText += cipherText[i]-keyword[i%keyword.size()]+65;
			//cout << "2- cipherText[i]: " << (int) cipherText[i] << " plainText[i]: " << (int) plainText[i] << " keyword[i]: " << (int) keyword[i%keyword.size()] << "\n";
		}
	}
	return plainText;
	
}

int main() {
	/*
	Example from Wikipedia: https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher
	
	Plaintext:	ATTACKATDAWN
	Key:	    LEMONLEMONLE
	Ciphertext:	LXFOPVEFRNHR

	*/

	string hwCT = "PTUGYCYMHZGVVZVFXKLZGYPVJHZLSDSMYCKVXVVVATZEWFXZLDOGLZVFRMVZRTFQFFGPRXHALAYCELWTVHVPNCOSHWWELMEHHJLMFVOJFFFHWJOGKSMFAVQVFHVQNOLALVTBYWKHHLRKSKDLZZXDEZHBUKWCKALVFXZXKCVVQVWGALVFXDEJDELRKMHMXZAXASTCGAIDDEHXVHALWYOWVAJOWCEEQBUKRQKVWJHALXZZXZEKHALFRGXVJKVXHPKOKYEZZPOIEKXMMIGMHVIWOLHKVXUEIFHDSWHALECHXYVRWEJSMSKLHFBEFEJATSPGCKAMFBHMXYSMYMRBZCPRFMPPVGTUHSMMOIVBWVJDOLZECAHZXKVXLRKWKLXIWTUKCSPHWZBLOEUCPDLVBBHWBSWTCJSEMHZRMOIJVTKSNQHCIIVTSJKVXHVVOBOEUBMZXMRBLHRBRMSIATSKVCFLXIMRLXSJMPJZUOYIU";
	string hwKEY = "OTHER";
	
	string plainText = "ATTACKATDAWN";
	string keyword = "LEMON";
	string cipherText = encode(plainText, keyword);
	std::cout << "Encode Test: " << cipherText << "\n";
	
	cipherText = "LXFOPVEFRNHR";
	plainText = decode(hwCT, hwKEY);
	std::cout << "Decode Test: " << plainText << "\n";
}