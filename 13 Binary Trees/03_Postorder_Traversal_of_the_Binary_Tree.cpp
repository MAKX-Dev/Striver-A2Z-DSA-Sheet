#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

void postorder(Node* root, vector<int> &list) {
    if(root == nullptr) return;
    postorder(root->left, list);
    postorder(root->right, list);
    list.push_back(root->data);
}

vector<int> postOrder(Node* root) {
    vector<int> list;
    postorder(root, list);
    return list;
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(4);
    root->left->left = new Node(4);
    root->left->right = new Node(2);
    vector<int> result = postOrder(root);
    cout << "Postorder traversal of the binary tree is: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}