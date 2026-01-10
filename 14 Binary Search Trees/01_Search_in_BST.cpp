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

TreeNode* searchBST(TreeNode* root, int val) {
  while(root != nullptr && root->data != val) {
    root = val < root->data ? root->left : root->right;
  }
  return root;
}

int main() {
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(80);
    TreeNode* ans = searchBST(root, 40);
    if(ans != nullptr) {
        cout << ans->data << endl;
    }
    return 0;
}