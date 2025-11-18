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
    Node(int data1){
        data = data1;
        next = nullptr;
    } 
};

int LengthOfLoop(Node* head) {
    if(head == nullptr && head->next == nullptr){
        return NULL;
    }
    Node* fast = head;
    Node* slow = head;
    Node* meetingNode = NULL;
    while(fast != nullptr && fast->next != nullptr) {
        if(slow == fast){
            meetingNode = slow;
            break;
        }
    }
    if(meetingNode == nullptr) return 0;
    int cnt = 1;
    Node* temp = meetingNode->next;
    while(temp != meetingNode){
        cnt++;
        temp = temp->next;
    }
    return cnt;    
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth= new Node(5);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third; 
    int result = LengthOfLoop(head);
    cout << "Length of Loop in Linked List is: " << result <<endl;
    return 0;

        
}