#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

void inorderTraversal(Node* root, int &count) {
    if (root == NULL) return;
    inorderTraversal(root->left, count);
    if (root->left == NULL && root->right == NULL) {
        count++;
    }
    inorderTraversal(root->right, count);
}

int countLeaves(Node* root) {
    int count = 0;
    inorderTraversal(root, count);
    return count;
}

int main() {
    // Create a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Count the leaves
    int leafCount = countLeaves(root);
    cout << "Number of leaves: " << leafCount << endl;

    // Clean up memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
