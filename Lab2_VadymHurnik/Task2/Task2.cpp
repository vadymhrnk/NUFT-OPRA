#include <iostream>
#include<math.h>

using namespace std;

int main()
{
	float A = 0, B = 0, C = 0, D = 0, x1 = 0, x2 = 0;

	cout << "Enter A: ";
	cin >> A;

	while (A == 0)
	{
		cout << "Re enter A: ";
		cin >> A;
	}

	cout << "Enter B: ";
	cin >> B;
	cout << "Enter C: ";
	cin >> C;

	D = pow(B, 2) - 4 * A * C;

	x1 = (-B + sqrt(D) / (2 * A));
	x2 = (-B - sqrt(D) / (2 * A));

	if (x1>x2)
	{
		cout << "x1 = : " << x1 << endl;
		cout << "x2 = : " << x2 << endl;
	}
	else
	{
		cout << "x2 = : " << x2 << endl;
		cout << "x1 = : " << x1 << endl;

	}


	return 0;
}
