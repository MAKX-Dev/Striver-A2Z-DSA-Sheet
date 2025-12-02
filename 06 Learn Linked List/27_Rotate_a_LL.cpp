#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* back;
    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};

Node* findNthNode(Node* head, int k) {
    Node* temp = head;
    int cnt = 0;
    while(temp != nullptr) {
    if(cnt == k) return temp;
    cnt++;
    temp = temp->next;
    }
    return temp;
}

Node* rotateLL(Node* head, int k) {
    if(head == nullptr || k == 0) return head;
    int len = 1;
    Node* tail = head;
    while(tail->next != nullptr) {
        len++;
        tail = tail->next;
    }
    if(k % len == 0) return head;
    k = k % len;
    tail->next = head;
    Node* newLastNode = findNthNode(head, len - k - 1);
    head = newLastNode->next;
    newLastNode->next = nullptr;
    return head;
}

void print(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
     }
}

int main() {
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    int  k = 4;
    cout<<"Orignal List is: ";
    print(head);
    cout << endl;
    cout << "Linked List after rotating by k places: " << " ";
    head = rotateLL(head, k);
    print(head);
    return 0;
}