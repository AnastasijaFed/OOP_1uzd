

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <iostream>
#include <numeric>
#include <iomanip>

struct Student {
    std::string name;
    std::string surname;
    std::vector<double> grades;
    int exam_grade;
    mutable double final_grade;

};



#endif //STUDENT_H
