#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>

class Subject {
public:
    std::string subjectname;
    int credit;
    float gradepoint;

    // Using modern constructor initializer list
    Subject(std::string name, int cr, float gp);
};

#endif
