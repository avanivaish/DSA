//merging two LL
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

void insertAtHead(node* &head,int val){
    node* n = new node(val);
    n->next=head;
    head=n;
}

void insertAtTail(node* &head,int val){
    node* n = new node(val);
    if(head==NULL){
        insertAtHead(head,val);
        return ;
    }

    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

node* merge(node* &head1, node* &head2){
    node* p1=head1;
    node* p2=head2;
    node* dummyhead = new node(-1);
    node* p3=dummyhead;

    while(p1!=NULL && p2!=NULL){
        if(p1->data<p2->data){
            p3->next=p1;
            p1=p1->next;
        }
        else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }
    while(p1!=NULL){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
    while(p2!=NULL){
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }

    return dummyhead->next;
}


int main(){
    node* head1=NULL;
    node* head2=NULL;
    int arr1[]={1,3,4,5,7,9};
    int arr2[]={2,6,10};
    for(int i=0;i<6;i++){
        insertAtTail(head1,arr1[i]);
    }
    for(int i=0;i<3;i++){
        insertAtTail(head2,arr2[i]);
    }
    display(head1);
    display(head2);
    node* newhead = merge(head1,head2);
    display(newhead);
    return 0;
}