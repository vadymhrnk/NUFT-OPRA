#include<iostream>
#include <vector>

using namespace std;

int main()
{
	int size;
	vector<int> c3;

	cout << "Enter size of array: ";
	cin >> size;

	c3.resize(size);

	c3[0] = 0;
	c3[1] = 1;

	for (int i = 2; i < size; i++)
		c3[i] = c3[i - 1] + c3[i - 2];

	cout << "Fibonacci numbers: ";
	for (int i = 0; i < size; i++)
		cout << c3[i] << " ";

	return 0;
}