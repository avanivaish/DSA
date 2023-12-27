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
    if(head==NULL){
        return;
    }
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

node* sortList(node* &head){
    if (head == NULL || head -> next == NULL){
        return head;
    }
    node* zeroHead = new node(-1);
    node* oneHead = new node(-1);
    node* twoHead = new node(-1);
    node* zeroTail = zeroHead;
    node* oneTail = oneHead;
    node* twoTail = twoHead;

    node* curr = head;
    while(curr!=NULL){
        int data = curr->data;
        if(data==0){
            zeroTail->next=curr;
            zeroTail=zeroTail->next;
        }
        else if(data==1){
            oneTail->next=curr;
            oneTail=oneTail->next;
        }
        else if(data==2){
            twoTail->next=curr;
            twoTail=twoTail->next;
        }
        curr=curr->next;
    }

    //MERGE
    if(oneHead->next!=NULL){
        zeroTail->next=oneHead->next;
    }
    else{
        zeroTail->next=twoHead->next;
    }
    oneTail->next=twoHead->next;
    twoTail->next=NULL;

    head = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

int main(){
    node* head = NULL;
    int arr[]={0,0,2,1,0,2,1,0,1}; //output: 0 0 0 0 1 1 1 2 2 
    for(int i=0;i<9;i++){
        insertAtTail(head,arr[i]);
    }
    display(head);
    node* newHead = sortList(head);
    display(newHead);
    return 0;
}