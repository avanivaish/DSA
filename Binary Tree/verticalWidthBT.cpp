#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    // Function to find the vertical width of a Binary Tree.
    int verticalWidth(Node* root) {
        if (root == nullptr) {
            return 0;
        }

        // Use an unordered set to store unique horizontal distances.
        unordered_set<int> hdSet;

        // Queue to store pairs of node and its horizontal distance.
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            Node* node = front.first;
            int hd = front.second;

            // Insert the horizontal distance into the set.
            hdSet.insert(hd);

            // Enqueue left child with horizontal distance decremented by 1.
            if (node->left != nullptr) {
                q.push({node->left, hd - 1});
            }

            // Enqueue right child with horizontal distance incremented by 1.
            if (node->right != nullptr) {
                q.push({node->right, hd + 1});
            }
        }

        // The size of the set gives the vertical width.
        return hdSet.size();
    }
};

int main() {
    // Constructing the following binary tree
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;
    int width = solution.verticalWidth(root);
    cout << "The vertical width of the binary tree is: " << width << endl;

    // Clean up memory (optional but good practice)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
