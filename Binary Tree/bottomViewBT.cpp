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
    vector<int> bottomView(Node* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        map<int, int> topNode;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            pair<Node*, int> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            topNode[hd] = frontNode->data;
            if (frontNode->left) {
                q.push({frontNode->left, hd - 1});
            }
            if (frontNode->right) {
                q.push({frontNode->right, hd + 1});
            }
        }
        for (auto i: topNode) {
            ans.push_back(i.second);
        }
        return ans;
    }
};

Node* createTree() {
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    return root;
}

int main() {
    Node* root = createTree();
    Solution sol;
    vector<int> result = sol.bottomView(root);
    
    cout << "Bottom view of the binary tree is: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
