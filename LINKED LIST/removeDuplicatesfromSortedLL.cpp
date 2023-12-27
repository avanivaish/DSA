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

node* removeDuplicatesSortedLL(node* &head){
    if(head==NULL){return head;}
    node* curr=head;
    while(curr->next!=NULL){
        if(curr->data==curr->next->data){
            node* next = curr->next->next;
            node* toDelete = curr->next;
            delete toDelete;
            curr->next=next;
        }
        else{
            curr=curr->next;
        }
    }
    return head;
}

int main(){
    node* head=NULL;
    int arr[]={1,1,3,4,5,5,8,8}; //1,3,4,5,8 - OUTPUT
    for(int i=0;i<8;i++){
        insertAtTail(head,arr[i]);
    }
    display(head);
    node* newHead = removeDuplicatesSortedLL(head);
    display(newHead);
    return 0;
}