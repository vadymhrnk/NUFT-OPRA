#include <iostream>
#include<math.h>

using namespace std;

int main()
{
	int number, oddCounter = 0, evenCounter = 0;

	cout << "Enter number from 1 to 10.000.000 = ";
	cin >> number;

	while (number != 0)
	{
		int current = number % 10;
		number /= 10;
		if (current % 2 == 0)
		{
			evenCounter++;
		}
		else
		{
			oddCounter++;
		}
	}

	cout << "Even digits: " << evenCounter << endl;
	cout << "Odd digits: " << oddCounter << endl;

	return 0;
}