#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

int maxPathSumUtil(Node* root, int &ans) {
    if (root == NULL) return 0;
    
    int left = maxPathSumUtil(root->left, ans);
    int right = maxPathSumUtil(root->right, ans);
    
    int nodeMax = max(max(root->val, root->val + left + right), max(root->val + left, root->val + right));
    ans = max(ans, nodeMax);
    
    int singlePathSum = max(root->val, max(root->val + left, root->val + right));
    return singlePathSum;
}

int maxPathSum(Node* root) {
    int ans = INT_MIN;
    maxPathSumUtil(root, ans);
    return ans;
}

int main() {
    // Create a sample binary tree:
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);
    
    // Calculate the maximum path sum
    int result = maxPathSum(root);
    cout << "Maximum path sum is: " << result << endl;
    
    return 0;
}
