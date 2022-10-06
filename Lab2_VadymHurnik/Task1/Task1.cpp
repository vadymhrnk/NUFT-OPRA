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

	y = x * y > 0 ? a = pow((x + y), 2) - sqrt(x * y) : x * y < 0 ? a = pow((x + y), 2) + sqrt(x * y) : a = pow((x + y), 2) + 1;
	cout << "Result: " << a << endl;

	return 0;
}
