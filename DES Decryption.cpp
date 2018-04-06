#include <iostream>
#include <string>
#include "ctype.h"
#include <vector>
#include "math.h"
using namespace std;

int main()
{
	int PC1[56] = { 57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36,
		63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4 };

	int	PC2[48] = { 14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47,
		55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32 };

	int	Rotations[16] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };

	int s1[4][16] = { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
		0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
		4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
		15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 };

	int s2[4][16] = { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
		3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
		0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
		13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 };

	int s3[4][16] = { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
		13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
		13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
		1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 };

	int s4[4][16] = { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
		13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
		10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
		3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 };

	int s5[4][16] = { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
		14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
		4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
		11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 };

	int s6[4][16] = { 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
		10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
		9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
		4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 };

	int s7[4][16] = { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
		13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
		1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
		6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 };

	int s8[4][16] = { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
		1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
		7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
		2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 };

	int ex_box[48] = { 32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9,
		8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17,
		16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25,
		24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1 };

	int p_box[32] = { 16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10,
		2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25 };

	int init_p[64] = { 58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4,
		62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8,
		57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3,
		61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7 };

	int fin_p[64] = { 40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31,
		38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29,
		36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27,
		34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25 };

	//kEY GENERATION
	string key; vector<int> key_bin1, PC1_out1, PC1_out2; int PC2_in[56] = { 0 }, Key[16][48] = { 0 };
	getline(cin, key);
	if (key.length() != 16)
	{
		cout << "ERROR input is not 64 bit in hex.\n";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < key.length(); i++)
	{
		if (!(key[i] > 47 && key[i] < 58) && !(key[i] > 64 && key[i] < 71))
		{
			cout << "ERROR input " << key[i] << endl;
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
		for (int k = 0; k < 56; k++)
		{
			if (k < 28)
				PC2_in[k] = PC1_out1[k];
			else
				PC2_in[k] = PC1_out2[k - 28];
		}
		for (int j = 0; j < 48; j++)
		{
			Key[i][j] = PC2_in[PC2[j] - 1];
		}
	}

	//DES STRUCTURE
	string Ciphertext; vector<int> ciphertext; int round_in[64] = { 0 };
	getline(cin, Ciphertext);
	if (Ciphertext.length() != 16)
	{
		cout << "ERROR input is not 64 bit in hex.\n";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < Ciphertext.length(); i++)
	{
		if (!(Ciphertext[i] > 47 && Ciphertext[i] < 58) && !(Ciphertext[i] > 64 && Ciphertext[i] < 71))
		{
			cout << "ERROR input " << Ciphertext[i] << endl;
			exit(EXIT_FAILURE);
		}
	}
	for (int i = 0; i < Ciphertext.length(); i++)
	{
		switch (Ciphertext[i])
		{
		case '0':{ciphertext.push_back(0); ciphertext.push_back(0); ciphertext.push_back(0); ciphertext.push_back(0); break; }
		case '1':{ciphertext.push_back(0); ciphertext.push_back(0); ciphertext.push_back(0); ciphertext.push_back(1); break; }
		case '2':{ciphertext.push_back(0); ciphertext.push_back(0); ciphertext.push_back(1); ciphertext.push_back(0); break; }
		case '3':{ciphertext.push_back(0); ciphertext.push_back(0); ciphertext.push_back(1); ciphertext.push_back(1); break; }
		case '4':{ciphertext.push_back(0); ciphertext.push_back(1); ciphertext.push_back(0); ciphertext.push_back(0); break; }
		case '5':{ciphertext.push_back(0); ciphertext.push_back(1); ciphertext.push_back(0); ciphertext.push_back(1); break; }
		case '6':{ciphertext.push_back(0); ciphertext.push_back(1); ciphertext.push_back(1); ciphertext.push_back(0); break; }
		case '7':{ciphertext.push_back(0); ciphertext.push_back(1); ciphertext.push_back(1); ciphertext.push_back(1); break; }
		case '8':{ciphertext.push_back(1); ciphertext.push_back(0); ciphertext.push_back(0); ciphertext.push_back(0); break; }
		case '9':{ciphertext.push_back(1); ciphertext.push_back(0); ciphertext.push_back(0); ciphertext.push_back(1); break; }
		case 'A':{ciphertext.push_back(1); ciphertext.push_back(0); ciphertext.push_back(1); ciphertext.push_back(0); break; }
		case 'B':{ciphertext.push_back(1); ciphertext.push_back(0); ciphertext.push_back(1); ciphertext.push_back(1); break; }
		case 'C':{ciphertext.push_back(1); ciphertext.push_back(1); ciphertext.push_back(0); ciphertext.push_back(0); break; }
		case 'D':{ciphertext.push_back(1); ciphertext.push_back(1); ciphertext.push_back(0); ciphertext.push_back(1); break; }
		case 'E':{ciphertext.push_back(1); ciphertext.push_back(1); ciphertext.push_back(1); ciphertext.push_back(0); break; }
		case 'F':{ciphertext.push_back(1); ciphertext.push_back(1); ciphertext.push_back(1); ciphertext.push_back(1); break; }

		}
	}

	//Run Decryption N Times
	int N;
	cin >> N;
	if (N<0 || N>1000)
	{
		cout << "ERROR N is not in range of (0-1000).\n";
		exit(EXIT_FAILURE);
	}

	vector<int> ex_out, xor_out, s_out, in_pbox;
	int right[32] = { 0 }, left[32] = { 0 }, box_out[32] = { 0 }, round_out[64] = { 0 }, swapped[64] = { 0 }, output[64] = { 0 }, z, row, col;

	for (int t = 0; t < N; t++)
	{
		//Initial Permutation
		for (int i = 0; i < 64; i++)
			round_in[i] = ciphertext[init_p[i] - 1];

		//ROUND IMPLEMENTATION

		for (int r = 15; r >= 0; r--)
		{
			for (int i = 0; i < 64; i++)
			{
				if (i < 32)
					left[i] = round_in[i];
				else
					right[i - 32] = round_in[i];
			}
			for (int i = 0; i < 32; i++)
				round_out[i] = right[i];

			for (int i = 0; i < 48; i++)
			{
				ex_out.push_back(right[(ex_box[i]) - 1]);
			}

			for (int i = 0; i < 48; i++)
			{
				z = ex_out[i] ^ Key[r][i];
				xor_out.push_back(z);
			}

			row = xor_out[5] + (xor_out[0] * 2);
			col = xor_out[4] + (xor_out[3] * 2) + (xor_out[2] * 4) + (xor_out[1] * 8);
			s_out.push_back(s1[row][col]);

			row = xor_out[11] + (xor_out[6] * 2);
			col = xor_out[10] + (xor_out[9] * 2) + (xor_out[8] * 4) + (xor_out[7] * 8);
			s_out.push_back(s2[row][col]);

			row = xor_out[17] + (xor_out[12] * 2);
			col = xor_out[16] + (xor_out[15] * 2) + (xor_out[14] * 4) + (xor_out[13] * 8);
			s_out.push_back(s3[row][col]);

			row = xor_out[23] + (xor_out[18] * 2);
			col = xor_out[22] + (xor_out[21] * 2) + (xor_out[20] * 4) + (xor_out[19] * 8);
			s_out.push_back(s4[row][col]);

			row = xor_out[29] + (xor_out[24] * 2);
			col = xor_out[28] + (xor_out[27] * 2) + (xor_out[26] * 4) + (xor_out[25] * 8);
			s_out.push_back(s5[row][col]);

			row = xor_out[35] + (xor_out[30] * 2);
			col = xor_out[34] + (xor_out[33] * 2) + (xor_out[32] * 4) + (xor_out[31] * 8);
			s_out.push_back(s6[row][col]);

			row = xor_out[41] + (xor_out[36] * 2);
			col = xor_out[40] + (xor_out[39] * 2) + (xor_out[38] * 4) + (xor_out[37] * 8);
			s_out.push_back(s7[row][col]);

			row = xor_out[47] + (xor_out[42] * 2);
			col = xor_out[46] + (xor_out[45] * 2) + (xor_out[44] * 4) + (xor_out[43] * 8);
			s_out.push_back(s8[row][col]);

			for (int i = 0; i < s_out.size(); i++)
			{
				switch (s_out[i])
				{
				case 0: in_pbox.push_back(0); in_pbox.push_back(0); in_pbox.push_back(0); in_pbox.push_back(0); break;
				case 1: in_pbox.push_back(0); in_pbox.push_back(0); in_pbox.push_back(0); in_pbox.push_back(1); break;
				case 2: in_pbox.push_back(0); in_pbox.push_back(0); in_pbox.push_back(1); in_pbox.push_back(0); break;
				case 3: in_pbox.push_back(0); in_pbox.push_back(0); in_pbox.push_back(1); in_pbox.push_back(1); break;
				case 4: in_pbox.push_back(0); in_pbox.push_back(1); in_pbox.push_back(0); in_pbox.push_back(0); break;
				case 5: in_pbox.push_back(0); in_pbox.push_back(1); in_pbox.push_back(0); in_pbox.push_back(1); break;
				case 6: in_pbox.push_back(0); in_pbox.push_back(1); in_pbox.push_back(1); in_pbox.push_back(0); break;
				case 7: in_pbox.push_back(0); in_pbox.push_back(1); in_pbox.push_back(1); in_pbox.push_back(1); break;
				case 8: in_pbox.push_back(1); in_pbox.push_back(0); in_pbox.push_back(0); in_pbox.push_back(0); break;
				case 9: in_pbox.push_back(1); in_pbox.push_back(0); in_pbox.push_back(0); in_pbox.push_back(1); break;
				case 10: in_pbox.push_back(1); in_pbox.push_back(0); in_pbox.push_back(1); in_pbox.push_back(0); break;
				case 11: in_pbox.push_back(1); in_pbox.push_back(0); in_pbox.push_back(1); in_pbox.push_back(1); break;
				case 12: in_pbox.push_back(1); in_pbox.push_back(1); in_pbox.push_back(0); in_pbox.push_back(0); break;
				case 13: in_pbox.push_back(1); in_pbox.push_back(1); in_pbox.push_back(0); in_pbox.push_back(1); break;
				case 14: in_pbox.push_back(1); in_pbox.push_back(1); in_pbox.push_back(1); in_pbox.push_back(0); break;
				case 15: in_pbox.push_back(1); in_pbox.push_back(1); in_pbox.push_back(1); in_pbox.push_back(1); break;
				default: cout << "Wrong Input\n"; exit(EXIT_FAILURE);
				}
			}
			for (int i = 0; i < 32; i++)
			{
				box_out[i] = in_pbox[(p_box[i]) - 1];
			}
			for (int i = 0; i < 32; i++)
			{
				round_out[i + 32] = left[i] ^ box_out[i];
			}
			memcpy(round_in, round_out, sizeof(round_in));
			ex_out.clear(); xor_out.clear(); s_out.clear(); in_pbox.clear();
		}
		//Swapping
		for (int i = 0; i < 64; i++)
		{
			if (i < 32)
				swapped[i] = round_out[i + 32];
			else
				swapped[i] = round_out[i - 32];
		}
		for (int i = 0; i < 64; i++)
			output[i] = swapped[fin_p[i] - 1];

		if (t != (N - 1))
		{
			ciphertext.clear();
			for (int i = 0; i < 64; i++)
				ciphertext.push_back(output[i]);
		}
	}

	//Print Ciphertext
	if (N == 0)
	{
		for (int i = 0; i < 64; i = i + 4)
		{
			cout << hex << uppercase << (ciphertext[i] * 8 + ciphertext[i + 1] * 4 + ciphertext[i + 2] * 2 + ciphertext[i + 3]);
		}
		cout << endl;
	}
	else
	{
		for (int i = 0; i < 64; i = i + 4)
		{
			cout << hex << uppercase << (output[i] * 8 + output[i + 1] * 4 + output[i + 2] * 2 + output[i + 3]);
		}
		cout << endl;
	}
	return 0;
}



