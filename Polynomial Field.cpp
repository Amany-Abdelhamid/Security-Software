#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int x, y; int z[8] = { 0 }; int sum, multiply=0;
	cin >> hex >> x >> hex >> y;

	sum = x^y;

	z[0] = x; 
	for (int i = 1; i < 8; i++)
	{
		if ((z[i - 1] & 128) == 0)
			z[i] = (z[i - 1] << 1) & 255;
		else
			z[i] = ((z[i - 1] << 1) & 255) ^ 27;
	}
	for (int i = 0; i < 8; i++)
	{
		if (((y >> i) & 1) == 1)
			multiply = multiply ^ z[i];
	}

	cout << uppercase << hex << setw(2) << setfill('0') << sum << " " << uppercase << hex << setw(2) << setfill('0') << multiply;
	cout << endl;
	return 0;
}