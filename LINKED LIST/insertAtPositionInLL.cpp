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

void insertAtPosition(node* &head, int pos, int val){
    if(pos==1){
        insertAtHead(head,val);
        return;
    }
    node* temp = head;
    int count=1;
    while(count<pos-1){
        temp=temp->next;count++;
    }
    if(temp->next==NULL){
        insertAtTail(head,val);
    }
    //creating node for val
    node* n = new node(val);
    n->next=temp->next;
    temp->next=n;
}

int main(){
    node* head = NULL;
    insertAtTail(head,2);
    insertAtTail(head,7);
    insertAtTail(head,4);
    insertAtTail(head,8);
    insertAtTail(head,10);
    insertAtHead(head,1);
    display(head);
    insertAtPosition(head,3,100);
    display(head);
    return 0;
}