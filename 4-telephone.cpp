#include <iostream>
using namespace std;

class telephone {
public:
    int mob[10];
    string name[10];

    telephone() {
        for (int i = 0; i < 10; i++) {
            mob[i] = -1;
        }
    }
    
    void linear_probing() {
        int key;
        cout << "Enter telephone number: ";
        cin >> key;
        int hash_address = key % 10;

        if (mob[hash_address] == -1) {
            mob[hash_address] = key;
            cout << "Enter name: ";
            cin >> name[hash_address];
        } 
        else {
            int i = 1;
            while ((hash_address + i) < 10) {
                if (mob[hash_address + i] == -1) 
                {
                    mob[hash_address + i] = key;
                    cout << "Enter name: ";
                    cin >> name[hash_address + i];
                    return;
                }
                i++;	
            }   
            cout << "Hash table is full or no space available for this key.\n";x`
        }
    }

    void quadratic_probing() {
        int key;
        cout << "Enter telephone number: ";
        cin >> key;
        int hash_address = key % 10;

        if (mob[hash_address] == -1) {
            mob[hash_address] = key;
            cout << "Enter name: ";
            cin >> name[hash_address];
        } else {
            int i = 1;
            while (i < 10) {
                int new_address = (hash_address + i * i) % 10;
                if (mob[new_address] == -1) {
                    mob[new_address] = key;
                    cout << "Enter name: ";
                    cin >> name[new_address];
                    return;
                }
                i++;
            }
            cout << "Hash table is full or no space available for this key.\n";
        }
    }

    void display() {
        cout << "Telephone Directory:\n";
        for (int i = 0; i < 10; i++) {
            if (mob[i] != -1) {
                cout << i << " -> " << name[i] << " : " << mob[i] << endl;
            }
        }
    }
};

int main() {
    telephone t;
    int ch, n;
    while (true) {
        cout << "\n1. Linear Probing\n2. Quadratic Probing\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter number of entries: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    t.linear_probing();
                }
                break;
            case 2:
                cout << "Enter number of entries: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    t.quadratic_probing();
                }
                break;
            case 3:
                t.display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid input."<<endl;
        }
    }
    return 0;
}
