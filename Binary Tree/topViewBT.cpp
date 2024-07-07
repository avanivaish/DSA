#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Function to return a list of nodes visible from the top view 
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        vector<int> ans;
        if (root == NULL) return ans;

        map<int, int> topNode;
        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 0));

        while (!q.empty()) {
            pair<Node*, int> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second;

            if (topNode.find(hd) == topNode.end()) {
                topNode[hd] = frontNode->data;
            }
            if (frontNode->left) {
                q.push(make_pair(frontNode->left, hd - 1));
            }
            if (frontNode->right) {
                q.push(make_pair(frontNode->right, hd + 1));
            }
        }
        for (auto i : topNode) {
            ans.push_back(i.second);
        }
        return ans;
    }
};

int main() {
    // Example tree construction
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<int> result = sol.topView(root);

    cout << "Top view of the binary tree is: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory (deleting nodes)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
