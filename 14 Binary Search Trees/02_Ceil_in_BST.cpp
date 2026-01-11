#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;         
    TreeNode* left;   
    TreeNode* right;  
    TreeNode(int key) {
        data = key;
        left = nullptr; 
        right = nullptr;
    }
};

int ceilBST(TreeNode* root, int key) {
  int ceil = -1;
  while(root) {
    if(root->data == key) {
      ceil = root->data;
      return ceil; 
    }
    else if(root->data > key) {
      ceil = root->data;
      root = root->left;
    }
    else {
      root = root->right;
    }
  }
  return ceil;
}

int main() {
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(80);
    int key = 65;
    int result = ceilBST(root, key);
    cout << result << endl;
    return 0;
}