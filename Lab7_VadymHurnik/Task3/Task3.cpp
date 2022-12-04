#include <iostream>

using namespace std;


int main()
{
	const int row = 7, column = 7;
	int a4[row][column];
	int avg[row][column];

	srand(time(NULL));

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			a4[i][j] = rand() % 100 - 50;
			cout << a4[i][j] << "\t";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (j >= i && i <= row - 1 && j <= column - 1 - i)
			{
				cout << a4[i][j] <<"\t";
				avg[i][j] = a4[i][j];

			}
		}
		cout << endl;
	}

	return 0;
}
