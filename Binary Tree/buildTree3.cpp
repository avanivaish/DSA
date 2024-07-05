#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* buildTree(Node* root){
    cout<<"Enter Data: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    
    if(data == -1) {
        return NULL;
    }
    
    cout<<"Enter Data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    
    cout<<"Enter Data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);
    
    return root;
}
 int main(){
    Node* root = NULL;
    root = buildTree(root);
    return 0;
 }
