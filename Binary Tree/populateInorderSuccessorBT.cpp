#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node* next;

    Node(int val) {
        data = val;
        left = right = next = NULL;
    }
};

class Solution {
  public:
    void populateNext(Node *root) {
        Node* prev = NULL;
        solve(root, prev);
    }
    
    void solve(Node* root, Node* &prev) {
        if (!root) return;
        solve(root->left, prev);
        if (prev != NULL) {
            prev->next = root;
        }
        prev = root;
        solve(root->right, prev);
    }
};

void printInorder(Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

void printNextPointers(Node* root) {
    Node* current = root;
    while (current != NULL) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create the binary tree
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(3);

    // Print the inorder traversal of the tree
    cout << "Inorder Traversal of the Tree: ";
    printInorder(root);
    cout << endl;

    // Populate next pointers
    Solution sol;
    sol.populateNext(root);

    // Print the next pointers
    cout << "Next Pointers of Nodes: ";
    printNextPointers(root->left->left); // Start from the leftmost node

    return 0;
}
