#include "functions.h"
#include "StudentList.h"
#include "StudentDeque.h"
using namespace std;




int main() {

    sortStudentsInFile(1000);
    sortStudentsInFile(10000);
    sortStudentsInFile(100000);
    sortStudentsInFile(1000000);
    sortStudentsInFile(10000000);

   /* list <StudentList> studentsList;
    studentsList = readFileLists(1000);
    studentsList = sortList(studentsList, 1000);

    studentsList.clear();
    studentsList = readFileLists(10000);
    studentsList = sortList(studentsList, 10000);
    studentsList.clear();
    studentsList = readFileLists(100000);
    studentsList = sortList(studentsList, 100000);
    studentsList.clear();
    studentsList = readFileLists(1000000);
    studentsList = sortList(studentsList, 1000000);
    studentsList.clear();
    studentsList = readFileLists(10000000);
    studentsList = sortList(studentsList, 10000000);*/


    /*deque<StudentDeque> studentsDeque;
    studentsDeque = readFileDeque(1000);
    studentsDeque = sortDeque(studentsDeque, 1000);
    studentsDeque.clear();
    studentsDeque = readFileDeque(10000);
    studentsDeque = sortDeque(studentsDeque, 10000);
    studentsDeque.clear();
    studentsDeque = readFileDeque(100000);
    studentsDeque = sortDeque(studentsDeque, 100000);
    studentsDeque.clear();
    studentsDeque = readFileDeque(1000000);
    studentsDeque = sortDeque(studentsDeque, 1000000);
    studentsDeque.clear();
    studentsDeque = readFileDeque(10000000);
    studentsDeque = sortDeque(studentsDeque, 10000000);
    */



    return 0;
}