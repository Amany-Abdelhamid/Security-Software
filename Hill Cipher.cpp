#include <iostream>
#include <string>
#include "ctype.h"
#include <math.h>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
	string plaintext, keytext; int key_length; int x; vector<long> key; vector<int> part;
	cin >> key_length;
    x = int(sqrt(double(key_length)));
	if ((key_length <= 0) || (key_length>10000) || ((x*x) != key_length))
	{
		cout << "ERROR length\n";
		exit(EXIT_FAILURE);
	}
	cin.ignore();
	getline(cin, keytext);
	
	for (int i = 0; i < keytext.length(); i++)
	{
		switch (keytext[i])
		{
		case ' ': case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': break;
		default: cout << "Wrong key\n"; exit(EXIT_FAILURE);
		}
		if (keytext[0] == ' ')
		{
			cout << "Error start with a number not space\n"; exit(EXIT_FAILURE);
		}
	    if ((keytext[i] == ' ') && (keytext[i + 1] == ' '))
		{
			cout << "Error Double space\n"; exit(EXIT_FAILURE);
		}
		if (keytext[keytext.length()] == ' ')
		{
			cout << "Error end with a number not space\n"; exit(EXIT_FAILURE);
		}
	}
	
	string sub; int j = 0; 
	for (int i = 0; i <= keytext.length(); i++)
	{
		if (keytext[i] == ' ' || keytext[i] == NULL)
		{
			sub = keytext.substr(j, i );
			key.push_back(atol(sub.c_str()));
			j = i + 1;
		}
	}
	if (key.size() != key_length)
	{
		cout << "Error key length is wrong\n"; exit(EXIT_FAILURE);
	}
	for (int i = 0; i < key.size(); i++)
	{
		if (key[i]>1000000000)
		{
			cout << "Error key is out of range\n"; exit(EXIT_FAILURE);
		}
	}

	getline(cin, plaintext);
	if (plaintext.length()>100)
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
	if (plaintext.length() % x != 0)
	{
		for (int i = 1; i < x; i++)
		{
			plaintext.push_back('X');
			if (plaintext.length() % x == 0)
				break;
		}
	}
	long long output = 0;
	for (int i = 0; i < x; i++)
	{
		part.push_back(0);
	}
	for (int i = 0; i < plaintext.length(); i++)
	{
		for (int j = 0; j < x; j++)
		{
			part[j] = int(plaintext[i]-65);
			i++;
		}
		i--;
		for (int k = 0; k < key_length; k++)
		{
			for (int j = 0; j < x; j++)
			{
				output += long long(long(part[j]) * (key[k]%26));
				k++;
			}
			k--;
			cout << char((output%26) + 65);
			output = 0;
		}
	}
	
	cout << "\n";
	return 0;
}