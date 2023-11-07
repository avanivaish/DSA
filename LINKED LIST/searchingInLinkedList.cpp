//SEARCHING
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
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

bool searchLinkedList(node* head, int key){
    node* temp = head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
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
    cout<<searchLinkedList(head,8)<<endl;
    cout<<searchLinkedList(head,51)<<endl;
    return 0;
}