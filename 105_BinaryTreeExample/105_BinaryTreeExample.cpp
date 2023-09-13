#include <iostream>

// Define the structure of a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the binary tree
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        // If the tree is empty, create a new node as the root
        return new TreeNode(value);
    }

    // Otherwise, recursively insert into the left or right subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to perform an in-order traversal of the binary tree
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Traverse the left subtree
    inorderTraversal(root->left);

    // Visit the current node
    std::cout << root->data << " ";

    // Traverse the right subtree
    inorderTraversal(root->right);
}

int main() {
    TreeNode* root = nullptr;

    // Insert values into the binary tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    // Perform an in-order traversal to display the values in sorted order
    std::cout << "In-order traversal (sorted values): ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}

/*
In this code:

We define a TreeNode struct to represent the nodes of the binary tree.
Each node contains an integer value (data) and pointers to its left and right children (left and right).

We create a function insert to insert a new node with a given value into the binary tree.
The insertion is performed recursively based on the value, with smaller values going to the left subtree and larger values going to the right subtree.

We define a function inorderTraversal to perform an in-order traversal of the binary tree.
In-order traversal visits nodes in ascending order, which is why it's suitable for displaying sorted values.

In the main function, we create an empty binary tree represented by the root pointer.

We insert several values (50, 30, 70, 20, 40, 60, 80) into the binary tree using the insert function.

Finally, we perform an in-order traversal of the tree to display the values in sorted order.
The output will be "In-order traversal (sorted values): 20 30 40 50 60 70 80".
*/