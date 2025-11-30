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

Node* getKthNode(Node* temp, int k) {
    k -= 1;
    while(temp != nullptr && k>0) {
        k--;
        temp = temp->next;
    }
    return temp;
}

Node* reverseKGroup(Node* head, int k) {
    Node* temp = head;
    Node* nextNode;
    Node* prevNode = nullptr;
    while(temp != nullptr) {
        Node* KthNode = getKthNode(temp, k);
        if(KthNode == nullptr) {
            if(prevNode) prevNode->next = temp;
            break;
        } 
        nextNode = KthNode->next;
        KthNode->next = nullptr;
        reverseLL(temp);
        if(temp == head) {
            head = KthNode;
        }
        else {
            prevNode->next = KthNode;
        }
         prevNode = temp;
         temp = nextNode;
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
    Node* head = new Node(6);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    int k=3;
    cout << "Orignal LL is: " << " ";
    printLL(head);
    cout << endl;
    cout << "K group reversed LL is: " << " ";
    head = reverseKGroup(head, k);
    printLL(head);
    return 0;
}