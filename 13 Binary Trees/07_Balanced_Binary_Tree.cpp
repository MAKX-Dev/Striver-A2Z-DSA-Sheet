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

int checkHeight(Node* root) {
    if(root == nullptr) return 0;
    int left = checkHeight(root->left);
    if(left == -1) return -1;
    int right = checkHeight(root->right);
    if(right == -1) return -1;
    if(abs(left - right) > 1) return -1;
    return 1 + max(left, right);
}

bool isBalanced(Node* root) {
    return checkHeight(root) != -1;
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(4);
    root->left->left = new Node(4);
    root->left->right = new Node(2);
    bool result = isBalanced(root);
    if(result) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}