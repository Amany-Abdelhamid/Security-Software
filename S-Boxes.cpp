#include <iostream>
#include <string>
#include <vector>

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

	 string in; vector<int> binary;
	getline(cin, in);
	if (in.length() != 12)
	{
		cout << "ERROR input length is wrong\n";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < in.length(); i++)
	{
		switch (in[i])
		{
		case '0':binary.push_back(0); binary.push_back(0); binary.push_back(0); binary.push_back(0); break;
		case '1':binary.push_back(0); binary.push_back(0); binary.push_back(0); binary.push_back(1); break;
		case '2': binary.push_back(0); binary.push_back(0); binary.push_back(1); binary.push_back(0); break;
		case '3':binary.push_back(0); binary.push_back(0); binary.push_back(1); binary.push_back(1); break;
		case '4':binary.push_back(0); binary.push_back(1); binary.push_back(0); binary.push_back(0); break;
		case '5':binary.push_back(0); binary.push_back(1); binary.push_back(0); binary.push_back(1); break;
		case '6':binary.push_back(0); binary.push_back(1); binary.push_back(1); binary.push_back(0); break;
		case '7':binary.push_back(0); binary.push_back(1); binary.push_back(1); binary.push_back(1); break;
		case '8':binary.push_back(1); binary.push_back(0); binary.push_back(0); binary.push_back(0); break;
		case '9':binary.push_back(1); binary.push_back(0); binary.push_back(0); binary.push_back(1); break;
		case'A':binary.push_back(1); binary.push_back(0); binary.push_back(1); binary.push_back(0); break;
		case'B':binary.push_back(1); binary.push_back(0); binary.push_back(1); binary.push_back(1); break;
		case 'C':binary.push_back(1); binary.push_back(1); binary.push_back(0); binary.push_back(0); break;
		case'D':binary.push_back(1); binary.push_back(1); binary.push_back(0); binary.push_back(1); break;
		case'E':binary.push_back(1); binary.push_back(1); binary.push_back(1); binary.push_back(0); break;
		case'F':binary.push_back(1); binary.push_back(1); binary.push_back(1); binary.push_back(1); break;
		default: cout << "Wrong Input\n"; exit(EXIT_FAILURE);
		}
		
	}
	
	int row, col;
	row = binary[5] + (binary[0] * 2);
	col = binary[4] + (binary[3] * 2) + (binary[2] * 4) + (binary[1] * 8);
	cout << hex << uppercase << s1[row][col];

	row = binary[11] + (binary[6] * 2);
	col = binary[10] + (binary[9] * 2) + (binary[8] * 4) + (binary[7] * 8);
	cout << hex << uppercase << s2[row][col];

	row = binary[17] + (binary[12] * 2);
	col = binary[16] + (binary[15] * 2) + (binary[14] * 4) + (binary[13] * 8);
	cout << hex << uppercase << s3[row][col];

	row = binary[23] + (binary[18] * 2);
	col = binary[22] + (binary[21] * 2) + (binary[20] * 4) + (binary[19] * 8);
	cout << hex << uppercase << s4[row][col];

	row = binary[29] + (binary[24] * 2);
	col = binary[28] + (binary[27] * 2) + (binary[26] * 4) + (binary[25] * 8);
	cout << hex << uppercase << s5[row][col];

	row = binary[35] + (binary[30] * 2);
	col = binary[34] + (binary[33] * 2) + (binary[32] * 4) + (binary[31] * 8);
	cout << hex << uppercase << s6[row][col];

	row = binary[41] + (binary[36] * 2);
	col = binary[40] + (binary[39] * 2) + (binary[38] * 4) + (binary[37] * 8);
	cout << hex << uppercase << s7[row][col];
	
	row = binary[47] + (binary[42] * 2);
	col = binary[46] + (binary[45] * 2) + (binary[44] * 4) + (binary[43] * 8);
	cout << hex << uppercase << s8[row][col];

	cout << "\n";
	return 0;
}