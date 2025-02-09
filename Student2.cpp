
#include "Student2.h"
using namespace std;

Student2* addStudents(Student2* students) {
    char answer;
    int i = 0;
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
        int grades_number = 0;
        cout<<"Kiek tarpinių pažymių (už namų darbus) norite įvesti?: "<<endl;
        cin>>grades_number;
        cout<<"Pažymiai: "<<endl;

        for (int i = 0; i < grades_number; i++) {

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



        students[i] = student;

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
    int i = 0;
    while(student.grades[i + 1] != 0.0) {
        sum += student.grades[i];
        i++;
    }
    return sum / (i+1);
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