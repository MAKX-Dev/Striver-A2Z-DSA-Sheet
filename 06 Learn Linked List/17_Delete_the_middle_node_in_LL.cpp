#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    public:
    Node(int data1, Node* next1) {
        next = next1;
        data = data1;
    }
    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* deleteMiddle(Node* head) {
    if(head == nullptr || head->next == nullptr) return head;
    Node* slow = head;
    Node* fast = head;
    Node* prev = head;
    while(fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    free(slow);
    return head;
}

void printLL(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    printLL(head);
    cout << endl;
    head = deleteMiddle(head);
    printLL(head);
    return 0;
}