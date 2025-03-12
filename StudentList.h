//
// Created by Anastasija Fedorenko on 2025-03-12.
//

#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <string>
#include <list>
using namespace std;

struct StudentList {
    std::string name;
    std::string surname;
    std::list<double> grades;
    int exam_grade;

};
list<StudentList> readFileLists(int num);
double averageList(const StudentList &student);
double calculateFinalGradesAverageList(const StudentList &student);
list<StudentList> sortList(list<StudentList> students, int num);


#endif //STUDENTLIST_H
