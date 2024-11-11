

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

void saveStudentToFile(const Student& student) {
    ofstream file("student.txt", ios::app); // Open the file in append mode
    if (file.is_open()) {
        file << "Full Name: " << student.name << "\t\t\t" << "Program: " << student.department << endl;
        file << "ID Number: " << student.id << "\t\t\t" << "Admission: " << student.admission << endl;
        file << "Admission Year: " << student.admission << "/" << student.admissionYear + 1 << "\t\t" << "Class Year: " << student.classYear << endl;
        file << "Dormitory B" << student.block << ", R-" << student.room << "\t\t" << "Section " << student.section << endl;
        file << "---------------------------------------------" << endl;
        file.close();
    } else {
        cerr << "Unable to open file" << endl;
    }
    
    }

void displayStudentInfo(const Student& student);

void registerStudent(Student& student) {
    cout << "Enter full name: ";
    cin >> student.name;

    cout << "Enter department: ";
    cin >> student.department;

    cout << "Enter ID number: ";
    cin >> student.id;

    cout << "Enter admission : ";
    cin >> student.admission;

    cout << "Enter admission year: ";
    cin >> student.admissionYear;

    cout << "Enter class year: ";
    cin >> student.classYear;

    cout << "Enter dormitory block : ";
    cin >> student.block;

    cout << "Enter room number: ";
    cin >> student.room;

    cout << "Enter section : ";
    cin >> student.section;

    // Clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    saveStudentToFile(student);
}


float calculateGPA(const int grades[]) {
    const int A_score = 90,
              B_score = 80,
              C_score = 70,
              D_score = 60;

    const int A = 4,
              B = 3,
              C = 2,
              D = 1,
              F = 0;

    int totalPoints = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        if (grades[i] >= A_score && grades[i] <= 100) {
            totalPoints += A * CREDIT_HOUR;
        } else if (grades[i] >= B_score) {
            totalPoints += B * CREDIT_HOUR;
        } else if (grades[i] >= C_score) {
            totalPoints += C * CREDIT_HOUR;
        } else if (grades[i] >= D_score) {
            totalPoints += D * CREDIT_HOUR;
        } else {
            totalPoints += F * CREDIT_HOUR;
        }
    }

    return static_cast<float>(totalPoints) / (NUM_SUBJECTS * CREDIT_HOUR);
}