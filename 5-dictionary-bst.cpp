#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string word;
    string meaning;
    Node* left;
    Node* right;

    Node(string w, string m) {
        word = w;
        meaning = m;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node* insert(Node* root, string word, string meaning) {
        if (root == NULL)
            return new Node(word, meaning);

        if (word < root->word)
            root->left = insert(root->left, word, meaning);
        else if (word > root->word)
            root->right = insert(root->right, word, meaning);
        // Duplicate words are ignored
        return root;
    }

    void addWord(string word, string meaning) {
        root = insert(root, word, meaning);
    }

    Node* search(Node* root, string word) {
        if (root == NULL || root->word == word)
            return root;

        if (word < root->word)
            return search(root->left, word);
        else
            return search(root->right, word);
    }

    void searchWord(string word) {
        Node* result = search(root, word);
        if (result)
            cout << "Word: " << result->word << ". Meaning: " << result->meaning << endl;
        else
            cout << "Word not found!" << endl;
    }

    Node* findMin(Node* root) {
        while (root->left)
            root = root->left;
        return root;
    }

    Node* deleteNode(Node* root, string word) {
        if (root == NULL)
            return root;

        if (word < root->word)
            root->left = deleteNode(root->left, word);
        else if (word > root->word)
            root->right = deleteNode(root->right, word);
        else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = findMin(root->right);
            root->word = temp->word;
            root->meaning = temp->meaning;
            root->right = deleteNode(root->right, temp->word);
        }
        return root;
    }

    void deleteWord(string word) {
        root = deleteNode(root, word);
    }

    void updateWord(string word, string newMeaning) {
        Node* result = search(root, word);
        if (result)
            result->meaning = newMeaning;
        else
            cout << "Word not found!" << endl;
    }

    void displayAscending(Node* root) {
        if (root) {
            displayAscending(root->left);
            cout << root->word << " - " << root->meaning << endl;
            displayAscending(root->right);
        }
    }

    void displayDescending(Node* root) {
        if (root) {
            displayDescending(root->right);
            cout << root->word << " - " << root->meaning << endl;
            displayDescending(root->left);
        }
    }

    void displayWords(bool ascending = true) {
        if (ascending) {
            cout << "\nWords in Ascending Order:\n";
            displayAscending(root);
        } else {
            cout << "\nWords in Descending Order:\n";
            displayDescending(root);
        }
    }
};

int main() {
    BST bst;
    int choice;
    string word, meaning;

    do {
        cout << "\nDictionary Operations:\n";
        cout << "1. Add Word\n";
        cout << "2. Search Word\n";
        cout << "3. Update Meaning\n";
        cout << "4. Delete Word\n";
        cout << "5. Display Words (Ascending)\n";
        cout << "6. Display Words (Descending)\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To consume newline character

        switch (choice) {
        case 1:
            cout << "Enter word: ";
            getline(cin, word);
            cout << "Enter meaning: ";
            getline(cin, meaning);
            bst.addWord(word, meaning);
            break;

        case 2:
            cout << "Enter word to search: ";
            getline(cin, word);
            bst.searchWord(word);
            break;

        case 3:
            cout << "Enter word to update: ";
            getline(cin, word);
            cout << "Enter new meaning: ";
            getline(cin, meaning);
            bst.updateWord(word, meaning);
            break;

        case 4:
            cout << "Enter word to delete: ";
            getline(cin, word);
            bst.deleteWord(word);
            break;

        case 5:
            bst.displayWords(true);
            break;

        case 6:
            bst.displayWords(false);
            break;

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
