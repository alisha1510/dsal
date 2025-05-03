#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string key, val;
    int height;
    Node* Ln;
    Node* Rn;
    

    Node(string k, string v) {
        key = k;
        val = v;
        Ln = Rn = nullptr;
        height = 1;
    }
};

int getHeight(Node* n) {
    if (n != NULL)
        return n->height;
    else
        return 0;
}

int getBalance(Node* n) {
    return n ? getHeight(n->Ln) - getHeight(n->Rn) : 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* rightRotate(Node* y) {
    Node* x = y->Ln;
    Node* T2 = x->Rn;
    x->Rn = y;
    y->Ln = T2;
    y->height = max(getHeight(y->Ln), getHeight(y->Rn)) + 1;
    x->height = max(getHeight(x->Ln), getHeight(x->Rn)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->Rn;
    Node* T2 = y->Ln;
    y->Ln = x;
    x->Rn = T2;
    x->height = max(getHeight(x->Ln), getHeight(x->Rn)) + 1;
    y->height = max(getHeight(y->Ln), getHeight(y->Rn)) + 1;
    return y;
}

Node* insert(Node* node, string key, string val) {
    if (!node)
        return new Node(key, val);

    if (key < node->key)
        node->Ln = insert(node->Ln, key, val);
    else if (key > node->key)
        node->Rn = insert(node->Rn, key, val);
    else {
        cout << "Duplicate keyword not allowed.\n";
        return node;
    }

    node->height = 1 + max(getHeight(node->Ln), getHeight(node->Rn));
    int balance = getBalance(node);

    // Rotations
    if (balance > 1 && key < node->Ln->key)
        return rightRotate(node);
    if (balance < -1 && key > node->Rn->key)
        return leftRotate(node);
    if (balance > 1 && key > node->Ln->key) {
        node->Ln = leftRotate(node->Ln);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->Rn->key) {
        node->Rn = rightRotate(node->Rn);
        return leftRotate(node);
    }

    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->Ln)
        current = current->Ln;
    return current;
}

Node* deleteNode(Node* root, string key) {
    if (!root)
        return root;

    if (key < root->key)
        root->Ln = deleteNode(root->Ln, key);
    else if (key > root->key)
        root->Rn = deleteNode(root->Rn, key);
    else {
        if (!root->Ln || !root->Rn) {
            Node* temp = root->Ln ? root->Ln : root->Rn;
            if (!temp) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(root->Rn);
            root->key = temp->key;
            root->val = temp->val;
            root->Rn = deleteNode(root->Rn, temp->key);
        }
    }

    if (!root)
        return root;

    root->height = 1 + max(getHeight(root->Ln), getHeight(root->Rn));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->Ln) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->Ln) < 0) {
        root->Ln = leftRotate(root->Ln);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->Rn) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->Rn) > 0) {
        root->Rn = rightRotate(root->Rn);
        return leftRotate(root);
    }

    return root;
}

void inorder(Node* root) {
    if (!root)
        return;
    inorder(root->Ln);
    cout << root->key << " : " << root->val << endl;
}


void update(Node* root, string key) {
    if (!root) {
        cout << "Keyword not found.\n";
        return;
    }

    if (key < root->key)
        update(root->Ln, key);
    else if (key > root->key)
        update(root->Rn, key);
    else {
        cout << "Current meaning: " << root->val << endl;
        cout << "Enter new meaning: ";
        cin.ignore();
        getline(cin, root->val);
        cout << "Updated successfully.\n";
    }
}

// Function to find max comparisons for searching
int maxComparisons(Node* root) {
    if (!root)
        return 0;
    return 1 + max(maxComparisons(root->Ln), maxComparisons(root->Rn));
}

int main() {
    Node* root = nullptr;
    int choice;
    string key, val;

    do {
        cout << "\nDictionary Menu:\n";
        cout << "1. Add keyword\n";
        cout << "2. Delete keyword\n";
        cout << "3. Update meaning\n";
        cout << "4. Display Ascending\n";
        cout << "5. Max comparisons for search\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter keyword: ";
            cin >> key;
            cout << "Enter meaning: ";
            cin.ignore();
            getline(cin, val);
            root = insert(root, key, val);
            break;
        case 2:
            cout << "Enter keyword to delete: ";
            cin >> key;
            root = deleteNode(root, key);
            break;
        case 3:
            cout << "Enter keyword to update: ";
            cin >> key;
            update(root, key);
            break;
        case 4:
            cout << "Dictionary in ascending order:\n";
            inorder(root);
            break;
        
            
        case 5:
            cout << "Maximum comparisons for search: " << maxComparisons(root) << endl;
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
