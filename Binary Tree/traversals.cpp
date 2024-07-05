#include<iostream>
#include<queue>

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
void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL); //seperator for level seperation 
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
            q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        
    }
}
void inorderTraversal(Node* root){
    if(root==NULL) return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
void preorderTraaversal(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorderTraaversal(root->left);
    preorderTraaversal(root->right);
}
void postorderTraversal(Node* root){
    if(root==NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}

 int main(){
    Node* root = NULL;
    //creating a tree 
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    //level order traversal 
    cout<<"Level Order Traversal: "<<endl;
    levelOrderTraversal(root);
    cout<<"INORDER TRAVERSAL: "<<endl;
    inorderTraversal(root);
    cout<<endl;
    cout<<"PREORDER TRAVERSAL: "<<endl;
    preorderTraaversal(root);
    cout<<endl;
    cout<<"POSTORDER TRAVERSAL: "<<endl;
    postorderTraversal(root);
    return 0;
 }
