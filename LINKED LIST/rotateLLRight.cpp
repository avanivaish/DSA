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
    if (head == NULL) {
        head = n;
        tail = n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    tail = n;
}

void display(node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head=head->next;
    }cout<<endl;
}


node* rotateLL(node* &head, int k){
    if(head==NULL || k==0 ){
        return head;
    }
    node* temp = head;
    int n = 0;
    while(temp->next!=NULL){
        n++;
        temp=temp->next;
    }
    temp->next=head;
    temp=head;
    k=k%n;
    int jump = n-k;
    while(jump){
        temp=temp->next;
        jump--;
    }
    head = temp->next;
    temp->next = NULL;
    return head;
}

int main(){
    node *head=NULL, *tail=NULL;
    int arr[]={1,2,3,4,5,6,7};
    int k =  2;
    for(int i=0;i<7;i++){
        insertAtTail(head,tail,arr[i]);
    }
    display(head);
    node* rotate = rotateLL(head,k);
    display(rotate);
    return 0;
}