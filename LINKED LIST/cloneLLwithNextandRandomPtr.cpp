#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* random;
    Node(int val){
        data=val;
        next=NULL;
        random=NULL;
    }
};

void insertAtTail(Node* &head, Node* &tail, int val){
    Node* n = new Node(val);
    if(head==NULL){
        head=n;
        tail=n;
        return;
    }
    tail->next=n;
    tail=n;
}

void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

Node* copyListApproach1(Node* head){
    //step 1
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    Node* temp = head;
    while(temp!=NULL){
        insertAtTail(cloneHead , cloneTail , temp->data );
        temp=temp->next;
    }
    //step 2
    unordered_map<Node*,Node*> mapping;
    Node* temp2 = cloneHead;
    temp=head;
    while(temp!=NULL){
        mapping[temp]=temp2;
        temp=temp->next;
        temp2=temp2->next;
    }
    //step 3
    temp = head;
    temp2 = cloneHead;
    while(temp!=NULL){
        temp2->random=mapping[temp->random];
        temp=temp->next;
        temp2=temp2->next;
    }
    //step 4
    return cloneHead;
}

Node* copyListApproach2(Node* head){
    //step 1
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    Node* temp = head;
    while(temp!=NULL){
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp=temp->next;
    }
    //step 2
    Node* originalNode = head;
    Node* cloneNode = cloneHead;
    while(originalNode!=NULL && cloneNode!=NULL){
        Node* next = originalNode->next;
        originalNode->next=cloneNode;
        originalNode=next;
        next = cloneNode->next;
        cloneNode->next=originalNode;
        cloneNode=next;
    }
    //step 3
    temp = head;
    while(temp!=NULL){
        if(temp->random!=NULL){
            temp->next->random=temp->random->next;
        }
        temp=temp->next->next;
    }
    //step 4
    originalNode = head;
    cloneNode = cloneHead;
    while(originalNode!=NULL && cloneNode!=NULL){
        originalNode->next = cloneNode->next;
        originalNode=originalNode->next;
        if(originalNode!=NULL){
            cloneNode->next = originalNode->next;
            cloneNode=cloneNode->next;
        }
    }
    //step 5
    return cloneHead;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    int arr[]={1,2,3,4,5,6,7};
    for(int i=0;i<7;i++){
        insertAtTail(head,tail,arr[i]);
    }
    display(head);
    Node* ans = copyListApproach1(head);
    display(ans);
    Node* anss = copyListApproach2(head);
    display(anss);
    return 0;
}

