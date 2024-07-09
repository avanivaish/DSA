#include <iostream>
#include <climits>

using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to find the kth ancestor
Node* solve(Node* root, int &k, int node) {
    // base case
    if (root == NULL) return NULL;
    if (root->data == node) return root;
    
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);
    
    if (leftAns != NULL && rightAns == NULL) {
        k--;
        if (k <= 0) {
            k = INT_MAX;
            return root;
        } else {
            return leftAns;
        }
    }
    if (leftAns == NULL && rightAns != NULL) {
        k--;
        if (k <= 0) {
            k = INT_MAX;
            return root;
        } else {
            return rightAns;
        }
    }
    return NULL;
}

int kthAncestor(Node *root, int k, int node) {
    Node* ans = solve(root, k, node);
    if (ans == NULL || ans->data == node) return -1;
    else return ans->data;
}

int main() {
    // Create the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int k = 2;
    int node = 5;
    
    int ancestor = kthAncestor(root, k, node);
    if (ancestor == -1) {
        cout << "Kth ancestor does not exist." << endl;
    } else {
        cout << "The " << k << "th ancestor of node " << node << " is " << ancestor << "." << endl;
    }

    // Clean up the memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
