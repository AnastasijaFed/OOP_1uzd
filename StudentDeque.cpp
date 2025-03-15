//
// Created by Anastasija Fedorenko on 2025-03-12.
//

#include "StudentDeque.h"
#include <ctime>

//
// Created by Anastasija Fedorenko on 2025-03-12.
//


#include <fstream>
#include <sstream>
#include <iostream>
#include <numeric>


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
                calculateFinalGradesAverageDeque(student);

                students.push_back(student);
            }
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            double duration_s = duration_ms.count() / 1000.0;
          //  cout << to_string(num) + " irasu skaitymas i deque: "<< duration_s << "s" << endl;

            file.close();
        }
    }
    catch (const runtime_error &e) {
        cerr << "Klaida skaitant failą: " << e.what() << endl;
    }
    return students;
}
double averageDeque(const StudentDeque &student) {
    if (student.grades.empty()) {
        return 0.0;
    }
    double average = accumulate(student.grades.begin(), student.grades.end(), 0.0) / student.grades.size();
    return average;
}
void calculateFinalGradesAverageDeque(const StudentDeque &student) {
    double average_grade = averageDeque(student);
    double final = average_grade * 0.4 + student.exam_grade * 0.6;
    student.final_grade = final;
}

deque<StudentDeque> sortDeque(deque<StudentDeque> students, int num) {
    timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    sort(students.begin(), students.end(), [](StudentDeque &a, StudentDeque &b) {
        return a.final_grade < b.final_grade;
    });
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    double elapsed_seconds =
        (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    //cout << to_string(num) + " irasu rusiavimas i deque: "<< elapsed_seconds << "s" << endl;
    return students;
}
void splitToGroupsDeque(deque<StudentDeque> students, int num) {
    deque<StudentDeque> kietekai;
    deque<StudentDeque> vargsiukai;
    timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    for (int i = 0; i < num; i++) {
        if (students[i].final_grade < 5) {
            vargsiukai.push_back(students[i]);
            students.shrink_to_fit();
        }
        else if (students[i].final_grade >= 5) {
            kietekai.push_back(students[i]);
            students.shrink_to_fit();
        }
    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    double elapsed_seconds =
        (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << to_string(num) + " irasu dalijimas i deque: "<< elapsed_seconds << "s" << endl;

}

