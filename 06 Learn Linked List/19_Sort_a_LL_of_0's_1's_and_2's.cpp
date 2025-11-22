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

Node* sortLL(Node* head) {
    if(head == nullptr || head->next == nullptr) return head;
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneTail = oneHead;
    Node* twoTail = twoHead;
    Node* temp = head;
    while(temp != nullptr) {
        if(temp->data == 0){
            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if(temp->data == 1){
            oneTail->next = temp;
            oneTail = temp;
        }
        temp = temp->next;
    }
    oneTail->next = twoHead->next;
    zeroTail->next = oneHead->next;
    twoTail->next = nullptr;
    Node* sortedHead = zeroHead->next;
    free(zeroHead);
    free(oneHead);
    free(twoHead);

    return sortedHead;
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
    cout << "Orignal Linked List is: " << " ";
    printLL(head);
    cout << endl;
    head = sortLL(head);
    cout << "Sorted Linked List is: " << " "; 
    printLL(head);
    return 0;
}