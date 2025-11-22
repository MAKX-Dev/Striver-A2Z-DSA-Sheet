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

Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head->next;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeTwoLists(Node* list1, Node* list2) {
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(list1 != nullptr && list2 != nullptr) {
        if(list1->data< list2->data) {
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }
    if(list1) temp->next = list1;
        else temp->next = list2;
    return dummyNode->next;
}

Node* mergeLL(Node* head) {
    if(head == nullptr || head->next == nullptr) return head;
    Node* middle = findMiddle(head);
    Node* leftHead = head;
    Node* rightHead = middle->next;
    middle->next = nullptr;
    leftHead = mergeLL(leftHead);
    rightHead = mergeLL(rightHead);
    return mergeTwoLists(leftHead,rightHead);
}

void printLL(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    Node* head = new Node(4);
    head->next = new Node(3);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(5);
    cout << "Original List: ";
    printLL(head);
    cout << endl;
    head = mergeLL(head);
    cout << "Sorted List:   ";
    printLL(head);
    return 0;
}