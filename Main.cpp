
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    
    char names[5][20];
    int marks[5][3];

    int total[5] = {0};
    double average[5] = {0.0};

    int topStudentIndex = 0;
    int maxTotal = -1;

    for (int i = 0; i < 5; i++) {
        cout << "Enter name for student " << i + 1 << ": ";
        cin.getline(names[i], 20);

        cout << "Enter Physics mark (0-100): ";
        cin >> marks[i][0];

        while (marks[i][0] < 0 || marks[i][0] > 100) {
            cout << "Invalid mark! Enter a mark from 0 to 100: ";
            cin >> marks[i][0];
        }

        cout << "Enter Mathematics mark (0-100): ";
        cin >> marks[i][1];

        while (marks[i][1] < 0 || marks[i][1] > 100) {
            cout << "Invalid mark! Enter a mark from 0 to 100: ";
            cin >> marks[i][1];
        }

        cout << "Enter English mark (0-100): ";
        cin >> marks[i][2];

        while (marks[i][2] < 0 || marks[i][2] > 100) {
            cout << "Invalid mark! Enter a mark from 0 to 100: ";
            cin >> marks[i][2];
        }

    
        for (int j = 0; j < 3; j++) {
            total[i] += marks[i][j];
        }

        average[i] = total[i] / 3.0;

        if (total[i] > maxTotal) {
            maxTotal = total[i];
            topStudentIndex = i;
        }

        cin.ignore();

        cout << endl;
    }

    cout << left << setw(20) << "Name"
         << right << setw(12) << "Physics"
         << setw(12) << "Mathematics"
         << setw(10) << "English"
         << setw(10) << "Total"
         << setw(10) << "Average" << endl;

    cout << "------------------------------------------------------------------------" << endl;

    for (int i = 0; i < 5; i++) {
        cout << left << setw(20) << names[i]
             << right << setw(12) << marks[i][0]
             << setw(12) << marks[i][1]
             << setw(10) << marks[i][2]
             << setw(10) << total[i]
             << setw(10) << fixed << setprecision(1)
             << average[i] << endl;
    }

    cout << "\nTop student: " << names[topStudentIndex] << endl;
    cout << "Highest total: " << maxTotal << "/300" << endl;

    return 0;
}
