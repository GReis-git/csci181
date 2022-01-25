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


/*
Preconditions: 
ciphertext is given in all lowercase letters
length < length of ciphertext

Postconditions:
prints the histogram for every column to standard output
*/
void print_histogram(string ciphertext, int length) {
	int histogram[26] = {0};
	for(int j = 1; j <= length; j++) {
		// sloppily using a redefinition to clear the array
		int histogram[26] = {0};
		for(int i = 0; ciphertext[i] != '\0'; i++) {
			if(i % length == j % length) 
				histogram[ciphertext[i]-97]++;
		}
		for(size_t i = 0; i < 26; i++) cout << histogram[i] << " ";
		cout << "\n";
	}
	
}


int main() {
	string ciphertext = "ptugycymhzgvvzvfxklzgypvjhzlsdsmyckvxvvvatzewfxzldoglzvfrmvzrtfqffgprxhalaycelwtvhvpncoshwwelmehhjlm fvojfffhwjogksmfavqvfhvqnolalvtbywkhhlrkskdlzzxdezhbukwckalvfxzxkcvvqvwgalvfxdejdelrkmhmxzaxastcgaiddehxvhalwyowvajowceeqbukrqkvwjhalxzzxzekhalfrgxvjkvxhpkokyezzpoiekxmmigmhviwolhkvxueifhdswhalechxyvrwejsmsklhfbefejatspgckamfbhmxysmymrbzcprfmppvgtuhsmmoivbwvjdolzecahzxkvxlrkwklxiwtukcsphwzbloeucpdlvbbhwbswtcjsemhzrmoijvtksnqhciivtsjkvxhvvoboeubmzxmrblhrbrmsiatskvcflximrlxsjmpjzuoyiu";
	int length = 5;
	print_histogram(ciphertext, length);
}