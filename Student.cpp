

#include "Student.h"

#include <fstream>
using namespace std;


vector<Student> addStudents(vector<Student> students) {
    char answer;
    cout <<"Ar norite pridėti naują studentą? (t/n)";
    cin >> answer;
    while (std::tolower(answer) != 't' && std::tolower(answer) != 'n') {
        cout<<"Toks atsakymas negalimas. Bandykite iš naujo.";
        cout <<"Ar norite pridėti naują studentą? (t/n)";
        cin >> answer;
    }

    while (std::tolower(answer) == 't') {
        Student student;

        cout<<"Vardas: "<<endl;
        cin >> student.name;

        cout<<"Pavardė: "<<endl;
        cin>>student.surname;
        int grades_number = 0;
        cout<<"Kiek tarpinių pažymių (už namų darbus) norite įvesti?: "<<endl;
        cin>>grades_number;
        cout<<"Pažymiai: "<<endl;

        for (int i = 1; i <= grades_number; i++) {

            int grade;
            while (!(cin >> grade) || grade < 0 || grade > 10) {
                cout << "Neteisinga įvestis. Įveskite skaičių: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            student.grades.push_back(grade);
        }
        cout<<"Egzamino pažymys: "<<endl;
        while (!(cin >> student.exam_grade) || student.exam_grade < 0 || student.exam_grade > 10) {
            cout << "Neteisinga įvestis. Įveskite skaičių: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }


        students.push_back(student);

        cout <<"Ar norite pridėti naują studentą? (t/n)";
        cin >> answer;
        while (std::tolower(answer) != 't' && std::tolower(answer) != 'n') {
            cout<<"Toks atsakymas negalimas. Bandykite iš naujo.";
            cout <<"Ar norite pridėti naują studentą? (t/n)";
            cin >> answer;
        }
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

vector<string> loadFromFile(const string& filename) {
    vector<string> list;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            list.push_back(line);
        }
        file.close();
    }else {
        cout<<"Neįmanoma atidaryti failo "<<filename<<endl;
    }
return list;
}

vector<Student> generateRandomStudents(int count, const std::string& first_names_file, const std::string& last_names_file) {
    vector<string> first_names = loadFromFile(first_names_file);
    vector<string> last_names = loadFromFile(last_names_file);
    vector<Student> students;

    if (first_names.empty() || last_names.empty()) {
        cerr<<"Nepavyko sugeneruoti vardų.\n";
        for (int i = 1; i <= count; ++i) {
            Student student;
            student.name = "Vardas" + to_string(i);
            student.surname = "Pavarde" + to_string(i);
            students.push_back(student);
        }
        return students;
    }
    else {
        random_shuffle(first_names.begin(), first_names.end());
        random_shuffle(last_names.begin(), last_names.end());
        for (int i = 0; i < count; ++i) {
            Student student;
            student.name = first_names[i % first_names.size()];
            student.surname = last_names[i % last_names.size()];
            students.push_back(student);
        }

        return students;
    }
}
bool compareByName(const Student a, const Student b) {
    return a.name < b.name;
}
bool compareBySurname(const Student a, const Student b) {
    return a.surname < b.surname;
}
bool compareByAverage(const Student a, const Student b) {
    return calculateFinalGradesAverage(a) < calculateFinalGradesAverage(b);
}
bool compareByMedian(const Student a, const Student b) {
    return calculateFinalGradesMedian(a) < calculateFinalGradesMedian(b);
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
            students = generateRandomStudents(count, std::string("first_names.txt"), std::string("surnames.txt"));
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