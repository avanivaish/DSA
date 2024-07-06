//MAXIMUM DEPTH OF BT
#include<iostream>
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

int maxDepthBT(Node* root){
    if(root == NULL) return 0;
    int left = maxDepthBT(root->left);
    int right = maxDepthBT(root->right);
    return max(left,right)+1;
}

int main(){
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    
    int maxDepth = maxDepthBT(root);
    cout<<"Maximum Depth of BT is: "<<maxDepth<<endl;
}
