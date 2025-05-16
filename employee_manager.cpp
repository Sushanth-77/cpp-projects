
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Employee {
    int id;
    string name;
    string department;
    double salary;
};

vector<Employee> employees;

void addEmployee() {
    Employee emp;
    cout << "Enter Employee ID: ";
    cin >> emp.id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, emp.name);
    cout << "Enter Department: ";
    getline(cin, emp.department);
    cout << "Enter Salary: ";
    cin >> emp.salary;
    employees.push_back(emp);
    cout << "Employee added successfully!\n";
}

void viewEmployees() {
    if (employees.empty()) {
        cout << "No employee records found.\n";
        return;
    }
    cout << "\n--- Employee Records ---\n";
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(20) << "Department" << "Salary\n";
    for (const auto& emp : employees) {
        cout << left << setw(10) << emp.id << setw(20) << emp.name << setw(20) << emp.department << emp.salary << "\n";
    }
}

void searchEmployee() {
    int id;
    cout << "Enter Employee ID to search: ";
    cin >> id;
    for (const auto& emp : employees) {
        if (emp.id == id) {
            cout << "Found: " << emp.name << ", Dept: " << emp.department << ", Salary: " << emp.salary << "\n";
            return;
        }
    }
    cout << "Employee not found.\n";
}

void updateEmployee() {
    int id;
    cout << "Enter Employee ID to update: ";
    cin >> id;
    for (auto& emp : employees) {
        if (emp.id == id) {
            cout << "Enter new Name (current: " << emp.name << "): ";
            cin.ignore();
            getline(cin, emp.name);
            cout << "Enter new Department (current: " << emp.department << "): ";
            getline(cin, emp.department);
            cout << "Enter new Salary (current: " << emp.salary << "): ";
            cin >> emp.salary;
            cout << "Employee updated successfully.\n";
            return;
        }
    }
    cout << "Employee not found.\n";
}

void deleteEmployee() {
    int id;
    cout << "Enter Employee ID to delete: ";
    cin >> id;
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if (it->id == id) {
            employees.erase(it);
            cout << "Employee deleted.\n";
            return;
        }
    }
    cout << "Employee not found.\n";
}

int main() {
    int choice;
    while (true) {
        cout << "\n--- Employee Management System ---\n";
        cout << "1. Add Employee\n2. View All Employees\n3. Search Employee\n4. Update Employee\n5. Delete Employee\n6. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addEmployee(); break;
            case 2: viewEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
}
