#include <iostream>
#include <string>
using namespace std;

long long EXEuclid(long long m, long long n)
{
	long long A1, A2, A3, B1, B2, B3, T1, T2, T3, Q;
	A1 = 1; A2 = 0; A3 = m;
	B1 = 0; B2 = 1; B3 = n;
loop: if (B3 == 0)
        {  
	       return 0; //no inverse
        }
	  if (B3 == 1)
	  { 
		  return B2; //B2 = b–1 mod m
	  }
	   Q = A3 / B3;
	   T1 = A1 - Q*B1; T2 = A2 - Q*B2; T3 = A3 - Q*B3;
	   A1 = B1; A2 = B2; A3 = B3;
	   B1 = T1; B2 = T2; B3 = T3;
	   goto loop;
}
int main()
{
	string MN; long long M, N; 

	getline(cin, MN);

	for (int i = 0; i < MN.length(); i++)
	{
		switch (MN[i])
		{
		case ' ': case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': break;
		default: cout << "Wrong Input\n"; exit(EXIT_FAILURE);
		}
		if (MN[0] == ' ')
		{
			cout << "Error start with a number not space\n"; exit(EXIT_FAILURE);
		}
		if ((MN[i] == ' ') && (MN[i + 1] == ' '))
		{
			cout << "Error Double space\n"; exit(EXIT_FAILURE);
		}
		if (MN[MN.length()] == ' ')
		{
			cout << "Error end with a number not space\n"; exit(EXIT_FAILURE);
		}
		if (MN[i] == ' ')
		{
			for (int j = i + 1; j < MN.length(); j++)
			{
				if (MN[j] == ' ')
				{
					cout << "Error Enter 2 inputs only.\n"; exit(EXIT_FAILURE);
				}
			}
		}
	}

	string sub; int j = 0;
	for (int i = 0; i <= MN.length(); i++)
	{
		if (MN[i] == ' ' || MN[i] == NULL)
		{
			sub = MN.substr(j, i);
			if ((atoll(sub.c_str())) < 1 || (atoll(sub.c_str()))> 2000000000000000000)
			{
				cout << "Error range of the numbers is (1-2000000000000000000).\n"; exit(EXIT_FAILURE);
			}
			else
			{
				if (j == 0)
				{
					M = atoll(sub.c_str());
					j = i + 1;
				}
				else
				{
					N = atoll(sub.c_str());
				}
			}
		}
	}
	
	long long i;
	i = EXEuclid(M, N);
	if (i == 0)
	{
		cout << "IMPOSSIBLE";
	}
	else
	{
		if (i < 0)
		  cout << ((-N) % M) + M << " " << (i%M) + M;
		else
			cout << ((-N) % M) + M << " " << i;
	}

	cout << "\n";
	return 0;
}