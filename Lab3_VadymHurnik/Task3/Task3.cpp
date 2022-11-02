#include <iostream>

using namespace std;

int main()
{
	float start = 0, end = 0, mult=1;
	int counter = 0;

	cout << "Enter start of range: ";
	cin >> start;
	cout << "Enter end of range: ";
	cin >> end;

	cout << "Numbers that divide by 3: ";
	for (int i = start; i < end; i++)
	{
		if ((i % 3) == 0)
		{
			counter++;
			mult = mult * i;
			cout << i << ", ";
		}
	}
	cout <<";" << endl;

	cout << "Multiplication of numbers that divide by 3: " << mult << endl;
	cout << "Quantity of numbers that divide by 3: " << counter << endl;
	return 0;
}