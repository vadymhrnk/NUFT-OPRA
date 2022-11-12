//E.1 #15
#include <iostream>
#include<math.h>

using namespace std;

int main()
{
	double x, y, xStart, xEnd, xStep;

	cout << "Enter interval size:" << endl << "Start = ";
	cin >> xStart;

	cout << "End = ";
	cin >> xEnd;

	cout << "Step = ";
	cin >> xStep;

	cout << endl << "X\tY" << endl;

	x = xStart;
	do
	{
		if (x < 0)
		{
			y = pow(x, 2) / 2 + 5 + pow(tan(x), 2);
		}
		else
		{
			y = sin(x) + pow(x, 2);
		}
		cout << x << "\t" << y << endl;

		x = x + xStep;
	} while (x <= xEnd);

	return 0;
}
