#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to insert a new node at the end
void appendNode(Node*& head, int data) {
    if (head == NULL) {
        head = new Node(data);
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new Node(data);
    }
}

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        Node* curr = head;
        Node* temp = new Node(-1);
        Node* head1 = temp;
        while (curr != NULL) {
            if (curr->next == NULL) {
                temp->next = curr;
                temp = temp->next;
                break;
            }
            if (curr->data == curr->next->data) {
                while (curr->next && curr->data == curr->next->data) {
                    curr = curr->next;
                }
                curr = curr->next;
                continue;
            }
            temp->next = curr;
            temp = temp->next;
            curr = curr->next;
        }
        temp->next = NULL;
        return head1->next;
    }
};

int main() {
    Node* head = NULL;
    appendNode(head, 1);
    appendNode(head, 2);
    appendNode(head, 2);
    appendNode(head, 3);
    appendNode(head, 4);
    appendNode(head, 4);
    appendNode(head, 5);

    cout << "Original list: ";
    printList(head);

    Solution solution;
    Node* result = solution.removeAllDuplicates(head);

    cout << "Modified list: ";
    printList(result);

    return 0;
}
