//VISUALISATION OF BST
#include <iostream>
#include <queue>
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

// Function to print spaces for indentation
void printSpaces(int n) {
    for (int i = 0; i < n; ++i) {
        cout << " ";
    }
}

// Function to print BST visually in a hierarchical structure
void printBST(TreeNode* root, int space) {
    // Base case
    if (root == NULL) {
        return;
    }

    // Increase distance between levels
    space += 5;

    // Process right child first
    printBST(root->right, space);

    // Print current node after space
    cout << endl;
    printSpaces(space);
    cout << root->key << "\n";

    // Process left child
    printBST(root->left, space);
}

// Main function
int main() {
    TreeNode* root = NULL;
    int key;

    cout << "Binary Search Tree Visualization" << endl;
    cout << "Enter nodes to insert into BST (enter -1 to stop):" << endl;

    // Input nodes from user
    while (true) {
        cout << "Enter key (or -1 to stop): ";
        cin >> key;
        if (key == -1) {
            break;
        }
        root = insert(root, key);
    }

    // Print the BST visually
    cout << "\nVisual Representation of BST:" << endl;
    printBST(root, 0);

    return 0;
}

