#include <iostream>
#include <string>
#include <vector>
#include "math.h"
using namespace std;

int main()
{
	int boxsize, insize; string boxvalue; vector<int> box, output;
	cin >> boxsize;
	if (boxsize < 4 || boxsize>256 || (boxsize % 4) != 0)
	{
		cout << "ERROR input\n";
		exit(EXIT_FAILURE);
	}
	cin.ignore();
	getline(cin, boxvalue);

	for (int i = 0; i < boxvalue.length(); i++)
	{
		switch (boxvalue[i])
		{
		case ' ': case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': break;
		default: cout << "Wrong box values\n"; exit(EXIT_FAILURE);
		}
		if (boxvalue[0] == ' ')
		{
			cout << "Error start with a number not space\n"; exit(EXIT_FAILURE);
		}
		if ((boxvalue[i] == ' ') && (boxvalue[i + 1] == ' '))
		{
			cout << "Error Double space\n"; exit(EXIT_FAILURE);
		}
		if (boxvalue[boxvalue.length()] == ' ')
		{
			cout << "Error end with a number not space\n"; exit(EXIT_FAILURE);
		}
	}
	string sub; int j = 0;
	for (int i = 0; i <= boxvalue.length(); i++)
	{
		if (boxvalue[i] == ' ' || boxvalue[i] == NULL)
		{
			sub = boxvalue.substr(j, i);
			if ((atoi(sub.c_str())) < 1)
			{
				cout << "Error box values starts from 1 not 0\n"; exit(EXIT_FAILURE);
			}
			else
			{
				box.push_back(atoi(sub.c_str()));
				j = i + 1;
			}
		}
	}
	cin >> insize;
	for (int i = 0; i < box.size(); i++)
	{
		if (box[i]>insize)
		{
			cout << "Error input size is not suitable for box values\n"; exit(EXIT_FAILURE);
		}
	}

	if (insize < 4 || insize>64 || (insize % 4) != 0)
	{
		cout << "ERROR input\n";
		exit(EXIT_FAILURE);
	}
	unsigned long long input; long long out = 0;
	cin >> hex >> input;
	if (input > (unsigned long long)(pow(long double(2), insize) - 1))
	{
		cout << "ERROR input length is wrong\n";
		exit(EXIT_FAILURE);
	}

	if (insize >= boxsize)
	{
		for (int i = 0; i < boxsize; i++)
		{
			output.push_back(int(int(input & int(1 << (insize - box[i]))) >> (insize - box[i])));

		}
		for (int i = 0; i < output.size(); i++)
		{
			out += long long((output[(output.size() - 1) - i]) * long long(pow(long double(2), i)));
		}
		cout << hex << uppercase << out;
	}
	else
	{
		int size2;
		for (int i = 0; i < insize; i++)
		{
			output.push_back(int(int(input & int(1 << (insize - box[i]))) >> (insize - box[i])));
		}
		size2 = output.size();
		for (int i = 0; i < (boxsize - size2); i++)
		{
			output.push_back(output[i % size2]);
		}
		for (int i = 0; i < output.size(); i++)
		{
			out += long long((output[(output.size() - 1) - i]) * long long(pow(long double(2), i)));
		}
		cout << hex << uppercase << out;
	}


	cout << "\n";
	return 0;
}