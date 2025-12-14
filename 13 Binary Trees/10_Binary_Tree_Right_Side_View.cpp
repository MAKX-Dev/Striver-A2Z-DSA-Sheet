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

void dfs(Node* root, vector<int> &ans, int level) {
    if(root == nullptr) return;
    if(level == ans.size()) {
        ans.push_back(root->data);
    }
    dfs(root->right, ans, level + 1);
    dfs(root->left, ans, level + 1);
}

vector<int> rightSideView(Node* root) {
    vector<int> ans;
    dfs(root, ans, 0);
    return ans;
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(4);
    root->left->left = new Node(4);
    root->left->right = new Node(2);
    vector<int> result = rightSideView(root);
    cout << "Node values from right side of binary Tree are: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " "; 
    } 
    return 0;
}