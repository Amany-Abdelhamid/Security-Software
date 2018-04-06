#include <iostream>
#include <string>
#include <vector>
#include "math.h"
using namespace std;

int main()
{
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

	string in,key; vector<int> in_bin,key_bin,ex_out,xor_out,s_out,in_pbox,out;
	getline(cin, in);
	if (in.length() != 8)
	{
		cout << "ERROR input length is wrong\n";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < in.length(); i++)
	{
		switch (in[i])
		{
		case '0':in_bin.push_back(0); in_bin.push_back(0); in_bin.push_back(0); in_bin.push_back(0); break;
		case '1':in_bin.push_back(0); in_bin.push_back(0); in_bin.push_back(0); in_bin.push_back(1); break;
		case '2': in_bin.push_back(0); in_bin.push_back(0); in_bin.push_back(1); in_bin.push_back(0); break;
		case '3':in_bin.push_back(0); in_bin.push_back(0); in_bin.push_back(1); in_bin.push_back(1); break;
		case '4':in_bin.push_back(0); in_bin.push_back(1); in_bin.push_back(0); in_bin.push_back(0); break;
		case '5':in_bin.push_back(0); in_bin.push_back(1); in_bin.push_back(0); in_bin.push_back(1); break;
		case '6':in_bin.push_back(0); in_bin.push_back(1); in_bin.push_back(1); in_bin.push_back(0); break;
		case '7':in_bin.push_back(0); in_bin.push_back(1); in_bin.push_back(1); in_bin.push_back(1); break;
		case '8':in_bin.push_back(1); in_bin.push_back(0); in_bin.push_back(0); in_bin.push_back(0); break;
		case '9':in_bin.push_back(1); in_bin.push_back(0); in_bin.push_back(0); in_bin.push_back(1); break;
		case'A':in_bin.push_back(1); in_bin.push_back(0); in_bin.push_back(1); in_bin.push_back(0); break;
		case'B':in_bin.push_back(1); in_bin.push_back(0); in_bin.push_back(1); in_bin.push_back(1); break;
		case 'C':in_bin.push_back(1); in_bin.push_back(1); in_bin.push_back(0); in_bin.push_back(0); break;
		case'D':in_bin.push_back(1); in_bin.push_back(1); in_bin.push_back(0); in_bin.push_back(1); break;
		case'E':in_bin.push_back(1); in_bin.push_back(1); in_bin.push_back(1); in_bin.push_back(0); break;
		case'F':in_bin.push_back(1); in_bin.push_back(1); in_bin.push_back(1); in_bin.push_back(1); break;
		default: cout << "Wrong Input\n"; exit(EXIT_FAILURE);
		}
	}
	for (int i = 0; i < 48; i++)
	{
		ex_out.push_back(in_bin[(ex_box[i]) - 1]);
	}

	getline(cin, key);
	if (key.length() != 12)
	{
		cout << "ERROR key length is wrong\n";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < key.length(); i++)
	{
		switch (key[i])
		{
		case '0':key_bin.push_back(0); key_bin.push_back(0); key_bin.push_back(0); key_bin.push_back(0); break;
		case '1':key_bin.push_back(0); key_bin.push_back(0); key_bin.push_back(0); key_bin.push_back(1); break;
		case '2': key_bin.push_back(0); key_bin.push_back(0); key_bin.push_back(1); key_bin.push_back(0); break;
		case '3':key_bin.push_back(0); key_bin.push_back(0); key_bin.push_back(1); key_bin.push_back(1); break;
		case '4':key_bin.push_back(0); key_bin.push_back(1); key_bin.push_back(0); key_bin.push_back(0); break;
		case '5':key_bin.push_back(0); key_bin.push_back(1); key_bin.push_back(0); key_bin.push_back(1); break;
		case '6':key_bin.push_back(0); key_bin.push_back(1); key_bin.push_back(1); key_bin.push_back(0); break;
		case '7':key_bin.push_back(0); key_bin.push_back(1); key_bin.push_back(1); key_bin.push_back(1); break;
		case '8':key_bin.push_back(1); key_bin.push_back(0); key_bin.push_back(0); key_bin.push_back(0); break;
		case '9':key_bin.push_back(1); key_bin.push_back(0); key_bin.push_back(0); key_bin.push_back(1); break;
		case'A':key_bin.push_back(1); key_bin.push_back(0); key_bin.push_back(1); key_bin.push_back(0); break;
		case'B':key_bin.push_back(1); key_bin.push_back(0); key_bin.push_back(1); key_bin.push_back(1); break;
		case 'C':key_bin.push_back(1); key_bin.push_back(1); key_bin.push_back(0); key_bin.push_back(0); break;
		case'D':key_bin.push_back(1); key_bin.push_back(1); key_bin.push_back(0); key_bin.push_back(1); break;
		case'E':key_bin.push_back(1); key_bin.push_back(1); key_bin.push_back(1); key_bin.push_back(0); break;
		case'F':key_bin.push_back(1); key_bin.push_back(1); key_bin.push_back(1); key_bin.push_back(1); break;
		default: cout << "Wrong Input\n"; exit(EXIT_FAILURE);
		}
	}

	int z;
	for (int i = 0; i < 48; i++)
	{
		z = ex_out[i] ^ key_bin[i];
		xor_out.push_back(z);
	}
	
	int row, col;
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
		out.push_back(in_pbox[(p_box[i]) - 1]);
	}
	int output;
	for (int i = 0; i < 32; i = i + 4)
	{
		output = out[i + 3] + (out[i + 2] * 2) + (out[i + 1] * 4) + (out[i] * 8);
		cout << hex << uppercase << output;
	}
	cout << "\n";
	return 0;
}