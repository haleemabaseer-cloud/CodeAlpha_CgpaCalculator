#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "Subject.h"

class Student {
public:
    std::string name;
    std::vector<Subject> subjects;

    // Pass string by const reference to save memory overhead
    Student(const std::string& studentName);

    void addSubject(const std::string& subjectName, int credit, float gradepoint);
    float calculatecgpa();
    void displaycgpa();
};

#endif
