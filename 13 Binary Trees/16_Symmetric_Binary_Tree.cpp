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

bool isMirror(Node* a, Node* b) {
  if(a == nullptr && b == nullptr) return true;
  if(a == nullptr || b == nullptr) return false;
  if(a->data != b->data) return false;
  return isMirror(a->left, b->right) && isMirror(a->right, b->left);
}

bool isSymmetric(Node* root) {
  Node* a = root->left;
  Node* b = root->right;
  return isMirror(a, b);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    bool result = isSymmetric(root);
    if(result) {
      cout << "YES Symmetric" << endl;
    }
    else {
      cout << "NO not symmetric" << endl;
    }
    return 0;
}