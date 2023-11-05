//INSERTION AT HEAD,TAIL
//DISPLAY LINKED LIST

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    
    if(head==NULL){
        head=n;
        return;
    }
    
    node* temp = head;

    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void insertAtHead(node* &head,int val){
    node* n = new node(val);
    n->next=head;
    head=n;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

int main(){
    node* head = NULL;
    insertAtTail(head,2);
    insertAtTail(head,7);
    insertAtTail(head,4);
    insertAtTail(head,8);
    insertAtTail(head,10);
    insertAtHead(head,100);
    display(head);
    return 0;
}