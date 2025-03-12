//
// Created by Anastasija Fedorenko on 2025-03-12.
//

#ifndef STUDENTDEQUE_H
#define STUDENTDEQUE_H

#include <deque>
#include <string>
using namespace std;

struct StudentDeque {
    std::string name;
    std::string surname;
    std::deque<double> grades;
    int exam_grade;

};

deque<StudentDeque> readFileDeque(int num);


#endif //STUDENTDEQUE_H
