#include <iostream>

using namespace std;

int main()
{
	float number = 0, first = 0, second = 0;

	cout << "Enter number: ";
	cin >> number;

	first = number / 10;
	second = fmod(number, 10);

	//cout << second << endl;
	cout << second << (int)first << endl;

	if (first < second)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}

	return 0;
}
