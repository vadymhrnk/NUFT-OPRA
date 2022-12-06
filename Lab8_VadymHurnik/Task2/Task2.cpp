#include <iostream>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	string str;
	int digit=0, alpha=0;

	cout << "Enter string: ";
	getline(cin, str);

	for (int i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i]))
		{
			digit++;
		}
		if (isalpha(str[i]))
		{
			alpha++;
		}
	}

	cout << "Digits count: " << digit << endl;
	cout << "Letters count: " << alpha << endl;

	return 0;
}
