#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        vector<int> ans;
        ListNode* temp = head;
        
        // Extract values from the linked list and store in a vector
        while (temp != nullptr) {
            ans.push_back(temp->val);
            temp = temp->next;
        }
        
        // Sort the vector
        sort(ans.begin(), ans.end());
        
        // Update the linked list with sorted values
        temp = head;
        int i = 0;
        while (temp != nullptr) {
            temp->val = ans[i];
            i++;
            temp = temp->next;
        }
        
        return head;
    }
};

// Utility function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Example usage
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution solution;
    
    cout << "Original Linked List: ";
    printList(head);
    
    // Sorting the linked list using insertion sort
    ListNode* sortedHead = solution.insertionSortList(head);
    
    cout << "Sorted Linked List: ";
    printList(sortedHead);

    return 0;
}
