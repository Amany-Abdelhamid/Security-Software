#include <iostream>
#include <string>
using namespace std;

long GCD(long A, long B)
{
	long R;
	if (B == 0)
		return A;
	else
	{
		R = A % B;
	    return GCD(B, R);
	}
}

int main()
{
	string AB; long A,B, out;

	getline(cin, AB);

	for (int i = 0; i < AB.length(); i++)
	{
		switch (AB[i])
		{
		case ' ': case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': break;
		default: cout << "Wrong Input\n"; exit(EXIT_FAILURE);
		}
		if (AB[0] == ' ')
		{
			cout << "Error start with a number not space\n"; exit(EXIT_FAILURE);
		}
		if ((AB[i] == ' ') && (AB[i + 1] == ' '))
		{
			cout << "Error Double space\n"; exit(EXIT_FAILURE);
		}
		if (AB[AB.length()] == ' ')
		{
			cout << "Error end with a number not space\n"; exit(EXIT_FAILURE);
		}
		if (AB[i] == ' ')
		{
			for (int j = i+1; j < AB.length(); j++)
			{
				if (AB[j] == ' ')
				{
					cout << "Error Enter 2 inputs only.\n"; exit(EXIT_FAILURE);
				}
			}
		}
	}

	string sub; int j = 0;
	for (int i = 0; i <= AB.length(); i++)
	{
		if (AB[i] == ' ' || AB[i] == NULL)
		{
			sub = AB.substr(j, i);
			if ((atol(sub.c_str())) < 0 || (atol(sub.c_str()))>2000000000)
			{
				cout << "Error range of the numbers is (0-2000000000).\n"; exit(EXIT_FAILURE);
			}
			else
			{
				if (j == 0)
				{
					A = atol(sub.c_str());
					j = i + 1;
				}
				else
				{
					B = atol(sub.c_str());
				}
			}
		}
	}
	
	if (A == 0)
	{
		cout << B;
		exit(EXIT_FAILURE);
	}
	else if (B == 0)
	{
		cout << A;
		exit(EXIT_FAILURE);
	}
	if (A > B)
	{
		cout << GCD(A, B);
	}
	else if (B > A)
	{
		cout << GCD(B, A);
	}
	cout << "\n";
	return 0;
}