#include "functions.h"
#include "StudentList.h"
#include "StudentDeque.h"
using namespace std;




int main() {
 vector<Student> students;
    cout << "Vektoriai: "<<endl;
    cout << "-----------------------------------------------------------"<<endl;

    sortStudentsInFile(students, 1000);
    students.clear();
    cout << " "<<endl;

    sortStudentsInFile(students,10000);
    students.clear();
    cout << " "<<endl;

    sortStudentsInFile(students,100000);
    students.clear();
    cout << " "<<endl;

    sortStudentsInFile(students,1000000);
    students.clear();
    cout << " "<<endl;

    sortStudentsInFile(students,10000000);
    students.clear();
    cout << " "<<endl;

    cout << "-----------------------------------------------------------"<<endl;
    cout << "Listai: "<<endl;
    cout << "-----------------------------------------------------------"<<endl;
    list <StudentList> studentsList;

    studentsList = readFileLists(1000);
    studentsList = sortList(studentsList, 1000);
    splitInTwo(studentsList, 1000);
    studentsList.clear();
    cout << " "<<endl;

    studentsList = readFileLists(10000);
    studentsList = sortList(studentsList, 10000);
    splitInTwo(studentsList, 10000);
    studentsList.clear();
    cout << " "<<endl;

    studentsList = readFileLists(100000);
    studentsList = sortList(studentsList, 100000);
    splitInTwo(studentsList, 100000);
    studentsList.clear();
    cout << " "<<endl;

    studentsList = readFileLists(1000000);
    studentsList = sortList(studentsList, 1000000);
    splitInTwo(studentsList, 1000000);
    studentsList.clear();
    cout << " "<<endl;

    studentsList = readFileLists(10000000);
    studentsList = sortList(studentsList, 10000000);
    splitInTwo(studentsList, 10000000);
    studentsList.clear();
    cout << "-----------------------------------------------------------"<<endl;
    cout << "Deque: "<<endl;
    cout << "-----------------------------------------------------------"<<endl;
    deque<StudentDeque> studentsDeque;
    deque<StudentDeque> kietekai;
    deque<StudentDeque> vargsiukai;
    studentsDeque = readFileDeque(1000);
    sortDeque(studentsDeque, 1000);
    splitToGroupsDeque(studentsDeque, kietekai, vargsiukai, 1000);
    studentsDeque.clear();
    cout << " "<<endl;

    studentsDeque = readFileDeque(10000);
    sortDeque(studentsDeque, 10000);
    splitToGroupsDeque(studentsDeque, kietekai, vargsiukai, 10000);
    studentsDeque.clear();
    cout << " "<<endl;

    studentsDeque = readFileDeque(100000);
    sortDeque(studentsDeque, 100000);
    splitToGroupsDeque(studentsDeque, kietekai, vargsiukai, 100000);
    studentsDeque.clear();
    cout << " "<<endl;

    studentsDeque = readFileDeque(1000000);
    sortDeque(studentsDeque, 1000000);
    splitToGroupsDeque(studentsDeque, kietekai, vargsiukai, 1000000);
    studentsDeque.clear();
    cout << " "<<endl;

    studentsDeque = readFileDeque(10000000);
    sortDeque(studentsDeque, 10000000);
    splitToGroupsDeque(studentsDeque, kietekai, vargsiukai,10000000);
    studentsDeque.clear();








    return 0;
}