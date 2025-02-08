

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

    std::vector<double> sorted_grades = student.grades;
    std::sort(sorted_grades.begin(), sorted_grades.end());

    size_t middle = sorted_grades.size() / 2;

    if (sorted_grades.size() % 2 == 0) {
        return (sorted_grades[middle - 1] + sorted_grades[middle]) / 2.0;
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
void generateGrades(vector<Student>& students) {
    static bool seeded = false;
    if (!seeded) {
        srand(time(0));
        seeded = true;
    }

    for (auto& student : students) {
        int grades_number = rand() % 15 + 1;
        student.grades.clear();
        for (int i = 0; i < grades_number; ++i) {
            student.grades.push_back(rand() % 11);
        }
        student.exam_grade = rand() % 11;
    }
}

int main() {
    vector<Student> students;
    int menu_choice;
    do {
        cout << "\nPasirinkite programos eigą:\n";
        cout << "1 - Įvesti studentų duomenis ranka\n";
        cout << "2 - Generuoti pažymius\n";
        cout << "3 - Generuoti studentų vardus, pavardes ir pažymius\n";
        cout << "4 - Baigti darbą\n";
        cout << "Jūsų pasirinkimas: ";
        cin >> menu_choice;

        switch (menu_choice) {
            case 1:
                students = addStudents(students);
            break;
            case 2:
                if (students.empty()) {
                    cout << "Pirmiausia sugeneruokite studentus arba įveskite ranka.\n";
                } else {
                    generateGrades(students);
                }
            break;
            case 3:
                int count;
            cout << "Kiek studentų generuoti? ";
            cin >> count;
            //students = generateStudents(count);
            generateGrades(students);
            break;
            case 4:
                cout << "Programa baigė darbą.\n";
            break;
            default:
                cout << "Neteisingas pasirinkimas. Bandykite dar kartą.\n";
        }

        if (menu_choice >= 1 && menu_choice <= 3) {
            printStudentList(students);
        }

    } while (menu_choice != 4);






    return 0;
}