#include <iostream>
#include <vector>
#include <map>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    map<string, int> mp;
    string solve(TreeNode* root, vector<TreeNode*>& res) {
        if (!root) return "#";
        string s = solve(root->left, res) + ',' + solve(root->right, res) + ',' + to_string(root->val);
        mp[s]++;
        if (mp[s] == 2) res.push_back(root);
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        solve(root, ans);
        return ans;
    }
};

// Helper function to print the tree nodes
void printTreeNodes(vector<TreeNode*> nodes) {
    for (TreeNode* node : nodes) {
        cout << node->val << " ";
    }
    cout << endl;
}

int main() {
    // Create a test tree:
    //        1
    //       / \
    //      2   3
    //     /   / \
    //    4   2   4
    //       /
    //      4

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(4);
    root->right->right = new TreeNode(4);

    Solution solution;
    vector<TreeNode*> duplicates = solution.findDuplicateSubtrees(root);

    cout << "Duplicate Subtrees Roots: ";
    printTreeNodes(duplicates);

    // Clean up memory (not necessary for this example, but good practice)
    delete root->right->right;
    delete root->right->left->left;
    delete root->right->left;
    delete root->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
