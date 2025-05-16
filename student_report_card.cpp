
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    int rollNo;
    string name;
    int marks[5];
    float average;
    char grade;
};

vector<Student> students;

float calculateAverage(int marks[]) {
    int total = 0;
    for (int i = 0; i < 5; ++i) total += marks[i];
    return total / 5.0f;
}

char calculateGrade(float average) {
    if (average >= 90) return 'A';
    else if (average >= 75) return 'B';
    else if (average >= 60) return 'C';
    else if (average >= 45) return 'D';
    else return 'F';
}

void addStudent() {
    Student s;
    cout << "Enter Roll No: ";
    cin >> s.rollNo;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter marks for 5 subjects:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "Subject " << i + 1 << ": ";
        cin >> s.marks[i];
    }
    s.average = calculateAverage(s.marks);
    s.grade = calculateGrade(s.average);
    students.push_back(s);
    cout << "Student record added.\n";
}

void displayStudent(const Student& s) {
    cout << left << setw(10) << s.rollNo << setw(20) << s.name
         << setw(10) << s.average << setw(10) << s.grade << endl;
}

void viewAllStudents() {
    if (students.empty()) {
        cout << "No student records found.\n";
        return;
    }
    cout << left << setw(10) << "RollNo" << setw(20) << "Name"
         << setw(10) << "Average" << setw(10) << "Grade" << endl;
    for (const auto& s : students) {
        displayStudent(s);
    }
}

void searchStudent() {
    int roll;
    cout << "Enter Roll No to search: ";
    cin >> roll;
    for (const auto& s : students) {
        if (s.rollNo == roll) {
            cout << "Record found:\n";
            displayStudent(s);
            return;
        }
    }
    cout << "Student not found.\n";
}

void deleteStudent() {
    int roll;
    cout << "Enter Roll No to delete: ";
    cin >> roll;
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->rollNo == roll) {
            students.erase(it);
            cout << "Record deleted.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

int main() {
    int choice;
    while (true) {
        cout << "\n--- Student Report Card System ---\n";
        cout << "1. Add Student\n2. View All Students\n3. Search Student\n4. Delete Student\n5. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewAllStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
}
