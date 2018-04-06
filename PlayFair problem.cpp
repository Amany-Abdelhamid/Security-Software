#include <iostream>
#include <string>
#include "ctype.h"
using namespace std;

int main()
{
	string plaintext,key;
	getline(cin, key);
	if (key.length()>25)
	{
		cout << "ERROR input\n";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < key.length(); i++)
	{
		if (!(isupper(key[i])))
		{
			cout<< "ERROR input\n";
			exit(EXIT_FAILURE);
		}
		for (int j = i + 1; j < key.length(); j++)
		{
			if ((key[i] == key[j]) || ((key[i] == 'I') && (key[j] == 'J')) || ((key[i] == 'J') && (key[j] == 'I')))
			{
				cout << "ERROR input\n";
				exit(EXIT_FAILURE);
			}
		}
	}
	
	getline(cin, plaintext);
	if ((plaintext.length() % 2 != 0) || (plaintext.length()>1000))
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
	for (int j = 0; j < plaintext.length(); j=j+2)
	{
		if ((plaintext[j] == plaintext[j + 1]) || (plaintext[j] == 'I' && plaintext[j + 1] == 'J') || (plaintext[j] == 'J' && plaintext[j + 1] == 'I'))
		{
			cout << "ERROR input\n";
			exit(EXIT_FAILURE);
		}
	}
	char pf[5][5] = {""}; int n = 0,k=65,flag=0;
	for (int i = 0; i < 5; i++)
	{
			for (int j = 0; j < 5; j++)
			{
				if (n != key.length())
				{
					pf[i][j] = key[n];
					n++;
				}
				else
				{ 
					for (int u = 0; u < key.length(); u++)
					{
						if ((key[u] == k) || (key[u] == 'I' && k == 74) || (key[u] == 'J' && k == 73))
						{
							flag = 1; break;
						}
					}
					if (!flag)
					{
						pf[i][j] = k;
					}
					else
					{
						j--;
						flag = 0;
					}
					if (k == 73)
						k = k + 2;
					else
						k++;
				}
			}
	}
	/*for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << pf[i][j] << " ";
		}
		cout << endl;
	}*/
	int r1, r2, c1, c2; flag = 0;
	for (int u = 0; u < plaintext.length(); u=u+2)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if ((plaintext[u] == pf[i][j]) || (plaintext[u] == 'I' && pf[i][j] == 'J') || (plaintext[u] == 'J' && pf[i][j] == 'I'))
				{
					r1 = i;
					c1 = j;
				}
				else if ((plaintext[u + 1] == pf[i][j]) || (plaintext[u + 1] == 'I' && pf[i][j] == 'J') || (plaintext[u + 1] == 'J' && pf[i][j] == 'I'))
				{
					r2 = i;
					c2 = j;
				}
			}
		}
		
		if (r1 == r2 && c1 != c2)
		{
			if (pf[r1][(c1 + 1) % 5] == 'J')pf[r1][(c1 + 1) % 5] = 'I';
			if (pf[r2][(c2 + 1) % 5] == 'J')pf[r2][(c2 + 1) % 5] = 'I';
			cout << pf[r1][(c1+1)%5] << pf[r2][(c2+1)%5];
		}
		else if (r1 != r2 && c1 == c2)
		{
			if (pf[(r1 + 1) % 5][c1] == 'J')pf[(r1 + 1) % 5][c1] = 'I';
			if (pf[(r2 + 1) % 5][c2] == 'J')pf[(r2 + 1) % 5][c2] = 'I';
			cout << pf[(r1 + 1) % 5][c1] << pf[(r2 + 1) % 5][c2];
		}
		else
		{
			if (pf[r1][c2] == 'J')pf[r1][c2] = 'I';
			if (pf[r2][c1] == 'J')pf[r2][c1] = 'I';
			cout << pf[r1][c2] << pf[r2][c1];
		}
	}
	cout << "\n";
	return 0;
}