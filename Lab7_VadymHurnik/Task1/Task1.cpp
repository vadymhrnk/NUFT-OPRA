#include <iostream>

using namespace std;

int main()
{
	const int row = 5, column = 7;
	int min = 0;
	int a10[row][column];

	srand(time(NULL));

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			a10[i][j] = rand() % 100 - 50;
			cout << a10[i][j] << "\t";
		}
		cout << endl;
	}

	min = a10[0][0];

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (a10[i][j] < min)
				min = a10[i][j];
		}

	}
	cout << "Minimum element: " << min;
	return 0;
}
