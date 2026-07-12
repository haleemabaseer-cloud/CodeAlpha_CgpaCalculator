#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

// Helper function to make sure recruiters/users can't crash the program with bad input
int getValidInteger(const string& prompt) {
    int val;
    while (true) {
        cout << prompt;
        if (cin >> val && val > 0) {
            cin.ignore(10000, '\n'); // clear buffer
            return val;
        }
        cout << "Invalid entry. Please enter a positive integer.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

float getValidFloat(const string& prompt) {
    float val;
    while (true) {
        cout << prompt;
        if (cin >> val && val >= 0.0f && val <= 4.0f) { // Assuming standard 4.0 scale max
            cin.ignore(10000, '\n'); 
            return val;
        }
        cout << "Invalid entry. Please enter a grade point between 0.0 and 4.0.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

int main() {
    string studentname;
    cout << "Enter Student's name: ";
    getline(cin, studentname);

    int numsub = getValidInteger("Enter the number of subjects: ");
    Student student(studentname);

    for (int i = 0; i < numsub; i++) {
        string subjectname;
        cout << "\n--- Subject " << (i + 1) << " ---\n";
        cout << "Enter the name of subject: ";
        getline(cin, subjectname);

        int credit = getValidInteger("Enter the credit hours of the subject: ");
        float gradepoint = getValidFloat("Enter the grade point: ");

        student.addSubject(subjectname, credit, gradepoint);
    }

    student.displaycgpa();
    return 0;
}
