#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int floorBST(TreeNode* root, int key) {
  int floor = -1;
  while(root) {
    if(root->data == key) {
      floor = root->data;
      return floor; 
    }
    else if(root->data > key) {
      root = root->left;
    }
    else {
      floor = root->data;
      root = root->right;
    }
  }
  return floor;
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
    int result = floorBST(root, key);
    cout << result << endl;
    return 0;
}