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

Node* delNthNode(Node* head, int n) {
    Node* fast = head;
    for(int i = 0 ; i < n ; i++) fast = fast->next;
    Node* slow = head;
    while(fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }
    Node* delNode = slow->next;
    slow->next = slow->next->next;
    free(delNode);
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
    int n=2;
    cout << "Orignal Linked List is: " << " ";
    printLL(head);
    cout<<endl;
    cout << "Lineked List after removing nth node from end: " << " "; 
    delNthNode(head,n);
    printLL(head);
    return 0;
}