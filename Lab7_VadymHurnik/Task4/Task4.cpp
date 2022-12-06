#include <iostream>

using namespace std;


int main()
{
	int g4[3][4][4];
	double avg = 0, counter = 0;
	srand(time(NULL));

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				g4[i][j][k] = rand() % 100 - 50;
				cout << g4[i][j][k] <<"\t";
				if (g4[i][j][k]>0)
				{
					avg = avg + g4[i][j][k];
					counter++;
				}
			}
			cout << endl;
		}
		cout << endl;
	}

	avg = avg / counter;
	
	cout << "Average of positives: " << avg<<endl;

	return 0;
}