#include <iostream>
#include <iomanip>  // Required for setw()

using namespace std;

int main() {
    // 1. Array declarations as specified
    char names[5][20];
    int marks[5][3];
    
    // Arrays to store computed results
    int total[5] = {0};
    double average[5] = {0.0};
    
    // Variables to track the top student
    int topStudentIndex = 0;
    int maxTotal = -1;

    // 2. Read student data
    for (int i = 1; i < 5; i++) {
        cout << "Enter name for student " <<i <<": ";
        cin.getline(names[i], 20);

        cout << "Enter 3 marks (out of 100%) for " << names[i] << ": ";
        for (int j = 0; j < 3; j++) {
            cin >> marks[i][j];
           
            total[i] += marks[i][j]; // 3. Compute total during input
        }
        
        // Compute average
        average[i] = total[i] / 3.0;

        // Track the top student based on the highest total score
        if (total[i] > maxTotal) {
            maxTotal = total[i];
            topStudentIndex = i;
        }

        // Hint implementation: Ignore the newline character left in the buffer by cin >>
        cin.ignore();
        cout << endl;
    }

    // 4. Print a neat table using setw()
    cout << left << setw(15) << "Name" 
         << right << setw(6) << "physics" 
         << setw(6) << "maths" 
         << setw(6) << "English " 
         << setw(8) << "Total" 
         << setw(10) << "Avg" << endl;
         
    cout << "--------------------------------------------------------" << endl;

    for (int i = 0; i < 5; i++) {
        cout << left << setw(15) << names[i]
             << right << setw(6) << marks[i][0]
             << setw(6) << marks[i][1]
             << setw(6) << marks[i][2]
             << setw(8) << total[i]
             << setw(10) << fixed << setprecision(1) << average[i] << endl;
    }

    // 5. Show the top student
    cout << "\nTop student: " << names[topStudentIndex] << endl;

    return 0;
}//use table if you can, real subject name with <=100 marks
