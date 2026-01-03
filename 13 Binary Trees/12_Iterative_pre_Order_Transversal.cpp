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

vector<int> preOrder(Node* root) {
  vector<int> preorder;
  if(root == NULL) return preorder;
  stack<Node*> st;
  st.push(root);
  while(!st.empty()) {
    root = st.top();
    st.pop();
    preorder.push_back(root->data);
    if(root->right != NULL) {
      st.push(root->right);
    }
    if(root->left != NULL) {
      st.push(root->left);
    }
  }
  return preorder;
}

void deleteTree(Node* root) {
  if(root == NULL) return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    vector<int> result = preOrder(root);
    cout << "Preorder traversal of the binary tree is: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << "  ";
    }
    cout << endl;
    deleteTree(root);
    return 0;
}
