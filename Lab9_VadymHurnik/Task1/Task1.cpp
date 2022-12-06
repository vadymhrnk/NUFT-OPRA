#include <iostream>
#include<string>

using namespace std;

int main()
{
	const int size = 10;
	int selectYear;

	struct Student
	{
		string faculty;
		string fullName;
		int joinYear;
	};

	Student students[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Enter student #"<< i+1<<" faculty: ";
		getline(cin, students[i].faculty);
		
		cout << "Enter student #" << i + 1 << " full name: ";
		getline(cin, students[i].fullName);
		
		cout << "Enter student #" << i + 1 << " join year: ";
		cin >> students[i].joinYear;
		cin.ignore();
		cout << endl;
	}

	cout << "Enter student join year to find: ";
	cin >> selectYear;

	for (int i = 0; i < size; i++)
	{
		if (students[i].joinYear == selectYear)
		{
			cout << "Student faculty: " << students[i].faculty << endl;

			cout << "Student full name: "<< students[i].fullName<<endl;

			cout << "Student join year: " << students[i].joinYear << endl << endl;
			
		}

	}


	return 0;
}
