#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    public:
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* addTwoNumbers(Node* head1, Node* head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;
    int carry = 0;
    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;
    while(temp1 != nullptr || temp2 != nullptr) {
        int sum = carry;
        if(temp1) sum = sum + temp1->data;
        if(temp2) sum = sum + temp2->data;
        Node* newNode = new Node(sum % 10);
        carry = sum / 10;
        curr->next = newNode;
        curr = curr->next;
        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;
    }
    if(carry) {
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummyNode->next;
}

void printLL(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    Node* headA = new Node(1);
    headA->next = new Node(0);
    headA->next->next = new Node(2);
    headA->next->next->next = new Node(0);
    headA->next->next->next->next = new Node(1);
    cout << "Orignal Linked List A is: " << " ";
    printLL(headA);
    cout << endl;
    Node* headB = new Node(1);
    headB->next = new Node(2);
    headB->next->next = new Node(7);
    headB->next->next->next = new Node(8);
    headB->next->next->next->next = new Node(1);
    cout << "Orignal Linked List B is: " << " ";
    printLL(headB);
    cout << endl;
    cout << "Sum as Linked List is: " << " ";
    Node* head = addTwoNumbers(headA, headB);
    printLL(head);
    return 0;
}

// TC O(max(M,N));
// SC O(max(M,N));