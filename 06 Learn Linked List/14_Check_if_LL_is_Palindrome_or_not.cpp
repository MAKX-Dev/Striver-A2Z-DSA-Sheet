#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    public:
    Node(int data1 ,Node* next1) {
        data = data1;
        next = next1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* reverseLL(Node* head) {
    if(head == nullptr || head->next == nullptr) return head;
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){
    Node*front = temp->next;
    temp->next = prev;
    prev = temp;
    temp = front;
    }
    return prev;
}

bool isPalindrome(Node* head) {
    if(head == nullptr || head->next == nullptr) return true;
    Node* slow = head;
    Node* fast = head;
    while(fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newHead = reverseLL(slow->next);
    Node* first = head;
    Node* second = newHead;
    while(second != nullptr) {
        if(first->data != second->data) {
            reverseLL(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLL(newHead);
    return true;
}

int main() {
    Node* head = new Node(3);
    head->next = new Node(7);
    head->next->next = new Node(5);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(3);

    if(isPalindrome(head)) {
        cout << "TRUE" << endl;
    }
    else{
        cout << "FALSE" << endl;
    }
    return 0;
}