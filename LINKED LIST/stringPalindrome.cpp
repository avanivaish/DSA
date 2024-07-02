#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string x) : data(x), next(nullptr) {}
};

class Solution {
public:
    bool compute(Node* head) {
        string s = "";
        Node* a = head;
        while (a != nullptr) {
            s.append(a->data);
            a = a->next;
        }
        for (int i = 0; i < s.length() / 2; i++) {
            if (s[i] != s[s.length() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    // Example linked list: ["a", "bc", "d", "dcb", "a"]
    Node* head = new Node("a");
    head->next = new Node("bc");
    head->next->next = new Node("d");
    head->next->next->next = new Node("dcb");
    head->next->next->next->next = new Node("a");

    Solution sol;
    bool result = sol.compute(head);

    if (result) {
        cout << "The combined string is a palindrome." << endl;
    } else {
        cout << "The combined string is not a palindrome." << endl;
    }

    // Free allocated memory (not strictly necessary in this short example, but good practice)
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
