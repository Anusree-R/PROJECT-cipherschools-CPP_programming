//TASK 1
//construct a bst and implement insert and search operations
#include <iostream>
using namespace std;
struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int k) : key(k), left(NULL), right(NULL) {}
};
TreeNode* insert(TreeNode* root, int key) {
    if (root == NULL) {
        return new TreeNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}
TreeNode* search(TreeNode* root, int key) {
    
    if (root == NULL || root->key == key) {
        return root;
    }

    
    if (key < root->key) {
        return search(root->left, key);
    }

    
    return search(root->right, key);
}


int main() {
    TreeNode* root = NULL;
    int choice, key;

    do {
        cout << "\nBinary Search Tree Operations:" << endl;
        cout << "1. Insert a key" << endl;
        cout << "2. Search for a key" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                root = insert(root, key);
                break;
            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                if (search(root, key) != NULL) {
                    cout << "Key " << key << " found in the BST." << endl;
                } else {
                    cout << "Key " << key << " not found in the BST." << endl;
                }
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 3);

    return 0;
}
/*
#include <iostream>
using namespace std;


struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int k) : key(k), left(NULL), right(NULL) {}
};


TreeNode* insert(TreeNode* root, int key) {
    
    if (root == NULL) {
        return new TreeNode(key);
    }

    
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    
    return root;
}


TreeNode* search(TreeNode* root, int key) {
    
    if (root == NULL || root->key == key) {
        return root;
    }

    
    if (key < root->key) {
        return search(root->left, key);
    }

    
    return search(root->right, key);
}


int main() {
    TreeNode* root = NULL;

    // Inserting keys into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Search example
    int key_to_search = 60;
    TreeNode* result = search(root, key_to_search);
    if (result != NULL) {
        cout << "Key " << key_to_search << " found in the BST." << endl;
    } else {
        cout << "Key " << key_to_search << " not found in the BST." << endl;
    }

    return 0;
}
*/
