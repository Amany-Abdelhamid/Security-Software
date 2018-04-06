#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int boxsize; string boxvalue; vector<int> box, output;
	cin >> boxsize;
	/*if (boxsize < 4 || (boxsize % 4) != 0)
	{
		cout << "ERROR input\n";
		exit(EXIT_FAILURE);
	}*/
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
	if (box.size() != boxsize)
	{
		cout << "ERROR input\n";
		exit(EXIT_FAILURE);
	}
	int flag = 0;
	for (int i = 0; i<box.size(); i++)
	{
		for (int k = i+1; k<box.size(); k++){
			if (box[i] == box[k])
			{
				flag = 1;
				break;
				
			}
			if(flag)break;
		}
	}
	output.resize(box.size());
	
	for (int i = 0; i < box.size(); i++)
	{
		for (int k = 0; k < box.size(); k++)
		{
			if ((k+1) == box[i])
			{
				output[k] = i+1;
				break;
			}
		}
		
	}
	if (flag)
	{
		cout << "IMPOSSIBLE";
	}
	else
	{
		for (int i = 0; i < output.size(); i++)
		{
			if (i != (output.size() - 1))
				cout << output[i] << " ";
			else
				cout << output[i];
		}
	}


	cout << "\n";
	return 0;
}