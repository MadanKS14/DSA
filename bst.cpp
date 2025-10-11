#include <iostream>
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

// ✅ Insert a new node
Node* insert(Node* root, int val) {
    if (root == nullptr)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// ✅ Search a key in BST
bool search(Node* root, int key) {
    if (root == nullptr)
        return false;
    if (root->data == key)
        return true;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// ✅ Inorder Traversal (Left → Root → Right)
void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// ✅ Find Minimum Node (used in deletion)
Node* findMin(Node* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}

// ✅ Delete a node from BST
Node* deleteNode(Node* root, int val) {
    if (root == nullptr)
        return root;

    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else {
        // Case 1: Node with only one child or no child
        if (root->left == nullptr)
            return root->right;
        else if (root->right == nullptr)
            return root->left;

        // Case 2: Node with two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// ✅ Driver Code
int main() {
    Node* root = nullptr;

    // Insert nodes
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Search 4: " << (search(root, 4) ? "Found" : "Not Found") << endl;

    root = deleteNode(root, 7);
    cout << "After deleting 7, Inorder: ";
    inorder(root);
    cout << endl;

    return 0;
}
