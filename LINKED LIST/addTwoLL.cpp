#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node* &head, Node* &tail, int val){
    Node* n = new Node(val);
    if(head==NULL){
        head = n;
        tail = n;
        return;
    }
    tail->next = n;
    tail = n;
}

void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

Node* reverse(Node* &head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* add(Node* first, Node* second){
    int carry=0;
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    while (first != nullptr || second !=nullptr || carry!=0) {
        int val1=0, val2=0;
        if(first!=NULL){val1=first->data;}
        if(second!=NULL){val2=second->data;}
        int sum = carry+val1+val2;
        int digit = sum%10;
        insertAtTail(ansHead,ansTail,digit);
        carry = sum/10;

        if(first!=NULL){first=first->next;}
        if(second!=NULL){second=second->next;}
    }
    return ansHead;
}

int main(){
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;
    int arr1[]={4,5};
    int arr2[]={3,4,5};
    //output: 3 9 0
    for(int i=0;i<2;i++){
        insertAtTail(head1,tail1,arr1[i]);
    }
    for(int i=0;i<3;i++){
        insertAtTail(head2,tail2,arr2[i]);
    }
    display(head1);
    display(head2);

    Node* first = reverse(head1);
    Node* second = reverse(head2);
    Node* ans = add(first, second);
    ans = reverse(ans);
    display(ans);
    return 0;
}