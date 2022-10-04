#include <iostream>
#include<math.h>

using namespace std;

int main()
{
	float alpha = 0;
	float Z1 = 0, Z2 = 0, Z3 = 0;

	cout << "Enter value of alpha: ";
	cin >> alpha;

	Z1 = 1 - 1 / 4 - pow(sin(2 * alpha), 2) + cos(2 * alpha);
	Z2 = pow(cos(alpha), 2) + pow(cos(alpha), 4);
	Z3 = 2 * Z1 + 1 / Z2;

	cout << "Values:\nZ1: " << Z1 <<endl<< "Z2: " << Z2<<endl<<"Z3: "<<Z3;
	return 0;
}
