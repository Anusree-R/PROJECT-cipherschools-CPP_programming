//TASK 2
#include <iostream>
using namespace std;

// Define the structure for BST nodes
struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int k) : key(k), left(NULL), right(NULL) {}
};

// Function to insert a key into the BST
TreeNode* insert(TreeNode* root, int key) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return new TreeNode(key);
    }

    // Otherwise, recur down the tree
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    // Return the unchanged node pointer
    return root;
}

// Function to search a given key in BST
TreeNode* search(TreeNode* root, int key) {
    // Base cases: root is null or key is present at the root
    if (root == NULL || root->key == key) {
        return root;
    }

    // Key is greater than root's key
    if (key < root->key) {
        return search(root->left, key);
    }

    // Key is smaller than root's key
    return search(root->right, key);
}

// Function to find the minimum value node in a subtree
TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;
    // Loop down to find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a key from BST
TreeNode* deleteNode(TreeNode* root, int key) {
    // Base case: if the tree is empty
    if (root == NULL) {
        return root;
    }

    // Otherwise, recur down the tree
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        TreeNode* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Function to perform inorder traversal of BST
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Function to perform postorder traversal of BST
void postorder(TreeNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}

// Function to perform preorder traversal of BST
void preorder(TreeNode* root) {
    if (root != NULL) {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to invert a binary tree
TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    // Swap left and right subtrees
    TreeNode* temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);

    return root;
}

// Main function
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

