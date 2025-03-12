//
// Created by Anastasija Fedorenko on 2025-03-12.
//

#include "StudentList.h"
#include <fstream>
#include <sstream>
#include <iostream>

list<StudentList> readFileLists(int num){
  list<StudentList> students;
  string filename = "students" + to_string(num) + ".txt";
    ifstream file(filename);
    try{
        if (!file.is_open()) {
            throw runtime_error("Nepavyko atidaryti failo.");
        } else {
            string header, line;
            getline(file, header);


            while (getline(file, line)) {
                StudentList student;
                std::istringstream iss(line);
                iss >> student.name >> student.surname;
                double grade;
                while (iss >> grade) {
                    student.grades.push_back(grade);
                }

                student.exam_grade = static_cast<int>(student.grades.back());
                student.grades.pop_back();

                students.push_back(student);
            }

            file.close();
        }
    }
    catch (const runtime_error &e) {
        cerr << "Klaida skaitant failą: " << e.what() << endl;
    }
    return students;
  }