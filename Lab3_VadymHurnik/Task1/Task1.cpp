#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	float x, y, xStart, xEnd, xStep;

	cout << "Enter interval size:" << endl << "Start = ";
	cin >> xStart;

	cout << "End = ";
	cin >> xEnd;

	cout << "Step = ";
	cin >> xStep;

	cout << endl << "X\tY" << endl;

	for (x = xStart; x <= xEnd; x += xStep)
	{
		if (x > 10)
		{
			y = pow(exp(1), -x + 1 + x * sin(5 * x));
		}
		else if (x <= 10)
		{
			y = pow(log(abs(x)), 2) - cbrt(x);
		}
		else
		{
			cout << "Incorrect values!";
		}
		cout << x << "\t" << y << endl;
	}

	return 0;
}
