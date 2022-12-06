#include <iostream>
#include<string>

using namespace std;

int main()
{
	string str;
	char symbol;
	int counter = 0, i;

	cout << "Enter string: ";
	getline(cin, str);

	cout << "Enter symbol to find: ";
	cin >> symbol;

	cout << "Enter start point: ";
	cin >> i;

	for (i; i < str.size(); i++)
	{
		if (str[i] == symbol)
		{
			counter++;
		}
	}

	cout << "Entered characters found: " << counter << endl;

	return 0;
}
