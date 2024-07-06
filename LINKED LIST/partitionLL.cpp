#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next=NULL;
    }
};

void insertAtTail(node* &head, node* &tail, int val){
    node* n = new node(val);
    if(head==NULL){
        head=n;
        tail=n;
        return;
    }
    node* temp =  head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    tail=n;
}

void display(node* head){
    node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}


node* partitionLL(node* head, int x){
    node* list1Head = new node(0);
    node* list2Head = new node(0);
    node* l1 = list1Head;
    node* l2 = list2Head;
    node* temp = head;
    while(temp){
        if(temp->data < x){
            l1->next = temp;
            l1=temp;
        }else{
            l2->next = temp;
            l2=temp;
        }
        temp = temp->next;
    }
    l1->next = list2Head->next;
    l2->next = NULL;
    return list1Head->next;
}


int main(){
    node* head = NULL;
    node* tail = NULL;
    int arr[]={1,4,3,2,5,2};
    int x = 3;
    for(int i=0;i<6;i++){
        insertAtTail(head,tail,arr[i]);
    }
    display(head);
    node* newHead = partitionLL(head,x);
    display(newHead);
    return 0;
}