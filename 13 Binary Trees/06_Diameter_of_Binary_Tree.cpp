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

int calculateHeight(Node* node, int& maxDiameter) {
    if(node == nullptr) return 0;
    int leftH = calculateHeight(node->left, maxDiameter);
    int rightH = calculateHeight(node->right, maxDiameter);
    int currentDiameter = leftH + rightH;
    maxDiameter = max(maxDiameter, currentDiameter);
    return 1 + max(leftH, rightH);
}

int diameterOfBinaryTree(Node* root) {
    int maxDiameter = 0;
    calculateHeight(root, maxDiameter);
    return maxDiameter;
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(4);
    root->left->left = new Node(4);
    root->left->right = new Node(2);
    int result = diameterOfBinaryTree(root);
    cout << "Diameter of Bianry Tree is: " << result << endl;
    return 0;
}