#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    void solve(Node* root, int k, int &count, vector<int>& path) {
        if(root == NULL) return;
        path.push_back(root->data);
        solve(root->left, k, count, path);
        solve(root->right, k, count, path);
        // Check k sum
        int sum = 0;
        int size = path.size();
        for(int i = size - 1; i >= 0; i--) {
            sum += path[i];
            if(sum == k) count++;
        }
        path.pop_back();
    }

    int sumK(Node* root, int k) {
        vector<int> path;
        int count = 0;
        solve(root, k, count, path);
        return count;
    }
};

int main() {
    // Create a sample tree
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(-1);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right->right = new Node(6);

    Solution sol;
    int k = 5;
    int result = sol.sumK(root, k);
    cout << "Number of paths with sum " << k << ": " << result << endl;

    // Clean up
    // Delete nodes to avoid memory leak (not necessary in short-lived programs, but good practice)
    delete root->right->right->right;
    delete root->right->left->right;
    delete root->right->left->left;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
