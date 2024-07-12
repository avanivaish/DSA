//CONSTRUCT TREE FROM INORDER AND PREODER TRAVERSAL

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    int findPosition(int in[], int element, int inorderStart, int inorderEnd) {
        for (int i = inorderStart; i <= inorderEnd; i++) {
            if (in[i] == element) {
                return i;
            }
        }
        return -1;
    }

    Node* solve(int in[], int pre[], int& index, int inorderStart, int inorderEnd, int n) {
        if (index >= n || inorderStart > inorderEnd) return NULL;
        int element = pre[index++];
        Node* root = new Node(element);
        int position = findPosition(in, element, inorderStart, inorderEnd);
        
        root->left = solve(in, pre, index, inorderStart, position - 1, n);
        root->right = solve(in, pre, index, position + 1, inorderEnd, n);
        
        return root;
    }
    
    Node* buildTree(int in[], int pre[], int n) {
        int preorderIndex = 0;
        Node* ans = solve(in, pre, preorderIndex, 0, n - 1, n);
        return ans;
    }
};

// Helper function to print the tree in postorder
void printPostorder(Node* node) {
    if (node == NULL) return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

int main() {
    int n = 7;
    int in[] = {1, 3, 7, 11, 3, 17, 18};
    int pre[] = {7, 3, 11, 1, 17, 3, 18};

    Solution solution;
    Node* root = solution.buildTree(in, pre, n);

    cout << "Postorder traversal of the constructed tree is: ";
    printPostorder(root);
    cout << endl;

    return 0;
}
