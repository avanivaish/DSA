#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root) {
        map<int, map<int, vector<int>>> nodes;
        queue<pair<Node*, pair<int, int>>> q;
        vector<int> ans;

        if (root == NULL) return ans;
        q.push(make_pair(root, make_pair(0, 0)));
        while (!q.empty()) {
            pair<Node*, pair<int, int>> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].push_back(frontNode->data);
            if (frontNode->left != NULL) {
                q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
            }
            if (frontNode->right != NULL) {
                q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
            }
        }
        for (auto i : nodes) {
            for (auto j : i.second) {
                for (auto k : j.second) {
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};

int main() {
    // Creating a binary tree for testing
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<int> result = sol.verticalOrder(root);

    // Printing the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
