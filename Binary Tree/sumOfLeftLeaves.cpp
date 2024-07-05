#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void inorderTraversal(TreeNode* root, int &sum) {
        if (root == NULL) return;
        
        // Traverse the left subtree
        inorderTraversal(root->left, sum);
        
        // Check if the left child is a leaf
        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
            sum += root->left->val;
        }
        
        // Traverse the right subtree
        inorderTraversal(root->right, sum);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        inorderTraversal(root, sum);
        return sum;
    }
};

int main() {
    // Create a binary tree for testing
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    // Create an instance of the Solution class
    Solution solution;
    
    // Calculate the sum of left leaves
    int sum = solution.sumOfLeftLeaves(root);
    
    // Print the result
    std::cout << "Sum of left leaves: " << sum << std::endl;
    
    // Clean up dynamically allocated memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
