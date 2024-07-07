#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

void solve(Node* root, vector<int>& ans, int level) {
    if (root == NULL) return;
    if (level == ans.size()) ans.push_back(root->data);
    
    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}

vector<int> leftView(Node* root) {
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

Node* createTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}

int main() {
    Node* root = createTree();
    vector<int> result = leftView(root);
    
    cout << "Left view of the binary tree is: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
