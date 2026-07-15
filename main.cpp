#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

int main()
{
    string studentname;
    int numsub;

    cout << "Enter Student's name: ";
    getline(cin, studentname);
    cout << "Enter the number of subjects: ";
    cin >> numsub;
    cin.ignore(); 

    Student student(studentname);

    for (int i = 0; i < numsub; i++)
    {
        string subjectname;
        int credit;
        float gradepoint;

        cout << "\nEnter the name of subject " << (i + 1) << ": ";
        getline(cin, subjectname);

        cout << "Enter the credit hours of the subject: ";
        cin >> credit;

        cout << "Enter the gradepoint: ";
        cin >> gradepoint;
        cin.ignore(); 

        student.addSubject(subjectname, credit, gradepoint);
    }

    student.displaycgpa();
    student.saveRecordToFile(); 
    
    return 0;
}
