//A book consists of chapters, chapters consist of sections and sections consist of subsections. Construct a tree and print the nodes. Find the time and space requirements of your method.
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
	
class student {
public:
    int rollno;
    char name[20], add[20];
    char div;

    void get() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Roll no.: ";
        cin >> rollno;
        cout << "Enter Division: ";
        cin >> div;
        cout << "Enter Address: ";
        cin >> add;
    }

    void put() {
        cout << "Name: " << name << endl;
        cout << "Roll No.: " << rollno << endl;
        cout << "Division: " << div << endl;
        cout << "Address: " << add << endl;
        cout << "---------------------------------" << endl;
    }

    int getroll() {
        return rollno;
    }

    char getdiv() {
        return div;
    }
};

void write_record() {
    ofstream outFile;
    student obj;
    outFile.open("student.dat", ios::binary | ios::app);
    obj.get();
    outFile.write((char*)&obj, sizeof(obj));
    outFile.close();
}

void display_record() {
    ifstream inFile;
    student obj;
    inFile.open("student.dat", ios::binary);
    while (inFile.read((char*)&obj, sizeof(obj))) {
        obj.put();
    }
    inFile.close();
}

void search_record(int n, char d) {
    ifstream inFile;
    student obj;
    bool found = false;
    inFile.open("student.dat", ios::binary);
    while (inFile.read((char*)&obj, sizeof(obj))) {
        if (obj.getroll() == n && obj.getdiv() == d) {
            obj.put();
            found = true;
            break;
        }
    }
    inFile.close();
    if (!found)
        cout << "Record not found." << endl;
}

void delete_record(int n, char d) {
    student obj;
    ifstream inFile;
    ofstream outFile;
    bool found = false;
    inFile.open("student.dat", ios::binary);
    outFile.open("temp.dat", ios::binary);
    while (inFile.read((char*)&obj, sizeof(obj))) {
        if (obj.getroll() == n && obj.getdiv() == d) {
            found = true;
            continue; // Skip writing the matching record
        }
        outFile.write((char*)&obj, sizeof(obj));
    }
    inFile.close();
    outFile.close();

    if (found) {
        remove("student.dat");
        rename("temp.dat", "student.dat");
        cout << "Record Deleted" << endl;
    } else {
        remove("temp.dat"); // No need of temp file if no record deleted
        cout << "Record not found to delete." << endl;
    }
}

void modify_record(int n, char d) {
    fstream file;
    student obj;
    bool found = false;
    file.open("student.dat", ios::in | ios::out | ios::binary);
    while (file.read((char*)&obj, sizeof(obj))) {
        if (obj.getroll() == n && obj.getdiv() == d) {
            cout << "Enter new details: " << endl;
            obj.get();
            int pos = -1 * static_cast<int>(sizeof(obj));
            file.seekp(pos, ios::cur);
            file.write((char*)&obj, sizeof(obj));
            found = true;
            cout << "Record Modified" << endl;
            break;
        }
    }
    file.close();
    if (!found)
        cout << "Record not found to modify." << endl;
}

int main() {
    int ch, n;
    char d;
    cout << "*Student Data using Sequential file*\n";
    while (true) {
        cout << "\n1. Write Info" << endl;
        cout << "2. Display Info" << endl;
        cout << "3. Search Info" << endl;
        cout << "4. Delete Info" << endl;
        cout << "5. Modify Info" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter number of records: ";
                cin >> n;
                for (int i = 0; i < n; i++)
                    write_record();
                break;
            case 2:
                display_record();
                break;
            case 3:
                cout << "Enter Roll No. to search: ";
                cin >> n;
                cout << "Enter Division: ";
                cin >> d;
                search_record(n, d);
                break;
            case 4:
                cout << "Enter Roll No. to delete: ";
                cin >> n;
                cout << "Enter Division: ";
                cin >> d;
                delete_record(n, d);
                break;
            case 5:
                cout << "Enter Roll No. to modify: ";
                cin >> n;
                cout << "Enter Division: ";
                cin >> d;
                modify_record(n, d);
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid choice, try again!" << endl;
        }
    }
    return 0;
}
