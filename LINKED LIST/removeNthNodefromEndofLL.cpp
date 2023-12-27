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

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void display(node* head){
    if(head==NULL){return;}
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

node* removeNthNodefromEndofLL(node* &head, int n){
    node* start = new node(0);
    start->next=head;
    node* fast = start;
    node* slow = start;
    for(int i=0;i<n;i++){
        fast=fast->next;
    }
    while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
    }

    slow->next = slow->next->next;

    return start->next;
}

int main(){
    node* head=NULL;
    int arr[]={11,12,32,41,55,35,81,28}; //11 12 32 55 35 81 28 
    for(int i=0;i<8;i++){
        insertAtTail(head,arr[i]);
    }
    display(head);
    int n = 5;
    node* newHead = removeNthNodefromEndofLL(head,n);
    display(newHead);
    return 0;
}