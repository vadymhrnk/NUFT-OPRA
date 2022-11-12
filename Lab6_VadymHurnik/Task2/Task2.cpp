#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int size, input;
	vector<int> a8;

	cout << "Enter size of array: ";
	cin >> size;

	a8.resize(size);

	cout << "Enter elments in array:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "a8[" << i + 1 << "] = ";
		cin >> a8[i];
	}

	system("cls");

	cout << "Enter number: ";
	cin >> input;


	cout << "Array a8[" << size << "] = ";

	for (int i = 0; i < size; i++)
		cout << a8[i] << " ";

	cout << endl;

	for (int i = 0; i < size; i++)
	{
		if (a8[i] < input)
			cout << "Element: " << a8[i] << " - Index: " << i << endl;
	}

	return 0;
}
