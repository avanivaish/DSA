#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    if(head==NULL){
        head=n;
        head->next=head;
        head->prev=head;
    }
    else{
        node* tail = head->prev;
        n->next=head;
        n->prev=tail;
        tail->next=n;
        head->prev=n;
        head=n;
    }
}

void insertAtTail(node* &head, int val){
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    node* n = new node(val);
    node* tail = head->prev;
    n->next=tail->next;
    n->prev=tail;
    tail->next=n;
    head->prev=n;
}

void display(node* head){
    if(head==NULL){
        return;
    }
    node* current = head;
    do{
        cout<<current->data<<" ";
        current=current->next;
    }while(current!=head);
    cout<<endl;
}

void deleteAtHead(node* &head){
    if(head==NULL){
        return;
    }
    if(head->next==head){
        delete head;
        head=NULL;
    }
    else{
        node* n = head->next;
        node* tail = head->prev;
        n->prev=tail;
        tail->next=n;
        delete head;
        head=n;
    }
}

void deletion(node* &head, int pos){
    if(head==NULL){
        return;
    }
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    node* current=head;
    node* prevNode=NULL;
    int count=1;
    do{
        if(count==pos){
            if(current==head){
                node* tail = head->prev;
                head = current->next;
                tail->next=head;
            }
            else{
                prevNode->next=current->next;
                current->next->prev=prevNode;
            }
            delete current;
            return;
        }
        prevNode=current;
        current=current->next;
        count++;
    }while(current!=head);
}

int main(){
    node* head = NULL;
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtHead(head,5);
    insertAtHead(head,6);
    display(head);
    insertAtTail(head,7);
    insertAtTail(head,8);
    display(head);
    deletion(head,4);
    display(head);
    deletion(head,1);
    display(head);
    return 0;
}