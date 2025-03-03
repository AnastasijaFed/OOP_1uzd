

#include "functions.h"
vector<Student> addStudents(vector<Student> students) {
    char answer;
    cout << "Ar norite pridėti naują studentą? (t/n)";
    cin >> answer;
    while (std::tolower(answer) != 't' && std::tolower(answer) != 'n') {
        cout << "Toks atsakymas negalimas. Bandykite iš naujo.";
        cout << "Ar norite pridėti naują studentą? (t/n)";
        cin >> answer;
    }

    while (std::tolower(answer) == 't') {
        Student student;

        cout << "Vardas: " << endl;
        cin >> student.name;

        cout << "Pavardė: " << endl;
        cin >> student.surname;
        int grades_number;
        cout << "Kiek tarpinių pažymių (už namų darbus) norite įvesti?: " << endl;
        cin >> grades_number;
        while (cin.fail() || grades_number < 0) {
            cout << "Neteisinga įvestis. Įveskite teigiamą skaičių: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> grades_number;
        }

        if (grades_number > 0) {
            cout << "Pažymiai: " << endl;
            for (int i = 1; i <= grades_number; i++) {
                int grade = 0;
                cin >> grade;
                while (cin.fail() || grade < 0 || grade > 10) {
                    cout << "Neteisinga įvestis. Įveskite skaičių nuo 0 iki 10: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> grade;
                }
                student.grades.push_back(grade);
            }
        } else {
            cout << "Studentas neturi tarpinių pažymių." << endl;
        }
        cout << "Egzamino pažymys: " << endl;
        cin>>student.exam_grade;
        while (cin.fail() || student.exam_grade < 0 || student.exam_grade > 10) {
            cout << "Neteisinga įvestis. Įveskite skaičių: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> student.exam_grade;
        }


        students.push_back(student);

        cout << "Ar norite pridėti naują studentą? (t/n)";
        cin >> answer;
        while (std::tolower(answer) != 't' && std::tolower(answer) != 'n') {
            cout << "Toks atsakymas negalimas. Bandykite iš naujo.";
            cout << "Ar norite pridėti naują studentą? (t/n)";
            cin >> answer;
        }
        if (answer == 'n') { break; }
    }
    return students;
}


double average(const Student &student) {
    if (student.grades.empty()) {
        return 0.0;
    }
    double average = accumulate(student.grades.begin(), student.grades.end(), 0.0) / student.grades.size();
    return average;
}

double median(const Student &student) {
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

double calculateFinalGradesMedian(const Student &student) {
    double median_grade = median(student);
    return median_grade * 0.4 + student.exam_grade * 0.6;
}

double calculateFinalGradesAverage(const Student &student) {
    double average_grade = average(student);
    return average_grade * 0.4 + student.exam_grade * 0.6;;
}

void printStudentList(vector<Student> &students) {
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

void generateGrades(vector<Student> &students) {
    static bool seeded = false;
    if (!seeded) {
        srand(time(0));
        seeded = true;
    }

    for (auto &student: students) {
        int grades_number = 5;
        student.grades.clear();
        for (int i = 0; i < grades_number; ++i) {
            student.grades.push_back(rand() % 10 + 1);
        }
        student.exam_grade = rand() % 10 + 1;
    }
}

vector<string> loadFromFile(const string &filename) {
    vector<string> list;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            list.push_back(line);
        }
        file.close();
    }
    return list;
}

vector<Student> readStudentsFile(const string &filename) {
    vector<Student> students;
    ifstream file(filename);
    try{
    if (!file.is_open()) {
        throw runtime_error("Nepavyko atidaryti failo.");
    } else {
        string header, line;
        getline(file, header);


        while (getline(file, line)) {
            Student student;
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


vector<Student> generateRandomStudents(int count) {
    vector<string> first_names = loadFromFile("first_names.txt");
    vector<string> last_names = loadFromFile("surnames.txt");
    vector<Student> students;

    if (first_names.empty() || last_names.empty()) {
        for (int i = 1; i <= count; ++i) {
            Student student;
            student.name = "Vardas" + to_string(rand() % count + 1);
            student.surname = "Pavarde" + to_string(rand() % count + 1);
            students.push_back(student);
        }
        return students;
    } else {
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

vector<Student> test() {
    std::string filename;
    cout << "Kiek studentų norite pridėti? (10000/100000/1000000)" << endl;
    int n;
    cin >> n;
    while (n != 10000 && n != 100000 && n != 1000000) {
        cout << "Neteisinga įvestis, bandykite dar kartą" << endl;
        cin >> n;
    }
    auto start = high_resolution_clock::now();
    if (n == 10000) {
        filename.assign("studentai10000.txt");
    } else if (n == 100000) {
        filename.assign("studentai100000.txt");
    } else if (n == 1000000) {
        filename.assign("studentai1000000.txt");
    }
    vector<Student> students;
    ifstream file(filename);
    try{
    if (!file.is_open()) {
        throw std::runtime_error("Nepavyko atidaryti failo: " + filename);
    }

    std::string line, header;
    getline(file, header);
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Student student;

        iss >> student.name >> student.surname;

        double grade;
        while (iss >> grade) {
            student.grades.push_back(grade);
        }

        if (!student.grades.empty()) {
            student.exam_grade = static_cast<int>(student.grades.back());
            student.grades.pop_back();
        } else {
            std::cerr << "Warning: No grades found for student " << student.name << " " << student.surname << std::endl;
        }

        students.push_back(student);
    }

    file.close();

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    double duration_s = duration_ms.count() / 1000.0;
    printStudentList(students);

    cout << "Duration (seconds): " << duration_s << endl;
    }catch (const runtime_error& e) {
        cerr << "Klaida skaitant failą: " << e.what() << endl;

        }
    return students;
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

vector<Student> sortByName(vector<Student> students) {
    sort(students.begin(), students.end(), compareByName);
    printStudentList(students);
    return students;
}

vector<Student> sortBySurname(vector<Student> students) {
    sort(students.begin(), students.end(), compareBySurname);
    printStudentList(students);
    return students;
}

vector<Student> sortByAverage(vector<Student> students) {
    sort(students.begin(), students.end(), compareByAverage);
    return students;
}

vector<Student> sortByMedian(vector<Student> students) {
    sort(students.begin(), students.end(), compareByMedian);
    return students;
}
void generateStudentsFile(int numberOfStudents){
  ofstream file;
  vector <Student> students;
  string number = to_string(numberOfStudents);
  auto start = high_resolution_clock::now();
  string filename = "students" + number + ".txt";
  file.open(filename);
  if (!file.is_open()) {
    cerr << "Nepavyko sukurti failo: " + filename;

  }
  else{
     students = generateRandomStudents(numberOfStudents);
     generateGrades(students);
     for (const Student &student : students) {
       file << student.name << " " << student.surname << "       ";
       for(const double &grade : student.grades) {
         file << grade  << " ";
       }
       file<< student.exam_grade << endl;
     }

  }
  auto stop = std::chrono::high_resolution_clock::now();
    auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    double duration_s = duration_ms.count() / 1000.0;
    cout<< filename + " generavimo laikas " << duration_s << "sek" << endl;
  file.close();


  }

void sortStudentsInFile(int numberOfStudents) {
  ofstream file1, file2;
  int answ;
  string filename1 = "kietekai" + to_string(numberOfStudents) + ".txt";
  file1.open(filename1);
  string filename2 = "vargsiukai" + to_string(numberOfStudents) + ".txt";
  file2.open(filename2);
  string filename3 = "students" + to_string(numberOfStudents) + ".txt";

  auto start = high_resolution_clock::now();
  vector<Student> students = readStudentsFile(filename3);
  auto stop = std::chrono::high_resolution_clock::now();
    auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    double duration_s = duration_ms.count() / 1000.0;
    cout<< numberOfStudents << " įrašų iš failo nuskaitymo laikas: " << duration_s << "sec" << endl;

    cout<< "Pagal ką norite rūšiuoti studentus?: " << endl;
    cout << "1-Pagal vardą: \n";
    cout << "2-Pagal pavardę: \n";
    cout << "3-Pagal galutinį vidurkį: \n";
    cout << "4-Pagal medianą: \n";
    cin >> answ;
                while (cin.fail() || answ < 1 || answ > 4) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Toks atsakymas negalimas. Bandykite iš naujo.";
                    cin >> answ;
                }
                auto start2 = high_resolution_clock::now();
                if (answ == 1) {
                    students = sortByName(students);
                }
                else if (answ == 2) {
                    students = sortBySurname(students);
                }
                else if (answ == 3) {
                    students = sortByAverage(students);
                }
                else if (answ == 4) {
                    students = sortByMedian(students);
                }
    auto stop2 = std::chrono::high_resolution_clock::now();
    auto duration_ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(stop2 - start2);
    double duration_s2 = duration_ms2.count() / 1000.0;
    cout<< numberOfStudents << " įrašų rūšiavimo laikas: " << duration_s2 << "sec" << endl;

    vector<Student> kietekai;
    vector<Student> vargsiukai;
    int i = 0;
    auto start3 = high_resolution_clock::now();
  for(Student student : students) {
    if(calculateFinalGradesAverage(student) < 5.00) {
      vargsiukai.push_back(student);
      //students.erase(students.begin() + i);

    }
    else {
      kietekai.push_back(student);
     // students.erase(students.begin() + i);
    }
    i++;
  }
  auto stop3 = std::chrono::high_resolution_clock::now();
  auto duration_ms3 = std::chrono::duration_cast<std::chrono::milliseconds>(stop3 - start3);
  double duration_s3 = duration_ms2.count() / 1000.0;
  cout<< numberOfStudents << " įrašų padalijimo į du konteinerius laikas: " << duration_s3 << "sec" << endl;

  auto start4 = high_resolution_clock::now();
  for(Student student : kietekai) {
    file1 << student.name << " " << student.surname << "       " << calculateFinalGradesAverage(student)<<endl;
  }
  auto stop4 = std::chrono::high_resolution_clock::now();
    auto duration_ms4 = std::chrono::duration_cast<std::chrono::milliseconds>(stop4 - start4);
    double duration_s4 = duration_ms2.count() / 1000.0;
    cout<< numberOfStudents << " įrašų kietekų įrašymo laikas: " << duration_s4 << "sec" << endl;

  auto start5 = high_resolution_clock::now();
  for(Student student : vargsiukai) {
    file2 << student.name << " " << student.surname << "       " << calculateFinalGradesAverage(student)<<endl;
  }
  auto stop5 = std::chrono::high_resolution_clock::now();
    auto duration_ms5 = std::chrono::duration_cast<std::chrono::milliseconds>(stop5 - start5);
    double duration_s5 = duration_ms2.count() / 1000.0;
    cout<< numberOfStudents << " įrašų vargšiukų įrašymo laikas: " << duration_s5 << "sec" << endl;

  file1.close();
  file2.close();
  }
