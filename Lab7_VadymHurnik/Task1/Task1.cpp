#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int size, sum = 0, counter = 0;
	vector<int> a10;

	cout << "Enter size of array: ";
	cin >> size;

	a10.resize(size);

	srand(time(NULL));

	for (int i = 0; i < size; i++)
		a10[i] = rand() % 100 - 50;
}
