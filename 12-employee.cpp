#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Employee {
public:
    int id;
    double salary;
    char name[50];

    static const char* filename;

    void addEmployee() {
        ofstream file(filename, ios::binary | ios::app);
        Employee emp;

        cout << "Enter Employee ID: ";
        cin >> emp.id;
        cin.ignore();

        cout << "Enter Employee Name: ";
        cin.getline(emp.name, 50);

        cout << "Enter Employee Salary: ";
        cin >> emp.salary;

        file.write((const char*)&emp, sizeof(Employee));
        file.close();

        cout << "Employee added successfully!" << endl;
    }

    void deleteEmployee() {
        int empID;
        bool found = false;

        cout << "Enter Employee ID to delete: ";
        cin >> empID;

        ifstream file(filename, ios::binary);
        ofstream temp("temp.dat", ios::binary);

        Employee emp;

        while (file.read((char*)&emp, sizeof(Employee))) {
            if (emp.id != empID) {
                temp.write((const char*)&emp, sizeof(Employee));
            } else {
                found = true;
            }
        }

        file.close();
        temp.close();

        remove(filename);
        rename("temp.dat", filename);

        if (found) {
            cout << "Employee deleted successfully!" << endl;
        } else {
            cout << "Employee not found!" << endl;
        }
    }

    void displayEmployee() {
        ifstream file(filename, ios::binary);
        Employee emp;
        bool found = false;
    
        cout << "\n----- Employee List -----\n";
        while (file.read((char*)&emp, sizeof(Employee))) {
            found = true;
            cout << "Employee ID: " << emp.id << endl;
            cout << "Name       : " << emp.name << endl;
            cout << "Salary     : " << emp.salary << endl;
            cout << "---------------------------" << endl;
        }
    
        file.close();
    
        if (!found) {
            cout << "No employee records found." << endl;
        }
    }
    
    
    
};

const char* Employee::filename = "employee_data.dat";

int main() {
    Employee emp;
    int choice;

    while (true) {
        cout << "\n***** Employee Management System *****" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Delete Employee" << endl;
        cout << "3. Display Employee" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                emp.addEmployee();
                break;
            case 2:
                emp.deleteEmployee();
                break;
            case 3:
                emp.displayEmployee();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}
