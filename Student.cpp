
using namespace std;




int main() {
    vector<Student> students;
    vector<Student> students2;
    int menu_choice;

    do {
        cout << "\nPasirinkite programos eigą:\n";
        cout << "1 - Įvesti studentų duomenis ranka\n";
        cout << "2 - Generuoti pažymius\n";
        cout << "3 - Generuoti studentų vardus, pavardes ir pažymius\n";
        cout << "4 - Nuskaityti iš failo\n";
        cout << "5 - Rūšiuoti\n";
        cout << "6 - Testas\n";
        cout << "7 - Baigti darbą\n";
        cout << "Jūsų pasirinkimas: ";

        while (!(cin >> menu_choice) || menu_choice < 1 || menu_choice > 7 || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Neteisingas pasirinkimas. Bandykite dar kartą.\n";
        }

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
                while (!(cin >> count) || count < 0 || cin.peek() != '\n') {
                    cout << "Neteisinga įvestis. Įveskite teigiamą skaičių: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                students2 = generateRandomStudents(count, std::string("first_names.txt"), std::string("surnames.txt"));
                generateGrades(students2);
                for (auto &student: students2) {
                    students.push_back(student);
                }
                break;
            case 4:
                students2 = readStudentsFile(std::string("kursiokai.txt"));
                for (auto &student: students2) {
                    students.push_back(student);
                }

                break;
            case 5:
                int answ;
                cout << "\n Pasirinkite rūšiavimo būdą: \n";
                cout << "1-Pagal vardą: \n";
                cout << "2-Pagal pavardę: \n";
                cout << "3-Pagal galutinį vidurkį: \n";
                cout << "4-Pagal medianą: \n";
                if (students.empty()) {
                    cout << "Sąraše nėra studentų";
                } else {
                    while (!(cin >> answ) || answ < 1 || answ > 4 || cin.peek() != '\n') {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Toks atsakymas negalimas. Bandykite iš naujo.";
                    }
                    if (answ == 1) {
                        students = sortByName(students);
                        printStudentList(students);
                    } else if (answ == 2) {
                        students = sortBySurname(students);
                        printStudentList(students);
                    } else if (answ == 3) {
                        students = sortByAverage(students);
                        printStudentList(students);
                    } else if (answ == 4) {
                        students = sortByMedian(students);
                        printStudentList(students);
                    }
                }
                break;
            case 6:
                students2 = test();
                for (auto &student: students2) {
                    students.push_back(student);
                }

            case 7:
                cout << "Programa baigė darbą.\n";
                break;
            default:
                cout << "Neteisingas pasirinkimas. Bandykite dar kartą.\n";
                cin >> menu_choice;
        }

        if (menu_choice >= 1 && menu_choice <= 4) {
            printStudentList(students);
        }
    } while (menu_choice != 7);


    return 0;
}
