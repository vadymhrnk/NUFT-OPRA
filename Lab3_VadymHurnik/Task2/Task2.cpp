#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double sum=0, mult = 1.0, i, j, i_start, i_end, j_start, j_end;

	cout << " start i = ";
	cin >> i_start;
	cout << " end i = ";
	cin >> i_end;
	cout << " start j = ";
	cin >> j_start;
	cout << " end j = ";
	cin >> j_end;

	for (i = i_start; i <= i_end; i++)
	{
		sum = 0;
		for (j = j_start; j <= j_end; j++)
		{
			sum = sum + (i / (i + 1));
		}
		mult = mult * (sum / sqrt(j));
	}
	cout << " Mult = " << mult << endl;

	return 0;
}
