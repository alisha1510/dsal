//A book consists of chapters, chapters consist of sections and sections consist of subsections. Construct a tree and print the nodes. Find the time and space requirements of your method.

#include<iostream>
using namespace std;


struct node {
    char name[50]; 
    int count;
    struct node* child[10];
} *root = NULL;

class book {
public:
    book() {
        root = NULL;
    }

    void create() {
        root = new node();
        cout << "Enter book name: ";
        cin >> root->name;
        cout << "Enter number of chapters: ";
        cin >> root->count;

        for (int i = 0; i < root->count; i++) {
            root->child[i] = new node();
            cout << "Enter chapter name: ";
            cin >> root->child[i]->name;
            cout << "Enter number of sections in chapter: ";
            cin >> root->child[i]->count;

            for (int j = 0; j < root->child[i]->count; j++) {
                root->child[i]->child[j] = new node();
                cout << "Enter section name: ";
                cin >> root->child[i]->child[j]->name;
                cout << "Enter number of subsections in section: ";
                cin >> root->child[i]->child[j]->count;

                for (int k = 0; k < root->child[i]->child[j]->count; k++) {
                    root->child[i]->child[j]->child[k] = new node();
                    cout << "Enter subsection name for section ";
                    cin >> root->child[i]->child[j]->child[k]->name;
                    // No further nesting beyond subsection
                    root->child[i]->child[j]->child[k]->count = 0;
                }
            }
        }
    }

    void display(node* n, int indent = 0) {
        if (n == NULL) return;

        for (int i = 0; i < indent; i++) cout << "  "; // Indentation

        cout << n->name << endl;
        
        for (int i = 0; i < n->count; i++) {
            display(n->child[i], indent + 1);
        }
    }
};

int main() {
    book b;
    b.create();
    cout << "\nBook Structure:\n";
    b.display(root);
    return 0;
}
