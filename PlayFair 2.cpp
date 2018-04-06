#include <iostream>
#include <string>
#include "ctype.h"
using namespace std;

int main()
{
	string plaintext, plaintext2, key, key2; int flag = 0;
	getline(cin, key2);
	if (key2.length()>1000)
	{
		cout << "ERROR input\n";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < key2.length(); i++)
	{
		if (!(isupper(key2[i])))
		{
			cout << "ERROR input\n";
			exit(EXIT_FAILURE);
		}
		for (int j = 0; j < i; j++)
		{
			if ((key2[i] == key2[j]) || ((key2[i] == 'I') && (key2[j] == 'J')) || ((key2[i] == 'J') && (key2[j] == 'I')))
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			key.push_back(key2[i]);
		}
		else
			flag = 0;
	}

	getline(cin, plaintext);
	if (plaintext.length()>1000)
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
	for (int j = 0; j < plaintext.length(); j = j + 2)
	{
		plaintext2.push_back(plaintext[j]);
		if (plaintext[j + 1] == NULL)
			break;
		else if ((plaintext[j] == plaintext[j + 1]) || (plaintext[j] == 'I' && plaintext[j + 1] == 'J') || (plaintext[j] == 'J' && plaintext[j + 1] == 'I'))
		{
			if (plaintext[j] == 'X')
				plaintext2.push_back('V');
			else
				plaintext2.push_back('X');
				j--;

		}
		else
			plaintext2.push_back(plaintext[j + 1]);
	}

	if ((plaintext2.length() % 2) != 0 && plaintext2[plaintext2.length()-1]!='X')
		plaintext2.push_back('X');
	else if ((plaintext2.length() % 2) != 0 && plaintext2[plaintext2.length() - 1] == 'X')
		plaintext2.push_back('V');
	

	for (int i = 0; i < plaintext2.length();i=i+2)
		if (plaintext2[i] == plaintext2[i+1])
		{
			cout << "ERROR input\n";
			exit(EXIT_FAILURE);
		}


	char pf[5][5] = { "" }; int n = 0, k = 65; flag = 0;
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
	for (int u = 0; u < plaintext2.length(); u = u + 2)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if ((plaintext2[u] == pf[i][j]) || (plaintext2[u] == 'I' && pf[i][j] == 'J') || (plaintext2[u] == 'J' && pf[i][j] == 'I'))
				{
					r1 = i;
					c1 = j;
				}
				else if ((plaintext2[u + 1] == pf[i][j]) || (plaintext2[u + 1] == 'I' && pf[i][j] == 'J') || (plaintext2[u + 1] == 'J' && pf[i][j] == 'I'))
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
			cout << pf[r1][(c1 + 1) % 5] << pf[r2][(c2 + 1) % 5];
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