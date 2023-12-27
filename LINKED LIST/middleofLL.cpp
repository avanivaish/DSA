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

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next=head;
    head=n;
}

void insertAtTail(node* &head, int val){
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }

    node* n = new node(val);
    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void display(node* head){
    if(head==NULL){
        return;
    }
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

node* middleOfLinkedList(node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* fast = head->next;
    node* slow = head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
    }
    return slow;
}


int main(){
    node* head = NULL;
    node* head1 = NULL;
    int arr[]={1,2,3,4,5,6};
    for(int i=0;i<6;i++){
        insertAtTail(head,arr[i]);
    }
    display(head);
    node* midNode = middleOfLinkedList(head);
    display(midNode);
    cout<<endl;
    int arr1[]={1,2,3,4,5,6,7};
    for(int i=0;i<7;i++){
        insertAtTail(head1,arr1[i]);
    }
    display(head1);
    node* midNode1 = middleOfLinkedList(head1);
    display(midNode1);
    return 0;
}