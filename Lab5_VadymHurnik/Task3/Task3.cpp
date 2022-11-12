#include <iostream>
#include<math.h>

using namespace std;

int main()
{
	float sum, s, e, x, n = 1;
	int counter = 0;

	cout << "Enter x: ";
	cin >> x;

	cout << "Enter e: ";
	cin >> e;

	s = pow(-1, n) / (pow(n, 3) + 3);
	sum = s;

	float lim = 1 / (pow(n, 3) + 3);

	do
	{
		lim = 1 / (pow(n, 3) + 3);

		s = pow(-1, n) / (pow(n, 3) + 3);
		sum = sum + s;

		n++;
		counter++;
	} while (lim > e);

	cout << "Counter: " << counter << endl;
	cout << "Summation: " << sum << endl;

	return 0;
}