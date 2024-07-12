//Root to leaf path sum

#include <iostream>
using namespace std;

// Definition for a binary tree node
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(Node* root, int target) {
        if (root == NULL) {
            return false;
        }
        
        // Subtract the value of the current node from the target sum
        target -= root->val;
        
        // Check if we have reached a leaf node and the target sum is zero
        if (root->left == NULL && root->right == NULL) {
            return target == 0;
        }
        
        // Recursively check the left and right subtrees
        return hasPathSum(root->left, target) || hasPathSum(root->right, target);
    }
};

// Helper function to build the tree for testing purposes
Node* buildTree(const vector<int>& nodes) {
    if (nodes.empty()) return NULL;
    
    Node* root = new Node(nodes[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (i < nodes.size()) {
        Node* current = q.front();
        q.pop();
        
        if (i < nodes.size() && nodes[i] != -1) {
            current->left = new Node(nodes[i]);
            q.push(current->left);
        }
        i++;
        
        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new Node(nodes[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

int main() {
    Solution sol;
    
    // Example usage:
    // Building the tree: 1 / \ 2 3
    vector<int> treeNodes = {1, 2, 3};
    Node* tree = buildTree(treeNodes);
    
    // Test cases
    cout << sol.hasPathSum(tree, 2) << endl;  // Output: 0 (false)
    cout << sol.hasPathSum(tree, 4) << endl;  // Output: 1 (true)
    
    return 0;
}
