

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

void displayStudentInfo(const Student& student) {
    cout << "ID: " << student.id << endl;
    cout << "Name: " << student.name << endl;
    cout << "Age: " << student.age << endl;
    cout << "Phone Number: " << student.phoneNumber << endl;
    cout << "Sex: " << student.sex << endl;
    cout << "Grades: ";
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        cout << student.grades[i] << " ";
    }
    cout << endl;
    float studentGPA = calculateGPA(student.grades);
    cout << "GPA: " << studentGPA << endl;
}

void saveStudentData(const Student students[], int numStudents, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }

   
    outFile << left << setw(10) << "ID"
            << left << setw(20) << "Name"
            << left << setw(5) << "Age"
            << left << setw(15) << "Phone Number"
            << left << setw(5) << "Sex"
            << left << setw(10) << "GPA";
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        string subjects_l[] = {"Applied two", "C++", "Civics", "Technical Drawing", "Writing Skill", "Emerging Technology"};
        outFile << left << setw(20) << (  subjects_l[j]);
    }
    outFile << endl;

  
    for (int i = 0; i < numStudents; ++i) {
        outFile << left << setw(10) << students[i].id
                << left << setw(20) << students[i].name
                << left << setw(5) << students[i].age
                << left << setw(15) << students[i].phoneNumber
                << left << setw(5) << students[i].sex
                << left << setw(10) << calculateGPA(students[i].grades);
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            outFile << left << setw(10) << students[i].grades[j];
        }
        outFile << endl;
    }
    outFile.close();
}