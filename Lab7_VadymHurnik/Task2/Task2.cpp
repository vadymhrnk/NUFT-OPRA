#include <iostream>

using namespace std;

int main()
{
	const int row = 5, column = 7, size = 5;
	int v35[row][column];
	int arr[size]{ 0,0,0,0,0 };

	srand(time(NULL));

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			v35[i][j] = rand() % 100 - 50;
			cout << v35[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "Summation of positive elements of diagonals that above main diagonal: ";

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (j > i && v35[i][j] > 0)
			{
				arr[i] = arr[i] + v35[i][j];
			}
		}
		cout << arr[i] << " ";
	}

	return 0;
}
