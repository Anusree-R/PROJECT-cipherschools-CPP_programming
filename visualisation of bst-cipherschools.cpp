//VISUALISATION OF BST
#include <iostream>
#include <queue>
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


void printSpaces(int n) {
    for (int i = 0; i < n; ++i) {
        cout << " ";
    }
}


void printBST(TreeNode* root, int space) {
   
    if (root == NULL) {
        return;
    }

   
    space += 5;

   
    printBST(root->right, space);

   
    cout << endl;
    printSpaces(space);
    cout << root->key << "\n";

    
    printBST(root->left, space);
}


int main() {
    TreeNode* root = NULL;
    int key;

    cout << "Binary Search Tree Visualization" << endl;
    cout << "Enter nodes to insert into BST (enter -1 to stop):" << endl;

    
    while (true) {
        cout << "Enter key (or -1 to stop): ";
        cin >> key;
        if (key == -1) {
            break;
        }
        root = insert(root, key);
    }

   
    cout << "\nVisual Representation of BST:" << endl;
    printBST(root, 0);

    return 0;
}

