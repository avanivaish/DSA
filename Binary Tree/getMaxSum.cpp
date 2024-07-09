//Maximum sum of Non-adjacent nodes

#include <iostream>
#include <algorithm>
#include <utility>

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

class Solution {
public:
    pair<int,int> solve(Node* root) {
        if (root == NULL) {
            return make_pair(0, 0);
        }
        
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        
        pair<int,int> res;
        
        res.first = root->data + left.second + right.second;
        res.second = max(left.first, left.second) + max(right.first, right.second);
        
        return res;
    }
    
    // Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) {
        pair<int,int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};

int main() {
    // Constructing a binary tree
    Node* root = new Node(10);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);

    Solution sol;
    cout << "Maximum sum of non-adjacent nodes: " << sol.getMaxSum(root) << endl;
    
    // Clean up the allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;
    
    return 0;
}
