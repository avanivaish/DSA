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

void insertAtTail(node* &head, node* &tail, int val){
    node* n = new node(val);
    if(head==NULL){
        head = n;
        tail = n;
        return;
    }
    tail->next = n;
    tail = n;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

node* deleteAtMiddle(node* &head){
    if (head == nullptr || head -> next == nullptr){
        delete head;
        return NULL;
    }
    node* fast = head;
    node* slow = head;
    node* prev = NULL;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    prev->next=slow->next;
    delete slow;
    return head;
}

int main(){
    node* head = NULL;
    node* tail = NULL;
    int arr[]={1,2,3,4,5,6};
    for(int i=0;i<6;i++){
        insertAtTail(head,tail,arr[i]);
    }
    display(head);
    node* newHead = deleteAtMiddle(head);
    display(newHead);

    node* head1 = NULL;
    node* tail1 = NULL;
    int arr1[]={1,2,3,4,5};
    for(int i=0;i<5;i++){
        insertAtTail(head1,tail1,arr1[i]);
    }
    display(head1);
    node* newHead1 = deleteAtMiddle(head1);
    display(newHead1);
    return 0;
}