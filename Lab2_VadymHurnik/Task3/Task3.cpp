#include <iostream>
#include<math.h>

using namespace std;

int main()
{
	int number = 0;

	cout << "PRESS \"0\" TO EXIT!" << endl;

	do
	{
		cout << "Enter number of month: ";
		cin >> number;

		switch (number)
		{
		case 1:
			cout << "January: 31" << endl;
			break;
		case 2:
			cout << "February: 28" << endl;
			break;
		case 3:
			cout << "March: 31" << endl;
			break;
		case 4:
			cout << "April: 30" << endl;
			break;
		case 5:
			cout << "May: 31" << endl;
			break;
		case 6:
			cout << "June: 30" << endl;
			break;
		case 7:
			cout << "July: 31" << endl;
			break;
		case 8:
			cout << "August: 31" << endl;
			break;
		case 9:
			cout << "September: 30" << endl;
			break;
		case 10:
			cout << "October: 31" << endl;
			break;
		case 11:
			cout << "November: 30" << endl;
			break;
		case 12:
			cout << "December: 31" << endl;
			break;
		case 0:
			cout << "Quitting..." << endl;
			break;
		default:
			cout << "Incorrect value. Try again. " << endl;
			break;
		}
	} while (number != 0);

}
