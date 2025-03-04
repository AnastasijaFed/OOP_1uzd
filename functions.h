//
// Created by Anastasija Fedorenko on 2025-02-23.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Student.h"
#include <fstream>
#include <sstream>
using namespace std;
using namespace std::chrono;

vector<Student> addStudents(vector<Student> students);
double average(const Student &student);
double median(const Student &student);
double calculateFinalGradesMedian(const Student &student);
double calculateFinalGradesAverage(const Student &student);
void printStudentList(vector<Student> &students);
void generateGrades(vector<Student> &students);
vector<string> loadFromFile(const string &fileName);
vector<Student> readStudentsFile(const string &fileName);
vector<Student> generateRandomStudents(int count);
vector<Student> test();
bool compareByName(const Student a, const Student b);
bool compareBySurname(const Student a, const Student b);
bool compareByAverage(const Student a, const Student b);
bool compareByMedian(const Student a, const Student b);
vector<Student> sortByName(vector<Student> students);
vector<Student> sortBySurname(vector<Student> students);
vector<Student> sortByAverage(vector<Student> students);
vector<Student> sortByMedian(vector<Student> students);
void generateStudentsFile(int numberOfStudents);
void sortStudentsInFile(int numberOfStudents);
void logDuration(const string& message, const auto& start, const auto& stop);



#endif //FUNCTIONS_H
