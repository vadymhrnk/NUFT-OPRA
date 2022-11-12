#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int size, sum = 0, counter = 0;
	vector<int> a4;

	cout << "Enter size of array: ";
	cin >> size;

	a4.resize(size);

	srand(time(NULL));

	for (int i = 0; i < size; i++)
		a4[i] = rand() % 100 - 50;

	cout << "Array a4[" << size << "] = ";

	for (int i = 0; i < size; i++)
	{
		cout << " " << a4[i] << " ";
		if ((a4[i] % 2) == 0 && a4[i] > 0)
		{
			sum = sum + a4[i];
			counter++;
		}
	}

	cout << endl << "Summation: " << sum << endl;
	cout << "Counter: " << counter << endl;

	return 0;
}
