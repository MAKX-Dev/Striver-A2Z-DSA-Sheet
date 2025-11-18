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

int startingOfLL(Node* head) {
    Node* slow = head;
    Node* fast = head;
    Node* meetingNode = nullptr;
    if(head == nullptr || head->next==nullptr) return NULL;
    while(fast !=nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            meetingNode = slow;
            break;
            }
        }
        if(meetingNode == nullptr) return NULL;
        slow = head;
        while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
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
    int result = startingOfLL(head);
    cout << result << endl;

}