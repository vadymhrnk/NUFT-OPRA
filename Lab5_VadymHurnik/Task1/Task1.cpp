#include <iostream>
#include<math.h>

using namespace std;

int main()
{
	double sum = 0, mult = 1.0, i_start, i_end, j_start, j_end, x;


	cout << "Start i = ";
	cin >> i_start;
	cout << "End i = ";
	cin >> i_end;
	cout << "Start j = ";
	cin >> j_start;
	cout << "End j = ";
	cin >> j_end;
	cout << "Enter variable x = ";
	cin >> x;

	int i = i_start - 1;
	do
	{
		i++;
		sum = sum + (i * sin(i));
	} while (i <= i_end);

	int j = j_start - 1;
	do
	{
		j++;
		mult = mult * (pow(sin(x * j), 2) + 2 * exp(-x + j));
	} while (j <= j_end);

	double P = sqrt(5.32 * 2.51) * sum + mult;

	cout << "Summation: " << sum << endl;
	cout << "Multiplication: " << mult << endl;
	cout << "Result: " << P << endl;

	return 0;
}
