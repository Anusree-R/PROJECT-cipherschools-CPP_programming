//TASK 2
//construct a bst and implement insert,search,delete,inorder traversal,preorder traversal,postorder traversal, inverting a binary tree operations
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

TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;
   
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}


TreeNode* deleteNode(TreeNode* root, int key) {
   
    if (root == NULL) {
        return root;
    }

    
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        
        TreeNode* temp = minValueNode(root->right);

       
        root->key = temp->key;

        
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}


void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}


void postorder(TreeNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}


void preorder(TreeNode* root) {
    if (root != NULL) {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}


TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    
    TreeNode* temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);

    return root;
}


int main() {
    TreeNode* root = NULL;
    int choice, key;

    do {
        cout << "\nBinary Search Tree Operations:" << endl;
        cout << "1. Insert a key" << endl;
        cout << "2. Search for a key" << endl;
        cout << "3. Delete a key" << endl;
        cout << "4. Inorder traversal" << endl;
        cout << "5. Postorder traversal" << endl;
        cout << "6. Preorder traversal" << endl;
        cout << "7. Invert the binary tree" << endl;
        cout << "8. Exit" << endl;
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
                cout << "Enter key to delete: ";
                cin >> key;
                root = deleteNode(root, key);
                break;
            case 4:
                cout << "Inorder traversal of BST: ";
                inorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Postorder traversal of BST: ";
                postorder(root);
                cout << endl;
                break;
            case 6:
                cout << "Preorder traversal of BST: ";
                preorder(root);
                cout << endl;
                break;
            case 7:
                root = invertTree(root);
                cout << "Binary tree inverted." << endl;
                break;
            case 8:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 8);

    return 0;
}

