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

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if(root == nullptr) return nullptr;
    if(root == p || root == q) return root;
    Node* left = lowestCommonAncestor(root->left, p, q);
    Node* right = lowestCommonAncestor(root->right, p, q);
    if(left != nullptr && right != nullptr) return root;
    return left != nullptr ? left : right;
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(4);
    root->left->left = new Node(4);
    root->left->right = new Node(2);
    Node* p = root->left->left = new Node(4);
    Node* q =  root->left->right = new Node(2);
    Node* result = lowestCommonAncestor(root, p, q);
    cout << "Lowest Common Ancestor is: " << result->data << endl;
    return 0;
}