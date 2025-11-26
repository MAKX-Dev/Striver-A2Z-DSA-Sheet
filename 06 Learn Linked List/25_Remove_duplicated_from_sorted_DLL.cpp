#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node* back;
    public:
    Node(int data1, Node* next1, Node* back1) {
        next = next1;
        data = data1;
        back = back1;
    }
    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* removeDuplicates(Node* head) {
    Node* temp1 = head;
    if(head == nullptr || head->next == nullptr) return head;
    while(temp1 !=nullptr && temp1->next != nullptr) {
        Node* temp2 = temp1->next;
        if(temp1->data == temp2->data) {
            temp1->next = temp2->next;
            if(temp1->next != nullptr) temp1->next->back = temp1;
            free(temp2);
        }
        else {
            temp1 = temp1->next;
        }
    }
    return head;
}

Node* printDLL(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
} 

int main() {
    Node* head=new Node(1);
    head->next=new Node(1);
    head->next->next=new Node(3);
    head->next->next->back=head->next;
    cout << "Orignal List: ";
    printDLL(head);
    cout << endl;
    cout << "Modified DLL is: " << " ";
    head = removeDuplicates(head);
    printDLL(head);
    return 0;
}