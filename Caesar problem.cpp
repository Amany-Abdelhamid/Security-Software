#include <iostream>
#include <string>
#include "ctype.h"
using namespace std;

int main()
{

	long long n; int flag = 0;
	string plaintext;
	cin >> n; 
	if (!(n >= 0 && n <= 99999999999))
	{
		cout << "ERROR input\n";	
	}
	cin.ignore();
	getline(cin, plaintext);
	for (int i = 0; i < plaintext.length(); i++)
	{
		if (!(isupper(plaintext[i])))
		{
			flag = 1;
			break;
		}
	}
	if (flag==1)
	cout << "ERROR input\n";
	if (n > 25)
		n = n % 26;
	for (int i = 0; i < plaintext.length(); i++)
	{
		if (char(plaintext[i] + n)>90)
			cout << char(plaintext[i] + n - 26);
		else
		cout << char(plaintext[i] + n);
	}
	cout << "\n";
	return 0;
}