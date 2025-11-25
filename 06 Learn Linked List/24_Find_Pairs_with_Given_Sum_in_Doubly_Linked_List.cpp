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
        next = next1;
        back = back1;
    }
    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

vector<vector<int>> findPairsWithGivenSum(Node* head, int target) {
    Node* temp1 = head;
    Node* temp2 = head;
    vector<vector<int>> list;
    if(temp1 == nullptr || temp1->next == nullptr) {
        return list;
    }
    while(temp2->next != nullptr) {
        temp2 = temp2->next;
    }
    while(temp1->data < temp2->data) {
    if(temp1->data + temp2->data > target) {
        temp2 = temp2->back;
    }
    else if(temp1->data + temp2->data == target) {
        list.push_back({temp1->data, temp2->data});
        temp1 = temp1->next;
    }
    else {
        temp1 = temp1->next;
    }  
}
    return list;
}

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

void printDLL(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    vector<int> headArray = {1, 2, 4, 5, 6, 8, 9};
    int target = 7;
    Node* head = convertArr2DLL(headArray);
    cout << "Origanl DLL is: " << " ";
    printDLL(head);
    cout << endl;
    cout << "Required List is: ";
    vector<vector<int>> result = findPairsWithGivenSum(head, target);
    for(int i=0; i < result.size(); i++) {
        for(int j=0; j < result[0].size() ; j++) {
            cout << result [i][j] << " , ";
        }
    }
    return 0;
}