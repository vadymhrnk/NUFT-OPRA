#include <iostream>
#include <iostream>
#include<math.h>

using namespace std;

int main()
{
	float sum, s, e, x, k = 1;
	int counter = 0;

	cout << "Enter x: ";
	cin >> x;

	cout << "Enter e: ";
	cin >> e;

	s = cos(pow((x), k)) / pow(k, 2);

	sum = s;
	while (fabs(s) > e)
	{
		s = cos(pow((x), k)) / pow(k, 2);
		sum = sum + s;

		k++;
		counter++;
	}

	cout << "Counter: " << counter << endl;
	cout << "Summation: " << sum << endl;

	return 0;
}