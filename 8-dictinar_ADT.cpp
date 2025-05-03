//ass 8
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int chain;
    string word, mean;
} obj[10];

int hash_fun(string wd) {
    int key = 0;
    for (char ch : wd) {
        key += ch;
    }
    return key % 10;
}

void collision(int key, string wd, string mn) {
    int i = 1;
    while ((key + i) % 10 < 10) {
        if (obj[(key + i) % 10].word == "-") {
            obj[(key + i) % 10].word = wd;
            obj[(key + i) % 10].mean = mn;
            obj[(key + i - 1) % 10].chain = (key + i) % 10;
            return;
        }
        i++;
    }
}

void hash_ini() {
    for (int i = 0; i < 10; i++) {
        obj[i].word = "-";
        obj[i].mean = "-";
        obj[i].chain = -1;
    }
}

void hash_table() {
    string wd, mn;
    cout << "\nEnter a word = ";
    cin >> wd;
    cout << "Enter meaning of above word = ";
    cin >> mn;
    
    int hash_key = hash_fun(wd);
    if (obj[hash_key].word == "-") {
        obj[hash_key].word = wd;
        obj[hash_key].mean = mn;
    } 
    else {
        collision(hash_key, wd, mn);
    }
}

void display() {
    cout << "Index \t Word \t Meaning \t Chain\n";
    for (int i = 0; i < 10; i++) {
        cout << i << " \t" << obj[i].word << "          \t" << obj[i].mean << " \t" << obj[i].chain << " \n";
    }
}

void del_key(string word) {
    int key = hash_fun(word);
    if (obj[key].word == word) {
        obj[key].word = "-";
        obj[key].mean = "-";
        obj[key].chain = -1;
        cout << "\nDeletion is successful!!\n";
    } else {
        int tar = obj[key].chain;
        int prev = key;
        while (tar != -1) {
            if (obj[tar].word == word) {
                obj[prev].chain = obj[tar].chain;
                obj[tar].word = "-";
                obj[tar].mean = "-";
                obj[tar].chain = -1;
                cout << "\nDeletion is successful!!\n";
                return;
            }
            prev = tar;
            tar = obj[tar].chain;
        }
        cout << "\nWord not found!!!\n";
    }
}

void find(string word) {
    int key = hash_fun(word);
    if (obj[key].word == word) {
        cout << "Found the word: " << obj[key].word << " -> " << obj[key].mean << endl;
    } else {
        int tar = obj[key].chain;
        while (tar != -1) {
            if (obj[tar].word == word) {
                cout << "Found the word: " << obj[tar].word << " -> " << obj[tar].mean << endl;
                return;
            }
            tar = obj[tar].chain;
        }
        cout << "\nWord Not Found!!!\n";
    }
}

int main() {
    int ch;
    string delwd, src;
    hash_ini();

    while (true) {
        cout << "\n1. Insert in hash table";
        cout << "\n2. Display hash table";
        cout << "\n3. Delete a word";
        cout << "\n4. Find a word";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: {
                int n;
                cout << "Enter number of entries: ";
                cin >> n;
                for (int j = 0; j < n; j++) {
                    hash_table();
                }
                break;
            }
            case 2:
                display();
                break;
            case 3:
                cout << "Enter word you want to delete: ";
                cin >> delwd;
                del_key(delwd);
                break;
            case 4:
                cout << "Enter word you want to find: ";
                cin >> src;
                find(src);
                break;
            case 5:
                exit(0);
            default:
                cout << "\nInvalid choice! Try again.\n";
        }
    } 

    return 0;
}