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

bool isLeaf(Node* node) {
  if(node->left == nullptr && node->right == nullptr) return true;
  else return false;
}

void addLeftBoundary(Node* root, vector<int> &res) {
  Node* cur = root->left;
  while(cur) {
    if(!isLeaf(cur)) res.push_back(cur->data);
    if(cur->left) cur = cur->left;
    else cur = cur->right;
  }
}

void addRightBoundary(Node* root, vector<int> &res) {
  Node* cur = root->right;
  vector<int> temp;
  while(cur) {
    if(!isLeaf(cur))  temp.push_back(cur->data);  
    if(cur->right) cur = cur->right;
    else cur = cur->left;
  }
  for(int i = temp.size() - 1; i >= 0; i--) {
    res.push_back(temp[i]);
  }
}

void addLeaves(Node* root, vector<int> &res) {
  if(isLeaf(root)) {
    res.push_back(root->data);
    return;
  }
  if(root->left) addLeaves(root->left, res);
  if(root->right) addLeaves(root->right, res);
}

vector<int> boundaryTraversal(Node* root) {
  vector<int> res;
  if(root == nullptr) return res;
  if(!isLeaf(root)) res.push_back(root->data);
  addLeftBoundary(root, res);
  addLeaves(root, res);
  addRightBoundary(root, res);
  return res;
}

int main() {
   Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    vector<int> ans = boundaryTraversal(root);
    for(int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
    return 0;
   
}