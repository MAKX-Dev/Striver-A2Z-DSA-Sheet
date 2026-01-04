#include <bits/stdc++.h>
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

bool isSameTree(Node* p, Node* q) {
  if(p == nullptr && q == nullptr) return true;
  if(p == nullptr || q == nullptr) return false;
  if(p->data != q->data) return false;
  return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    Node* p = new Node(1);
    p->left = new Node(2);
    p->right = new Node(2);
    p->left->right = new Node(5);
    Node* q = new Node(1);
    q->left = new Node(2);
    q->right = new Node(3);
    q->left->right = new Node(5);
    bool result = isSameTree(p, q);
    if(result) {
      cout << "Trees are same" << endl;
    }
    else {
      cout << "Trees are not same" << endl;
    }
    return 0;
}
