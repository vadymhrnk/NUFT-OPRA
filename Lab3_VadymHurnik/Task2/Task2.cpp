#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	const double A = 2.5, B = 5.4;
	double sum, mult, i, j, i_start, i_end, j_start, j_end;
	cout << " start i = ";
	cin >> i_start;
	cout << " end i = ";
	cin >> i_end;
	cout << " start j = ";
	cin >> j_start;
	cout << " end j = ";
	cin >> j_end;
	sum = 0;
	for (i = i_start; i <= i_end; i++)
	{
		mult = 1;
		for (j = j_start; j <= j_end; j++)
		{
			mult = mult * (A * (i + j));
		}
		sum = sum + mult / (B * i);
	}
	cout << " Sum = " << sum << endl;

	return 0;
}
