#include <iostream>

using namespace std;

int main()
{
	const int size = 5;
	int min = 0;
	int a10[size][size];

	srand(time(NULL));

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			a10[i][j] = rand() % 100 - 50;
			cout << a10[i][j] << "\t";
		}
		cout << endl;
	}

	min = a10[0][0];

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (a10[i][j] < min)
				min = a10[i][j];
		}

	}
	cout << "Minimum element: " << min;
	return 0;
}
