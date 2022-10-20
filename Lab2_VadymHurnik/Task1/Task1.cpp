#include <iostream>
#include<math.h>

using namespace std;

int main()
{
	float x = 0, y = 0, a = 0;

	cout << "Enter X: ";
	cin >> x;
	cout << "Enter Y: ";
	cin >> y;
	/*
	if (y = x * y > 0)
	{
		a = pow((x + y), 2) - sqrt(x * y);
	}
	else if (x * y < 0)
	{
		a = pow((x + y), 2) + sqrt(x * y);
	}
	else {
		a = pow((x + y), 2) + 1;
	}
	*/
	a = x * y > 0 ? pow((x + y), 2) - sqrt(x * y) : x * y < 0 ? pow((x + y), 2) + sqrt(x * y) : pow((x + y), 2) + 1;

	cout << "Result: " << a << endl;

	return 0;
}
