#include <iostream>
#include <string>
#include "ctype.h"
#include <vector>
using namespace std;

int main()
{       
	int PC1[56] = { 57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36,
		            63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4 };

	int	PC2[48] = { 14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47,
	            	55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32 };

	int	Rotations[16] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };

	string key; vector<int> key_bin1, PC1_out1, PC1_out2, PC2_out; int PC2_in[56] = { 0 };
	getline(cin, key);
	if (key.length() != 16 )
	{
		cout << "ERROR input is not 64 bit in hex.\n";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < key.length(); i++)
	{
		if (!(key[i] > 47 && key[i] < 58) && !(key[i] > 64 && key[i] < 71))
		{
			cout << "ERROR input "<<key[i]<<endl;
			exit(EXIT_FAILURE);
		}
	}
	for (int i = 0; i < key.length(); i++)
	{
		switch (key[i])
		{
		case '0':{key_bin1.push_back(0); key_bin1.push_back(0); key_bin1.push_back(0); key_bin1.push_back(0); break; }
		case '1':{key_bin1.push_back(0); key_bin1.push_back(0); key_bin1.push_back(0); key_bin1.push_back(1); break; }
		case '2':{key_bin1.push_back(0); key_bin1.push_back(0); key_bin1.push_back(1); key_bin1.push_back(0); break; }
		case '3':{key_bin1.push_back(0); key_bin1.push_back(0); key_bin1.push_back(1); key_bin1.push_back(1); break; }
		case '4':{key_bin1.push_back(0); key_bin1.push_back(1); key_bin1.push_back(0); key_bin1.push_back(0); break; }
		case '5':{key_bin1.push_back(0); key_bin1.push_back(1); key_bin1.push_back(0); key_bin1.push_back(1); break; }
		case '6':{key_bin1.push_back(0); key_bin1.push_back(1); key_bin1.push_back(1); key_bin1.push_back(0); break; }
		case '7':{key_bin1.push_back(0); key_bin1.push_back(1); key_bin1.push_back(1); key_bin1.push_back(1); break; }
		case '8':{key_bin1.push_back(1); key_bin1.push_back(0); key_bin1.push_back(0); key_bin1.push_back(0); break; }
		case '9':{key_bin1.push_back(1); key_bin1.push_back(0); key_bin1.push_back(0); key_bin1.push_back(1); break; }
		case 'A':{key_bin1.push_back(1); key_bin1.push_back(0); key_bin1.push_back(1); key_bin1.push_back(0); break; }
		case 'B':{key_bin1.push_back(1); key_bin1.push_back(0); key_bin1.push_back(1); key_bin1.push_back(1); break; }
		case 'C':{key_bin1.push_back(1); key_bin1.push_back(1); key_bin1.push_back(0); key_bin1.push_back(0); break; }
		case 'D':{key_bin1.push_back(1); key_bin1.push_back(1); key_bin1.push_back(0); key_bin1.push_back(1); break; }
		case 'E':{key_bin1.push_back(1); key_bin1.push_back(1); key_bin1.push_back(1); key_bin1.push_back(0); break; }
		case 'F':{key_bin1.push_back(1); key_bin1.push_back(1); key_bin1.push_back(1); key_bin1.push_back(1); break; }
			 
		}
	}
	for (int i = 0; i < 56; i++)
	{
		if (i < 28)
			PC1_out1.push_back(key_bin1[PC1[i] - 1]);
		else
			PC1_out2.push_back(key_bin1[PC1[i] - 1]);
	}
	
	for (int i = 0; i < 16; i++)
	{
		if (Rotations[i] == 1)
		{
			PC1_out1.push_back(PC1_out1.front());
			PC1_out1.erase(PC1_out1.begin());
			PC1_out2.push_back(PC1_out2.front());
			PC1_out2.erase(PC1_out2.begin());
		}
		else if (Rotations[i] == 2)
		{
			PC1_out1.push_back(PC1_out1.front());
			PC1_out1.erase(PC1_out1.begin());
			PC1_out1.push_back(PC1_out1.front());
			PC1_out1.erase(PC1_out1.begin());
			PC1_out2.push_back(PC1_out2.front());
			PC1_out2.erase(PC1_out2.begin());
			PC1_out2.push_back(PC1_out2.front());
			PC1_out2.erase(PC1_out2.begin());
		}
		for (int i = 0; i < 56; i++)
		{
			if (i < 28)
				PC2_in[i] = PC1_out1[i];
			else
				PC2_in[i] = PC1_out2[i - 28];
		}
		for (int j = 0; j < 48; j++)
		{
			PC2_out.push_back(PC2_in[PC2[j]-1]);
		}
		for (int j = 0; j < 12; j++)
		{
			cout << uppercase << hex << (8*PC2_out[0] + 4 * PC2_out[1] + 2 * PC2_out[2] + PC2_out[3]);
			PC2_out.erase(PC2_out.begin());
			PC2_out.erase(PC2_out.begin());
			PC2_out.erase(PC2_out.begin());
			PC2_out.erase(PC2_out.begin());
		}
		cout << endl;
	}
	return 0;
}