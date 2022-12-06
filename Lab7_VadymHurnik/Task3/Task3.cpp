#include<iostream>

using namespace std;

int main()
{
	const int row = 7, column = 7;
	int a4[row][column];

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

	cout << "Average: ";

	for (int i = 0; i < row; i++)
	{
		int counter = 0;
		double avg = 0;
		for (int j = 0; j < column; j++)
		{
			if (j >= i && i <= row - 1 && j <= column - 1 - i)
			{
				avg = avg + a4[i][j];
				counter++;
			}
		}
		if (counter != 0)
		{
			avg = avg / counter;
			cout << avg << " ";
		}
	}

	return 0;
}
