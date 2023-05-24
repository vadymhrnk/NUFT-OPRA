#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void addComma(string& str) {
	for (int i = 0; i < str.length(); i++) {
		if (isdigit(str[i]) && i + 1 < str.length() && str[i + 1] == '+') {
			str.insert(i + 1, ",");
			i += 1;
		}
	}
}

int main() {
	string inputFilename;
	string outputFilename;

	while (true) {
		cout << "Enter the input text file name (or 'stop' to exit): ";
		cin >> inputFilename;

		if (inputFilename == "stop") {
			break;
		}

		ifstream inputFile("..\\Task1\\" + inputFilename);

		if (!inputFile.is_open()) {
			cout << "Error opening input file: " << inputFilename << endl;
			continue;
		}

		cout << "Enter the output file name: ";
		cin >> outputFilename;

		ofstream outputFile(outputFilename);

		if (!outputFile.is_open()) {
			cout << "Error opening output file: " << outputFilename << endl;
			continue;
		}

		string line;
		while (getline(inputFile, line)) {
			cout << "Original string: " << line<<endl;
			addComma(line);
			cout << "Modified string: " << line<<endl;
			outputFile << line << endl;
		}

		inputFile.close();
		outputFile.close();

		cout << "Result written to file: " << outputFilename << endl;
	}

	return 0;
}
