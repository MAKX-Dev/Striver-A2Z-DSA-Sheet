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

int maxSum(Node* root, int& maxi) {
    if(root == nullptr) return 0;
    int left = max(0, maxSum(root->left, maxi));
    int right = max(0, maxSum(root->right, maxi));
    maxi = max(maxi, root->data + left + right);
    return root->data + max(left, right);
}

int maxPathSum(Node* root) {
    int maxi = INT_MIN;
    maxSum(root, maxi);
    return maxi;
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(4);
    root->left->left = new Node(4);
    root->left->right = new Node(2);
    int result = maxPathSum(root);
    cout << "Max Path Sum is: " << endl;
    return 0;
}
