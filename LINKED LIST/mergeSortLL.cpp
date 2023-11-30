#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtTail(node* &head, node* &tail, int val){
    node* n = new node(val);
    if(!head){
        head=n;
        tail=n;
        return;
    }
    tail->next=n;
    tail=n;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

node* getMiddle(node* head){
    node* fast = head->next;
    node* slow = head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

node* merge(node* left, node* right){
    if(left==NULL){return right;}
    if(right==NULL){return left;}
    node* dummy = new node(0);
    node* temp = dummy;
    while(left!=NULL && right!=NULL){
        if(left->data < right->data){
            temp->next=left;
            temp=left;
            left=left->next;
        }else{
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }
    while(left!=NULL){
        temp->next=left;
        temp=left;
        left=left->next;
    }
    while(right!=NULL){
        temp->next=right;
        temp=right;
        right=right->next;
    }
    return dummy->next;
}

node* mergeSort(node* head){
    if (head == NULL || head -> next==NULL){
        return head;
    }
    node* mid = getMiddle(head);
    node* left = head;
    node* right = mid->next;
    mid->next=NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    node* ans = merge(left,right);
    return ans;
}

int main(){
    node* head = NULL;
    node* tail = NULL;
    int arr[]={7,4,2,1,8,3,13,11};
    for(int i=0;i<8;i++){
        insertAtTail(head,tail,arr[i]);
    }
    display(head);
    
    //merge sort
    node* newHead = mergeSort(head);
    display(newHead);
    return 0;
}