

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

const int NUM_SUBJECTS = 6;
const int MAX_STUDENTS = 100;
const int CREDIT_HOUR = 3;

struct Student {
    string id, classYear;
    string name, department, admission;
    int grades[NUM_SUBJECTS];
    int age, room, block, admissionYear, section;
    string phoneNumber;
    char sex;
};

void studentProfile(const Student& student) {
    cout << "Full Name: " << student.name << "\t\t\t" << "Program: " << student.department << endl;
    cout << "ID Number: " << student.id << "\t\t\t" << "Admission: " << student.admission << endl;
    cout << "Admission Year: " << student.admission << "/" << student.admissionYear + 1 << "\t\t" << "Class Year: " << student.classYear << endl;
    cout << "Dormitory B" << student.block << ", R-" << student.room << "\t\t" << "Section " << student.section << endl;
}

