#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node *next;
    Node *random;
    Node()
    {
        val = 0;
        next = NULL;
        random = NULL;
    }
    Node(int data1)
    {
        val = data1;
        next = NULL;
        random = NULL;
    }
    Node(int data1, Node *next1, Node* r)
    {
        val = data1;
        next = next1;
        random = r;
    }
};

void insertCopyInBetween(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        Node* copyNode = new Node(temp->val);
        copyNode->next = temp->next;
        temp->next = copyNode;
        temp = temp->next->next;
    }
}

void connectRandomPointer(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        Node* copyNode = temp->next;
        if(temp->random->next == nullptr) copyNode->random = nullptr;
        copyNode->random = temp->random->next;
        temp = temp->next->next;
    }
}
Node* deepCopyList(Node* head) {
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;
    Node* temp = head;
    while(temp != nullptr) {
        res->next = temp->next;
        temp->next = temp->next->next;
        res = res->next;
        temp = temp->next;
    }
    return dummyNode->next;
}

Node* copyRandomList(Node* head) {
    insertCopyInBetween(head);
    connectRandomPointer(head);
    return deepCopyList(head);
}

void printClonedLinkedList(Node *head) {
    while (head != nullptr) {
        cout << "Data: " << head->val;
        if (head->random != nullptr) {
            cout << ", Random: " << head->random->val;
        } else {
            cout << ", Random: nullptr";
        }
        cout << endl;
        head = head->next;  
    }
}

int main() {
    Node* head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;
    cout << "Original Linked List with Random Pointers:" << endl;
    printClonedLinkedList(head);
    cout << endl;
    Node* clonedList = copyRandomList(head);
    cout << "Cloned Linked List with Random Pointers:" << endl;
    printClonedLinkedList(clonedList);

}