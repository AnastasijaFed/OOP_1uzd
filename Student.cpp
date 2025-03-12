#include "functions.h"
#include "StudentList.h"
#include "StudentDeque.h"
using namespace std;




int main() {
    list <StudentList> studentsList;
    studentsList = readFileLists(1000);
    studentsList.clear();
    studentsList = readFileLists(10000);
    studentsList.clear();
    studentsList = readFileLists(100000);
    studentsList.clear();
    studentsList = readFileLists(1000000);
    studentsList.clear();
    studentsList = readFileLists(10000000);


    return 0;
}