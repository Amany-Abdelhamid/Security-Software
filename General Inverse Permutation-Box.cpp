#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int in_size , out_size; string boxvalue; vector<int> box, output;
	cin >> in_size >> out_size;
	if (in_size < 1 || out_size > 128)
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
	
	for (int i = 0; i < box.size(); i++)
	{
		if (box[i] < 1 || box[i] > in_size)
		{
			cout << "ERROR input\n";
			exit(EXIT_FAILURE);
		}
	}
	if (box.size() != out_size)
	{
		cout << "ERROR input\n";
		exit(EXIT_FAILURE);
	}

	//non reversible box
	int flagr = 0, flago = 0;
	for (int i = 1; i <= in_size; i++)
	{
		for (int j = 0; j < box.size(); j++)
		{
			if (box[j] == i)
			{
				flagr = 1;
				break;
			}
		}
		if (!flagr) { cout << "IMPOSSIBLE" << endl; flago = 1; break; }
		flagr = 0;
	}
	if (!flago)
	{
		for (int i = 0; i < in_size; i++)
		{
			output.push_back(0);
		}
		//find repeated values in permutation box
		int flag = 0; output[box[0] - 1] = 1;
		for (int i = 1; i < box.size(); i++)
		{
			for (int k = 0; k < i; k++)
			{
				if (box[i] == box[k])
				{
					flag = 1;
					break;
				}
			}
			if (!flag) output[box[i] - 1] = i + 1;
			flag = 0;
		}

		for (int i = 0; i < output.size(); i++)
		{
			if (i != (output.size() - 1))
				cout << output[i] << " ";
			else
				cout << output[i];
		}

		cout << "\n";
	}
	return 0;
}