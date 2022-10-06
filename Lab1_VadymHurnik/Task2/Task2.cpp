#include <iostream>

using namespace std;

int main()
{
	float A = 0, B = 0, C = 0;
	float sizeProduct = 0;

	cout << "Enter point A: ";
	cin >> A;

	cout << "Enter point B: ";
	cin >> B;

	cout << "Enter point C (between A and B): ";
	cin >> C;

	while (C > B && C > A || C < B && C < A)
	{
		cout << "Re enter point C: ";
		cin >> C;
	}

	if (B > C && C > A)
	{
		sizeProduct = (B - C) * (C - A);
	}
	else if (A > C && C > B)
	{
		sizeProduct = (A - C) * (C - B);
	}
	cout << "Product: " << sizeProduct;

	return 0;
}
