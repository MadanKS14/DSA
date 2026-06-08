#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

int idx = -1;

// Build Tree from Preorder Traversal
Node* buildTree(vector<int>& preorder) {
    idx++;

    if (preorder[idx] == -1) {
        return nullptr;
    }

    Node* root = new Node(preorder[idx]);

    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

// Find Height of Binary Tree
int height(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main() {
    vector<int> preorder = {
        1,
        2, -1, -1,
        3,
        4, -1, -1,
        5, -1, -1
    };

    Node* root = buildTree(preorder);

    cout << "Height of Binary Tree = "
         << height(root) << endl;

    return 0;
}