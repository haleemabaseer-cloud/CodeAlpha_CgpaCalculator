#include "Student.h"
#include <iostream>
#include <fstream> 

using namespace std;

Student::Student(string studentName) 
{
    name = studentName;
}

void Student::addSubject(string subjectName, int credit, float gradepoint)
{
    Subject newSubject(subjectName, credit, gradepoint);
    subjects.push_back(newSubject); 
}

float Student::calculatecgpa()
{
    int totalcredit = 0;
    float weightgradepoint = 0;

    for (const Subject &subject : subjects)
    {
        totalcredit += subject.credit; 
        weightgradepoint += (subject.credit * subject.gradepoint); 
    }

    return (totalcredit > 0) ? (weightgradepoint / totalcredit) : 0;
}

void Student::displaycgpa()
{
    cout << "\nStudent's Name: " << name << endl;
    float cgpa = calculatecgpa();
    cout << "Calculated CGPA: " << cgpa << endl;
}

void Student::saveRecordToFile()
{
    ofstream file;
    file.open("cgpaData.txt", ios::out | ios::app);
    
    if (file.is_open())
    {
        file << "=============================\n";
        file << "Student Name: " << name << "\n";
        file << "Subjects Taken:\n";
        
        for (const Subject &subject : subjects)
        {
            file << " - " << subject.subjectname 
                 << " | Credits: " << subject.credit 
                 << " | Grade Point: " << subject.gradepoint << "\n";
        }
        
        file << "Final Calculated CGPA: " << calculatecgpa() << "\n";
        file << "=============================\n\n";
        
        file.close();
        cout << "Record successfully saved to 'cgpaData.txt'!" << endl;
    }
    else
    {
        cout << "Error: Unable to open file to save record." << endl;
    }
}
