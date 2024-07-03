#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        if (!getPath(root, p, path1) || !getPath(root, q, path2)) {
            return NULL;
        }
        int pc;
        for (pc = 0; pc < path1.size() && pc < path2.size(); pc++) {
            if (path1[pc] != path2[pc]) {
                break;
            }
        }
        return path1[pc - 1];
    }

    bool getPath(TreeNode* root, TreeNode* key, vector<TreeNode*>& path) {
        if (root == NULL) return false;
        path.push_back(root);
        if (root == key) return true;
        if (getPath(root->left, key, path) || getPath(root->right, key, path)) return true;
        path.pop_back();
        return false;
    }
};

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left; // Node 5
    TreeNode* q = root->left->right->right; // Node 4

    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    if (lca != NULL) {
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    } else {
        cout << "Lowest Common Ancestor not found" << endl;
    }

    // Clean up the allocated memory
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
