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

vector<int> inOrder(Node* root) {
  stack<Node*> st;
  Node* node = root;
  vector<int> inorder;
  while(node != nullptr || !st.empty()) {
    while(node != nullptr) {
      st.push(node);
      node = node->left;
    }
    node = st.top();
    st.pop();
    inorder.push_back(node->data);
    node = node->right;
  }
  return inorder;
}

int main() {
  struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    vector<int> result = inOrder(root);
    cout << "Inorder traversal of the binary tree is: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << "  ";
    }
    return 0;
}