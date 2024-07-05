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

void inserAtTail(node* &head, node* &tail, int val){
    node* n = new node(val);
    if(head==NULL){
        head=n;
        tail=n;
        return;
    }
    tail->next=n;
    tail=n;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

node* reverseLL(node* &head){
    node* curr = head;
    node* prev = NULL;
    node* next = NULL;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void reverseAlternateNodesAddtoEnd(node* &head){
    if(head==NULL || head->next==NULL){return;}
    node* temp1 = head;
    node* temp2 = head->next;
    node* res = temp2;
    while(temp2!=NULL && temp2->next!=NULL){
        temp1->next = temp2->next;
        temp1=temp1->next;
        temp2->next=temp1->next;
        temp2=temp2->next;
    }
    res = reverseLL(res);
    temp1->next = res;
}

int main(){
    node* head = NULL;
    node* tail = NULL;
    int arr[]={10,4,9,1,3,5,9,4};
    for(int i=0;i<8;i++){
        inserAtTail(head,tail,arr[i]);
    }
    display(head);
    reverseAlternateNodesAddtoEnd(head);
    display(head);
    return 0;
}