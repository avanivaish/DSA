#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map to store the nodes in vertical and level order
        map<int, map<int, multiset<int>>> nodes;
        // Queue to perform BFS
        queue<pair<TreeNode*, pair<int, int>>> q;
        vector<vector<int>> result;

        if (root == nullptr) return result;
        
        // Start BFS with the root node at horizontal distance 0 and level 0
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            
            TreeNode* node = temp.first;
            int hd = temp.second.first;  // horizontal distance
            int lvl = temp.second.second;  // level
            
            nodes[hd][lvl].insert(node->val);
            
            if (node->left) {
                q.push({node->left, {hd - 1, lvl + 1}});
            }
            if (node->right) {
                q.push({node->right, {hd + 1, lvl + 1}});
            }
        }
        
        // Traverse the map and prepare the result
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            result.push_back(col);
        }
        
        return result;
    }
};

int main() {
    // Creating a binary tree for testing
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> result = sol.verticalTraversal(root);

    // Printing the result
    for (const auto& col : result) {
        for (int val : col) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
