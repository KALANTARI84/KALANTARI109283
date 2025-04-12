#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ifstream inputFile("students1000.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    vector<double> studentAverages;
    string line;
    double totalSum = 0.0;
    int studentCount = 0;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        string name;
        int grade1, grade2, grade3, grade4;

        if (iss >> name >> grade1 >> grade2 >> grade3 >> grade4) {
            double average = (grade1 + grade2 + grade3 + grade4) / 4.0;
            studentAverages.push_back(average);
            totalSum += average;
            studentCount++;
        }
    }

    inputFile.close();

    if (studentCount == 0) {
        cerr << "No data found in the file." << endl;
        return 1;
    }

    double overallAverage = totalSum / studentCount;

    cout << "Individual student averages:" << endl;
    for (size_t i = 0; i < studentAverages.size(); ++i) {
        cout << "Student" << i + 1 << ": " << fixed << setprecision(2) << studentAverages[i] << endl;
    }

    cout << "\nOverall average of all students: " << fixed << setprecision(2) << overallAverage << endl;

    return 0;
}
