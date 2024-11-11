

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

void gradeTestScores(int scores[]) {
    const int A_score = 90,
              B_score = 80,
              C_score = 70,
              D_score = 60;

    const int A = 4,
              B = 3,
              C = 2,
              D = 1,
              F = 0;

    int total = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        string subjects_list[] = {"Applied two", "C++", "Civics", "Technical Drawing", "Writing Skill", "Emerging Technology"};
        cout << "Enter result of: " << subjects_list[i] << ": ";
        int result;
        cin >> result;
        if (result >= A_score && result <= 100) {
            cout << "Your grade is A." << endl;
            cout << "Your point is: " << A << endl;
            total += A * CREDIT_HOUR;
        } else if (result >= B_score) {
            cout << "Your grade is B." << endl;
            cout << "Your point is: " << B << endl;
            total += B * CREDIT_HOUR;
        } else if (result >= C_score) {
            cout << "Your grade is C." << endl;
            cout << "Your point is: " << C << endl;
            total += C * CREDIT_HOUR;
        } else if (result >= D_score) {
            cout << "Your grade is D." << endl;
            cout << "Your point is: " << D << endl;
            total += D * CREDIT_HOUR;
        } else {
            cout << "Your grade is F." << endl;
            cout << "Your point is: " << F << endl;
        }
        scores[i] = result;
    }
    float GPA = static_cast<float>(total) / (NUM_SUBJECTS * CREDIT_HOUR);
    cout << "Total points: " << total << endl;
    cout << "GPA: " << GPA << endl;
    if (GPA >= 1.8)
        cout << "Congratulations, you passed to the next semester." << endl;
    else
        cout << "Sorry, you failed." << endl;
}


void report(const Student students[], int numStudents) {
    float totalGPA = 0;
    int passedCount = 0;
    int failedCount = 0;

    cout << "-------- Report --------" << endl;
    cout << "Number of Students: " << numStudents << endl;

    for (int i = 0; i < numStudents; ++i) {
        float studentGPA = calculateGPA(students[i].grades);
        totalGPA += studentGPA;
        if (studentGPA >= 1.8) {
            passedCount++;
        } else {
            failedCount++;
        }
    }

    cout << "Average GPA: " << (totalGPA / numStudents) << endl;
    cout << "Students Passed: " << passedCount << endl;
    cout << "Students Failed: " << failedCount << endl;
}

void addStudent(Student students[], int& numStudents) {
    if (numStudents < MAX_STUDENTS) {
        cout << "Enter student ID: ";
        cin >> students[numStudents].id;
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, students[numStudents].name);
        cout << "Enter student age: ";
        cin >> students[numStudents].age;
        cout << "Enter student phone number: ";
        cin >> students[numStudents].phoneNumber;
        cout << "Enter student sex (M/F): ";
        cin >> students[numStudents].sex;
        cout << "Enter grades for each subject:" << endl;
        gradeTestScores(students[numStudents].grades);
        numStudents++;
        saveStudentData(students, numStudents, "student_data.txt");
    } else {
        cout << "Maximum number of students reached." << endl;
    }
}


void removeStudentByID(Student students[], int& numStudents, const string& idToRemove) {
    bool found = false;
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].id == idToRemove) {
            for (int j = i; j < numStudents - 1; ++j) {
                students[j] = students[j + 1];
            }
            numStudents--;
            cout << "Student with ID " << idToRemove << " removed successfully." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student with ID " << idToRemove << " not found." << endl;
    }
}