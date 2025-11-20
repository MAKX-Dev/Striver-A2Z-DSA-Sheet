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

Node* oddEvenList(Node* head) {
    if(head == nullptr || head->next == nullptr) return head;
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = head->next;
    while(even != nullptr && even->next != nullptr) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

void printList(Node* head) {
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
    cout << "Orignal Linked List is: " << " ";
    printList(head);
    cout<< endl;
    oddEvenList(head);
    cout << "Segregated odd and even nodes in LL: " << " ";
    printList(head);
    return 0;
}