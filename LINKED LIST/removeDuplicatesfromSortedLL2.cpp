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

node* removeDuplicatesfromSortedLLNew(node* &head){
    if(head==NULL){return head;}
    node* p = new node(0);
    p->next=head;
    node* curr = p;

    while(curr->next!=NULL && curr->next->next!=NULL){
        if(curr->next->data==curr->next->next->data){
            int val = curr->next->data;
            while(curr->next!=NULL && val==curr->next->data){
                curr->next=curr->next->next;
            }
        }
        else{
            curr=curr->next;
        }
    }
    return p->next;

}


int main(){
    node* head=NULL;
    int arr[]={1,1,3,4,5,5,8,8,10}; //3 4 10 - OUTPUT
    for(int i=0;i<9;i++){
        insertAtTail(head,arr[i]);
    }
    display(head);
    node* newHead = removeDuplicatesfromSortedLLNew(head);
    display(newHead);
    return 0;
}