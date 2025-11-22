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

Node* reverseLL(Node* head){
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=nullptr){
    Node*front=temp->next;
    temp->next=prev;
    prev=temp;
    temp=front;
    }
    return prev;
}

Node* addOne(Node* head) {
    if(head == nullptr) return nullptr;
    head = reverseLL(head);
    Node* temp = head; 
    int carry = 1;
    while(temp != nullptr) {
        temp->data = temp->data + carry;
        if(temp->data < 10) {
            carry = 0;
            break;
        }
        else{
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }
    if(carry == 1) {
        Node* newNode = new Node(1);
        head = reverseLL(head);
        newNode->next = head;
        return newNode;
    }
    head = reverseLL(head);
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
    head->next = new Node(0);
    head->next->next = new Node(2);
    head->next->next->next = new Node(0);
    head->next->next->next->next = new Node(1);
    cout << "Origanl Linked List is: " << " ";
    printLL(head);
    cout << endl;
    head = addOne(head);
    cout << "After adding one LL is: " << " ";
    return 0;
}