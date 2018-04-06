#include <iostream>
#include <string>
#include "ctype.h"
#include <stdlib.h>
#include <vector>
using namespace std;

int main()
{
	string plaintext, key,key2; 
	getline(cin, key);
	if (key.length()>=10000 || key.length()<1)
	{
		cout << "ERROR input\n";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < key.length(); i++)
	{
		if (!(isupper(key[i])))
		{
			cout << "ERROR input\n";
			exit(EXIT_FAILURE);
		}
	}
	key2 = key;
	getline(cin, plaintext);
	if (plaintext.length() >= 10000 || plaintext.length()<1)
	{
		cout << "ERROR input\n";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < plaintext.length(); i++)
	{
		if (!(isupper(plaintext[i])))
		{
			cout << "ERROR input\n";
			exit(EXIT_FAILURE);
		}
	}
	if (key.length()>plaintext.length())
	{
		cout << "ERROR length of plaintext is smaller than length of key\n";
		exit(EXIT_FAILURE);
	}
	if (key.length() < plaintext.length())
	{
		for (int i = 0; i < (plaintext.length() - key2.length()); i++)
		{
			key.push_back(key2[i % key2.length()]);
		}
	}
	cout << "Vigenere: ";
	for (int i = 0; i < plaintext.length(); i++)
	{
		cout << char((((plaintext[i] - 65) + (key[i] - 65)) % 26) + 65);
	}
	cout << "\n";

	int z;
	cout << "Vernam: ";
	for (int i = 0; i < plaintext.length(); i++)
	{
		z = plaintext[i] ^ key[i];
		if (z < 16)
			cout << '0' << hex <<uppercase<< z;
		else
		cout << hex << z;
	}
	cout << "\n";

	cout << "One-Time Pad: ";
	if (key2.length() == plaintext.length())
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	cout << "\n";
	return 0;
}