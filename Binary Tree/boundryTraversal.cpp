#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Solution class as provided
class Solution {
public:
    void traverseLeft(Node* root, vector<int> &ans){
        if(root==NULL) return;
        if(root->left == NULL && root->right == NULL){
            return;
        }
        ans.push_back(root->data);
        if(root->left != NULL){
            traverseLeft(root->left, ans);
        }else{
            traverseLeft(root->right, ans);
        }
    }
    
    void traverseLeaf(Node* root, vector<int> &ans){
        if(root==NULL) return;
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
        
    }
    
    void traverseRight(Node* root, vector<int> &ans){
        if(root==NULL) return;
        if(root->left == NULL && root->right == NULL) return;
        
        if(root->right) traverseRight(root->right, ans);
        else traverseRight(root->left, ans);
        
        ans.push_back(root->data);
    }
    
    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->data);
        traverseLeft(root->left, ans);
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
        traverseRight(root->right, ans);
        
        return ans;
    }
};

int main() {
    // Creating a sample binary tree
    Node* root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right = new Node(22);
    root->right->right = new Node(25);
    
    Solution sol;
    vector<int> boundaryTraversal = sol.boundary(root);
    
    // Print the boundary traversal
    for(int val : boundaryTraversal) {
        cout << val << " ";
    }
    cout << endl;
    
    // Free allocated memory (optional but good practice)
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;
    
    return 0;
}
