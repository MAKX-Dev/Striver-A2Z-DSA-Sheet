#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void preorder(Node* root, vector<int> &list) {
    if(root == nullptr) return;
    list.push_back(root->data);
    preorder(root->left, list);
    preorder(root->right, list);
}

 vector<int> preOrder(Node* root){
        vector<int> list;
        preorder(root, list);
        return list;
    }

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    vector<int> result = preOrder(root);
    cout << " Preorder traversal of the binary tree is: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << "  ";
    }
    return 0;
}