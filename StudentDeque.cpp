//
// Created by Anastasija Fedorenko on 2025-03-12.
//

#include "StudentDeque.h"

//
// Created by Anastasija Fedorenko on 2025-03-12.
//


#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
using namespace std::chrono;

deque<StudentDeque> readFileDeque(int num){
    deque<StudentDeque> students;
    string filename = "students" + to_string(num) + ".txt";
    ifstream file(filename);
    try{
        if (!file.is_open()) {
            throw runtime_error("Nepavyko atidaryti failo.");
        } else {
            string header, line;
            getline(file, header);

            auto start = high_resolution_clock::now();
            while (getline(file, line)) {
                StudentDeque student;
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
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            double duration_s = duration_ms.count() / 1000.0;
            cout << to_string(num) + " irasu skaitymas i deque: "<< duration_s << "s" << endl;

            file.close();
        }
    }
    catch (const runtime_error &e) {
        cerr << "Klaida skaitant failą: " << e.what() << endl;
    }
    return students;
}

