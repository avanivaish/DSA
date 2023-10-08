//Reverse linked list
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

void insertAtTail(node* &head,int val){
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
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

void reverseLinkedList(node* &head){
    node* prev = NULL;
    node* curr = head;
    node* nextptr;

    while(curr!=NULL){
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
    }
    head=prev;
}



int main(){
    node* head = NULL;
    insertAtTail(head,17);
    insertAtTail(head,11);
    insertAtTail(head,12);
    insertAtTail(head,13);
    insertAtTail(head,14);
    insertAtTail(head,15);
    insertAtTail(head,16);
    insertAtTail(head,18);
    display(head);
    reverseLinkedList(head);
    display(head);
    return 0;
}