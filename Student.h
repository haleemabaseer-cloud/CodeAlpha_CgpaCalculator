#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "Subject.h"

class Student {
public:
    std::string name;
    std::vector<Subject> subjects;

    Student(std::string studentName);
    
    void addSubject(std::string subjectName, int credit, float gradepoint);
    float calculatecgpa();
    void displaycgpa();
    void saveRecordToFile(); // New file-saving method
};

#endif
