#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib> // Include the <cstdlib> header for random number generation
#include <ctime>   // Include the <ctime> header to seed the random number generator
using namespace std;

void createTextMatrixFile(const char* filename) {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    FILE* file;
    if (fopen_s(&file, filename, "w") == 0) {
        fprintf(file, "%d %d\n", rows, cols);
        srand(time(0)); // Seed the random number generator

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int value = rand() % 101 - 50; // Generate random number from -50 to 50
                fprintf(file, "%d ", value);
            }
            fprintf(file, "\n");
        }
        fclose(file);
        cout << "Text matrix file created successfully." << endl;
    }
    else {
        cout << "Error creating text matrix file." << endl;
    }
}

void createTextStringsFile(const char* filename) {
    int numStrings;
    cout << "Enter the number of strings: ";
    cin >> numStrings;

    FILE* file;
    if (fopen_s(&file, filename, "w") == 0) {
        cin.ignore();
        for (int i = 0; i < numStrings; i++) {
            string str;
            cout << "Enter string " << (i + 1) << ": ";
            getline(cin, str);
            fprintf(file, "%s\n", str.c_str());
        }
        fclose(file);
        cout << "Text strings file created successfully." << endl;
    }
    else {
        cout << "Error creating text strings file." << endl;
    }
}

void createBinaryMatrixFile(const char* filename) {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    FILE* file;
    if (fopen_s(&file, filename, "wb") == 0) {
        fwrite(&rows, sizeof(int), 1, file);
        fwrite(&cols, sizeof(int), 1, file);
        srand(time(0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int value = rand() % 101 - 50;
                fwrite(&value, sizeof(int), 1, file);
            }
        }
        fclose(file);
        cout << "Binary matrix file created successfully." << endl;
    }
    else {
        cout << "Error creating binary matrix file." << endl;
    }
}

void createBinaryColumnMatrixFile(const char* filename) {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    FILE* file;
    if (fopen_s(&file, filename, "wb") == 0) {
        fwrite(&rows, sizeof(int), 1, file);
        fwrite(&cols, sizeof(int), 1, file);
        srand(time(0));

        for (int j = 0; j < cols; j++) {
            for (int i = 0; i < rows; i++) {
                int value = rand() % 101 - 50;
                fwrite(&value, sizeof(int), 1, file);
            }
        }
        fclose(file);
        cout << "Binary column matrix file created successfully." << endl;
    }
    else {
        cout << "Error creating binary column matrix file." << endl;
    }
}

int main() {
    const int MAX_FILENAME_LENGTH = 100;
    char textMatrixFilename[MAX_FILENAME_LENGTH];
    char textStringsFilename[MAX_FILENAME_LENGTH];
    char binaryMatrixFilename[MAX_FILENAME_LENGTH];
    char binaryColumnMatrixFilename[MAX_FILENAME_LENGTH];
    cout << "Enter the name of the text matrix file: ";
    cin.getline(textMatrixFilename, MAX_FILENAME_LENGTH);

    cout << "Enter the name of the text strings file: ";
    cin.getline(textStringsFilename, MAX_FILENAME_LENGTH);

    cout << "Enter the name of the binary matrix file: ";
    cin.getline(binaryMatrixFilename, MAX_FILENAME_LENGTH);

    cout << "Enter the name of the binary column matrix file: ";
    cin.getline(binaryColumnMatrixFilename, MAX_FILENAME_LENGTH);

    createTextMatrixFile(textMatrixFilename);
    createTextStringsFile(textStringsFilename);
    createBinaryMatrixFile(binaryMatrixFilename);
    createBinaryColumnMatrixFile(binaryColumnMatrixFilename);

    return 0;
}