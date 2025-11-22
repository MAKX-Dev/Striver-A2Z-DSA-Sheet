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

Node* getIntersectionNode(Node* head1, Node* head2) {
    if(head1 == nullptr || head2 == nullptr) return nullptr;
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1 != temp2) {
        temp1 = temp1->next;
        temp2 = temp2->next;
        if(temp1 == temp2) return temp1;
        if(temp1 == nullptr) temp1 = head2;
        if(temp2 == nullptr) temp2 = head1;
    }
    return temp1;
}

int main() {
    Node* common = new Node(6);
    common->next = new Node(7);

    Node* headA = new Node(1);
    headA->next = new Node(2);
    headA->next->next = new Node(3);
    headA->next->next->next = common;

    Node* headB = new Node(4);
    headB->next = new Node(5);
    headB->next->next = common;
    Node* intersection = getIntersectionNode(headA,headB);
    if(intersection) {
        cout << "Intersection found at node with data: " << intersection->data << endl;
    }
    else {
        cout << "No intersection exists" << endl;
    }
    return 0;
}