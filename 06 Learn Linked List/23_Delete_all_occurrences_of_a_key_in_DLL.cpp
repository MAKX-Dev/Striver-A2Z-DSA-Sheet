#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node* back;
    public:
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        back = back1;
        next = next1;
    }
    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2DLL(vector<int>& arr) {
    if(arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node* deleteAllOcurrences(Node* head, int target) {
    while(head != nullptr && head->data == target) {
        Node* toDelete = head;
        head = head->next;
        if(head != nullptr) {
            head->back = nullptr;
        }
        delete(toDelete);
    }
    if(head == nullptr) return nullptr;
    Node* current = head;
    while(current != nullptr) {
        if(current->data == target) {
            Node* prevNode = current->back;
            Node* nextNode = current->next;
            prevNode->next = nextNode;
            if(nextNode != nullptr) {
                nextNode->back = prevNode;
            }
            delete(current);
            current = nextNode;
        }
            else {
                current = current->next;
            }
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
    vector<int> arr = {2, 3, 2, 1, 4, 2};
    Node* head = convertArr2DLL(arr);
    int target = 2;
    cout << "Orignal DLL is: " << " ";
    printLL(head);
    cout << endl;
    cout << "After deleting all target ocurrences DLL is: " << " ";
    head = deleteAllOcurrences(head, target);
    printLL(head);
    return 0;
}

// TC O(N) 
// SC O(1)