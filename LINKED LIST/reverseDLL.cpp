#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
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
    n->prev = tail;
    tail = n;
}

void display(node* head){
    node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

node* reverseDLL(node* &head){
    node* ptr1 = head;
    node* ptr2 = head->next;

    ptr1->next = NULL;
    ptr1->prev = ptr2;

    while(ptr2){
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    return ptr1;
}

int main(){
    node* head = NULL;
    node* tail = NULL;
    int arr[]={1,2,3,4,5,6,7};
    for(int i=0;i<7;i++){
        insertAtTail(head,tail,arr[i]);
    }
    display(head);
    node* rev = reverseDLL(head);
    display(rev);
    return 0;
}