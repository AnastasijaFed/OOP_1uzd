

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
        cout<<"Kiek pažymių norite įvesti?: "<<endl;
        cin>>grades_number;
        cout<<"Pažymiai: "<<endl;

        for (int i = 1; i <= grades_number; i++) {

            int grade;
            cin>>grade;
            student.grades.push_back(grade);
        }
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
    for (size_t i = 0; i < student.grades.size() - 1; ++i) {
        sum += student.grades[i];
    }
    double exam_grade = student.grades[student.grades.size() - 1] * 0.6;
    double average_grades = sum / (student.grades.size() - 1);
    double final_grade = average_grades * 0.4 + exam_grade;

    return final_grade;
}

void printStudentList(const vector<Student>& students) {
    // Print header with proper spacing
    cout << left << setw(15) << "Pavardė" << setw(10) << "Vardas" << "Galutinis (Vid.)" << endl;
    cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl; // Separator line

    for (size_t i = 0; i < students.size(); ++i) {
        cout << left << setw(15) << students[i].surname << setw(10) << students[i].name;
        double avg = average(students[i]);
        cout << fixed << setprecision(2) << right << setw(13) << avg << endl; // Right align average
    }
}
int main() {
    vector<Student> students;
    students = addStudents(students);
    printStudentList(students);



    return 0;
}