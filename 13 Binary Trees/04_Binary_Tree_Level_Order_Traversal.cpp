#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;
    if(root == nullptr) return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        vector<int> level;
        for(int i = 0; i <size; i++) {
            Node* node = q.front();
            q.pop();
            if(node->left != nullptr) {
                q.push(node->left);
            }
            if(node->right != nullptr) {
                q.push(node->right);
            }
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    vector<vector<int>> result = levelOrder(root);
    cout << "level order traversal of its nodes' values: ";
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << ",";
        }
    }
    return 0;
}