
#include "Student2.h"
using namespace std;

vector<Student2> addStudents2(vector<Student2> students) {
    char answer;
    cout <<"Ar norite pridėti naują studentą? (t/n)";
    cin >> answer;
    while (std::tolower(answer) != 't' && std::tolower(answer) != 'n') {
        cout<<"Toks atsakymas negalimas. Bandykite iš naujo.";
        cout <<"Ar norite pridėti naują studentą? (t/n)";
        cin >> answer;
    }

    while (std::tolower(answer) == 't') {
        Student2 student;

        cout<<"Vardas: "<<endl;
        cin >> student.name;

        cout<<"Pavardė: "<<endl;
        cin>>student.surname;

        cout<<"Kiek tarpinių pažymių (už namų darbus) norite įvesti?: "<<endl;
        cin>>student.num_grades;
        cout<<"Pažymiai: "<<endl;

        for (int i = 0; i < student.num_grades; i++) {
            int grade;
            while (!(cin >> grade) || grade < 0 || grade > 10) {
                cout << "Neteisinga įvestis. Įveskite skaičių: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            student.grades[i] = grade;
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

double average(const Student2& student) {
    double sum = 0.0;

    for (int i = 0; i < student.num_grades; i++) {
        sum += student.grades[i];

    }
    double avr = sum / student.num_grades;
    return avr;
}

void selectionSort(double* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i) {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

double median(const Student2& student) {

    double sorted_grades[student.num_grades-1];
    selectionSort(sorted_grades, student.num_grades-1);

    size_t middle = student.num_grades / 2;

    if (student.num_grades % 2 == 0) {
        return (sorted_grades[middle - 1] + sorted_grades[middle]) / 2.0;
    } else {
        return sorted_grades[middle];
    }
}


double calculateFinalGradesMedian(const Student2& student) {
    double median_grade = median(student);
    return median_grade * 0.4 + student.exam_grade * 0.6;
}
double calculateFinalGradesAverage(const Student2& student) {
    double average_grade = average(student);
    return average_grade * 0.4 + student.exam_grade * 0.6;;
}

void printStudentList(const std::vector<Student2>& students) {
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
void generateGrades(vector<Student2>& students) {
    static bool seeded = false;
    if (!seeded) {
        srand(time(0));
        seeded = true;
    }

    for (auto& student : students) {
        int grades_number = rand() % 15 + 1;
        for (int i = 0; i < grades_number; ++i) {
            student.grades[i] = (rand() % 11);
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

void generateRandomStudents(vector<Student2> students,int count, const std::string& first_names_file, const std::string& last_names_file) {
    vector<string> first_names = loadFromFile(first_names_file);
    vector<string> last_names = loadFromFile(last_names_file);

    if (first_names.empty() || last_names.empty()) {
        cerr<<"Nepavyko sugeneruoti vardų.\n";
        for (int i = 1; i <= count; ++i) {
            Student2 student;
            student.name = "Vardas" + to_string(i);
            student.surname = "Pavarde" + to_string(i);
            students.push_back(student);
        }
    }
    else {
        random_shuffle(first_names.begin(), first_names.end());
        random_shuffle(last_names.begin(), last_names.end());
        for (int i = 0; i < count; ++i) {
            Student2 student;
            student.name = first_names[i % first_names.size()];
            student.surname = last_names[i % last_names.size()];
            students.push_back(student);
        }


    }
}

int main() {
    vector<Student2> students;
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
                students = addStudents2(students);
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
           generateRandomStudents(students, count, std::string("first_names.txt"), std::string("surnames.txt"));
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