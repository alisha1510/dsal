#include <iostream>
using namespace std;
	
class node {
public:
    int key;
    node *ln, *rn;
};


class Tree {
public:
    node* root;

    Tree() {
        root = NULL;
    }

    node* createTree(int key) {
        root = new node();
        root->key = key;
        root->ln = NULL;
        root->rn = NULL;
        return root;
    }

    void insertnode(int key, node* root) {
        node* new_node = new node();
        new_node->key = key;
        new_node->ln = NULL;
        new_node->rn = NULL;

        if (root->key >= key) {
            if (root->ln == NULL) {
                root->ln = new_node;
            } 
            else {
                insertnode(key, root->ln);
            }
        } 
    else {
            if (root->rn == NULL) {
                root->rn = new_node;
            } 
            else {
                insertnode(key, root->rn);
            }
        }
    }

    void displayInorder(node* root) {
        if (root != NULL) {
            displayInorder(root->ln);
            cout << root->key << "\n";
            displayInorder(root->rn);
        }
    }
//post order and preorder too 
    void displaymin(node* root) {
        while (root->ln != NULL) {
            root = root->ln;
        }
        cout << "Minimum number is " << root->key<<endl;
    }

    void search(node* root, int searchKey) {
        if (root == NULL) {
            cout << "Number not found"<<endl;
            return;
        }

        if (searchKey < root->key) {
            search(root->ln, searchKey);
        } 
        else if (searchKey > root->key) {
            search(root->rn, searchKey);
        } 
        else {
            cout << "\nNumber Found!";
        }
    }

    int longestPath(node* root) {
        if (root == NULL)
            return 0;
        int Lctr = longestPath(root->ln);
        int Rctr = longestPath(root->rn);
        return max(Lctr, Rctr) + 1;
    }

    node* swapNodes(node* root) {
        if (root == NULL)
            return NULL;
        node* temp = root->ln;
        root->ln = root->rn;
        root->rn = temp;

        swapNodes(root->ln);
        swapNodes(root->rn);
        return root;
    }
};

int main() {
    Tree t;
    int ch, key, n;

    while (true) {
        cout << "\n1. Insert node";
        cout << "\n2. Display inorder";
        cout << "\n3. Display minimum node";
        cout << "\n4. Search node";
        cout << "\n5. Longest path of node";
        cout << "\n6. Swap nodes";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter number of entries: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "Enter value: ";
                    cin >> key;
                    if (t.root == NULL)
                        t.root = t.createTree(key);
                    else
                        t.insertnode(key, t.root);
                }
                break;

            case 2:
                t.displayInorder(t.root);
                break;

            case 3:
                t.displaymin(t.root);
                break;

            case 4:
                cout << "Enter value to search: ";
                cin >> key;
                t.search(t.root, key);
                break;

            case 5:
                cout << "Longest path length: " << t.longestPath(t.root) << endl;
                break;

            case 6:
                t.swapNodes(t.root);
                cout << "Tree nodes swapped.\n";
                break;

            case 7:
                exit(0);

            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}
