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

int helper(Node* temp) {
    if(temp == nullptr) {
        return 1;
    }
    int carry = helper(temp->next);
    temp->data = temp->data + carry;
    if(temp->data < 10) {
        return 0;
    }
    temp->data = 0;
    return 1;
}

Node* addOneToLL(Node* head) {
    int carry = helper(head);
    if(carry == 1){
        Node* newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }
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
    Node* head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);
    head->next->next->next = new Node(9);
    head->next->next->next->next = new Node(9);
    cout << "Orignal Linked List is: " << " ";
    printLL(head);
    cout << endl;
    cout << "Linked List after adding one in digit is: " << " ";
    head = addOneToLL(head);
    printLL(head);
    return 0;
}

// TC O(N)
// SC O(N) because of recursive stack space