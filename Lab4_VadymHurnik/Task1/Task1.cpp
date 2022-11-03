#include <iostream>
#include <iostream>
#include<math.h>

using namespace std;

int main()
{
	float s, e = 0, x = 0, k = 1, sum = 0;
	int counter = 0;

	cout << "Enter x: ";
	cin >> x;

	cout << "Enter e: ";
	cin >> e;

	s = cos(pow((x), k)) / pow(k, 2);

	sum = s;
	cout << "RESULT: " << s << endl;
	while (fabs(s) > e)
	{
		k++;
		s = cos(pow((x), k)) / pow(k, 2);
		sum = sum + s;
		cout << "RESULT: " << s << endl;

		counter++;
	}

	cout << "Counter: " << counter << endl;
	cout << "Summation: " << sum << endl;

	return 0;
}