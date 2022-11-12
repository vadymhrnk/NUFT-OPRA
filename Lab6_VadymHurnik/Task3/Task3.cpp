#include <iostream>

using namespace std;

int main()
{
	const int size = 5;
	int r5[size];

	cout << "Enter 5 elments in array:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "r5[" << i + 1 << "] = ";
		cin >> r5[i];
	}

	system("cls");

	cout << "Array r5[" << size << "] = ";

	for (int i = 0; i < size; i++)
	{
		cout << r5[i] << " ";
		if (r5[i] % 2 == 0)
		{
			r5[i] = i;
		}
	}

	cout << endl << "Modified array r5[" << size << "] = ";

	for (int i = 0; i < size; i++)
	{
		cout << r5[i] << " ";
	}

	return 0;
}
