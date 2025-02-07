

#include "Student.h"
using namespace std;


vector<Student> addStudents(vector<Student> students) {
    char answer;
    cout <<"Ar norite pridėti naują studentą? (t/n)";
    cin >> answer;

    while (answer == 't') {
        Student student;

        cout<<"Vardas: "<<endl;
        cin >> student.name;

        cout<<"Pavardė: "<<endl;
        cin>>student.surname;
        int grades_number = 0;
        cout<<"Kiek tarpinių pažymių norite įvesti?: "<<endl;
        cin>>grades_number;
        cout<<"Pažymiai: "<<endl;

        for (int i = 1; i <= grades_number; i++) {

            int grade;
            cin>>grade;
            student.grades.push_back(grade);
        }
        cout<<"Egzamino pažymys: "<<endl;
        cin>>student.exam_grade;

        students.push_back(student);

        cout <<"Ar norite pridėti naują studentą? (t/n)";
        cin >> answer;
        if (answer == 'n') {break;}
    }
    return students;
}



double average(const Student& student) {
    if (student.grades.empty()) {
        return 0.0;
    }
    double sum = 0.0;
    for (size_t i = 0; i < student.grades.size(); ++i) {
        sum += student.grades[i];
    }
    double average_grades = sum / student.grades.size();
    return average_grades;
}

double median(const Student& student) {
    if (student.grades.empty()) {
        return 0.0;
    }

    std::vector<double> sorted_grades = student.grades; // Create a copy
    std::sort(sorted_grades.begin(), sorted_grades.end()); // Sort the copy

    size_t middle = sorted_grades.size() / 2;

    if (sorted_grades.size() % 2 == 0) {
        return (sorted_grades[middle - 1] + sorted_grades[middle]) / 2.0; // Correct, 2.0!
    } else {
        return sorted_grades[middle];
    }
}

double calculateFinalGradesMedian(const Student& student) {
    double median_grade = median(student);
    return median_grade * 0.4 + student.exam_grade * 0.6;
}
double calculateFinalGradesAverage(const Student& student) {
    double average_grade = average(student);
    return average_grade * 0.4 + student.exam_grade * 0.6;;
}

void printStudentList(const vector<Student>& students) {
    cout << left << setw(15) << "Pavardė" << setw(10) << "Vardas"
          << setw(15) << "Galutinis (Vid.)" << setw(15) << "Galutinis (Med.)" << endl;
    cout << setfill('-') << setw(55) << "-" << setfill(' ') << endl; // Increased width

    for (size_t i = 0; i < students.size(); ++i) {
        cout << left << setw(15) << students[i].surname << setw(10) << students[i].name;

        double avgFinal = calculateFinalGradesAverage(students[i]);
        double medFinal = calculateFinalGradesMedian(students[i]);

        cout << fixed << setprecision(2) << right << setw(15) << avgFinal
             << fixed << setprecision(2) << right << setw(15) << medFinal << endl;
    }
}

int main() {
    vector<Student> students;
    students = addStudents(students);
    printStudentList(students);



    return 0;
}