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
void buildFromLevelOrdertraversal(Node* &root){
    queue<Node*> q;
    cout<<"Enter data of root:"<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<"Enter data of left node of: "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }
        cout<<"Enter data of right node of: "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData != -1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
        
    }
}


 int main(){
    Node* root = NULL;
    //creating a tree 
    //root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    //creating a tree using level order traversal 
    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelOrdertraversal(root);
    //level order traversal 
    cout<<"Level Order Traversal: "<<endl;
    levelOrderTraversal(root);
    
    return 0;
 }
