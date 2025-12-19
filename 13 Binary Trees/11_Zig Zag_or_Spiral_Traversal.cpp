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

vector<vector<int>> zigzagLevelOrder(Node* root) {
    queue<Node*> q;
    vector<vector<int>> ans;
    if(root == nullptr) return ans;
    q.push(root);
    bool leftToRight = true;
    while(! q.empty()) {
        int size = q.size();
        vector<int> level(size);
        for(int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();
            int ind = leftToRight ? i : size - i - 1; 
            level[ind] = node->data;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        ans.push_back(level);
        leftToRight = ! leftToRight; 
    }
    return ans;
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(4);
    root->left->left = new Node(4);
    root->left->right = new Node(2);
    vector<vector<int>> result = zigzagLevelOrder(root);
    cout << " zigzag level order traversal of its nodes' values: " << endl;
    for(int i = 0; result.size(); i++) {
        for(int j = 0; j < result[0].size(); i++) {
            cout << result[i][j] << " ";
        }
    }
    return 0;
}