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

    while(temp->next != NULL){
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

void deleteAtHead(node* &head){
    node* todelete = head;
    head=head->next;
    delete todelete;
}

void deleteNode(node* &head, int val){
    //corner case 
    //no element
    if(head==NULL){
        return;
    }
    //only 1 element
    if(head->next==NULL){
        deleteAtHead(head);
        return;
    }
    
    node* temp = head;
    while(temp->next->data != val){
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

int main(){
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,11);
    insertAtTail(head,31);
    insertAtTail(head,51);
    insertAtTail(head,341);
    insertAtTail(head,121);
    display(head);
    deleteAtHead(head);
    display(head); 
    deleteNode(head,31);
    display(head);
    return 0;
}