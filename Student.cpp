#include "functions.h"
#include "StudentList.h"
#include "StudentDeque.h"
using namespace std;




int main() {
 /*vector<Student> students;
 vector<Student> vargsiukai3;
    sortStudentsInFile(students, 1000);
 strategyTwoVector(students, vargsiukai3, 1000);
    students.clear();
    vargsiukai3.clear();
    sortStudentsInFile(students,10000);
    strategyTwoVector(students, vargsiukai3, 10000);
    students.clear();
    vargsiukai3.clear();
    sortStudentsInFile(students,100000);
    strategyTwoVector(students, vargsiukai3, 100000);
    students.clear();
    vargsiukai3.clear();
    sortStudentsInFile(students,1000000);
    strategyTwoVector(students, vargsiukai3, 1000000);
    students.clear();
    vargsiukai3.clear();
    sortStudentsInFile(students,10000000);
    strategyTwoVector(students, vargsiukai3, 10000000);
    students.clear();
    vargsiukai3.clear();
    */

  /* list <StudentList> studentsList;
    list <StudentList> vargsiukai2;

    studentsList = readFileLists(1000);
    studentsList = sortList(studentsList, 1000);
    //splitInTwo(studentsList, 1000);
    strategyTwoList(studentsList, vargsiukai2, 1000);
    studentsList.clear();
    studentsList = readFileLists(10000);
    studentsList = sortList(studentsList, 10000);
    //splitInTwo(studentsList, 10000);
    strategyTwoList(studentsList, vargsiukai2, 10000 );
    studentsList.clear();
    studentsList = readFileLists(100000);
    studentsList = sortList(studentsList, 100000);
    //splitInTwo(studentsList, 100000);
    strategyTwoList(studentsList, vargsiukai2, 100000 );
    studentsList.clear();
    studentsList = readFileLists(1000000);
    studentsList = sortList(studentsList, 1000000);
   // splitInTwo(studentsList, 1000000);
 strategyTwoList(studentsList, vargsiukai2, 1000000 );
    studentsList.clear();
    studentsList = readFileLists(10000000);
    studentsList = sortList(studentsList, 10000000);
   // splitInTwo(studentsList, 10000000);
    strategyTwoList(studentsList, vargsiukai2, 10000000 );
    studentsList.clear();*/


    deque<StudentDeque> studentsDeque;
 deque<StudentDeque> kietekai;
 deque<StudentDeque> vargsiukai;
    studentsDeque = readFileDeque(1000);
    sortDeque(studentsDeque, 1000);
    //splitToGroupsDeque(studentsDeque, kietekai, vargsiukai, 1000);
    strategyTwoDeque(studentsDeque, vargsiukai, 1000);
    studentsDeque.clear();
    studentsDeque = readFileDeque(10000);
    sortDeque(studentsDeque, 10000);
    //splitToGroupsDeque(studentsDeque, kietekai, vargsiukai, 10000);
    strategyTwoDeque(studentsDeque, vargsiukai, 10000);
    studentsDeque.clear();
    studentsDeque = readFileDeque(100000);
    sortDeque(studentsDeque, 100000);
    //splitToGroupsDeque(studentsDeque, kietekai, vargsiukai, 100000);
    strategyTwoDeque(studentsDeque, vargsiukai, 100000);
    studentsDeque.clear();
    studentsDeque = readFileDeque(1000000);
    sortDeque(studentsDeque, 1000000);
    //splitToGroupsDeque(studentsDeque, kietekai, vargsiukai, 1000000);
    strategyTwoDeque(studentsDeque, vargsiukai, 1000000);
    studentsDeque.clear();

    studentsDeque = readFileDeque(10000000);
    sortDeque(studentsDeque, 10000000);
    //splitToGroupsDeque(studentsDeque, kietekai, vargsiukai,10000000);
    strategyTwoDeque(studentsDeque, vargsiukai, 10000000);
    studentsDeque.clear();







    return 0;
}