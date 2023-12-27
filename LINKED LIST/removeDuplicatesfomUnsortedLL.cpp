#include<iostream>
#include<unordered_set>
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

node* removeDuplicatesfromUnsortedLL(node* &head){
    unordered_set<int> hs;
    node* curr = head;
    node* prev = NULL;
    while(curr!=NULL){
        int val = curr->data;
        if(hs.find(val)!=hs.end()){
            prev->next=curr->next;
            delete curr;
        }
        else{
            hs.insert(val);
            prev=curr;
        }
        curr=prev->next;
    }
    return head;
}


int main(){
    node* head = NULL;
    int arr[]={5,5,3,2,1,23,23,7,1};  //OUTPUT: 5 3 2 1 23 7 
    for(int i=0;i<9;i++){
        insertAtTail(head,arr[i]);
    }
    display(head);
    node* newHead = removeDuplicatesfromUnsortedLL(head);
    display(newHead);
    return 0;
}