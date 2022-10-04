#include <iostream>
#include<math.h>

using namespace std;

int main()
{
	float A = 0, B = 0, C = 0;

	cout << "Enter point A: ";
	cin >> A;

	cout << "Enter point B: ";
	cin >> B;

	cout << "Enter point C (must be between A and B): ";
	cin >> C;

	do
	{
		cout << "Enter valid value: ";
		cin >> C;
	} while (A>C && C>B);

	return 0;
}
