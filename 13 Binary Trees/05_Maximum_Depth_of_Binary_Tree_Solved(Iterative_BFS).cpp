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

int maxDepth(Node* root) {
    if(root == nullptr) return 0;
    queue<Node*> q;
    int depth = 0;
    q.push(root);
    while(!q.empty()) {
        int levelSize = q.size();
        depth++;
        for(int i = 0; i < levelSize; i++) {
            Node* node = q.front();
            q.pop();
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
        }
    }
    return depth;
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(4);
    root->left->left = new Node(4);
    root->left->right = new Node(2);
    int result = maxDepth(root);
    cout << "Max Depth of Binary Tree is: " << result << endl;
    return 0;
}