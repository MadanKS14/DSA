#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

static int idx = -1;
Node *buildTree(vector<int> &arr)
{
  idx++;
  if (arr[idx] == -1)
  {
    return NULL;
  }
  Node *root = new Node(arr[idx]);
  root->left = buildTree(arr);
  root->right = buildTree(arr);

  return root;
}

void preorderTraversal(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  cout << root->data << " ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void inorderTraversal(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  inorderTraversal(root->left);
  cout << root->data << " ";
  inorderTraversal(root->right);
}

void postorderTraversal(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  cout << root->data << " ";
}

void levelorder(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  queue<Node *> q;
  q.push(root);
  while (!q.empty())
  {
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
      Node *curr = q.front();
      q.pop();
      cout << curr->data << " ";
      if (curr->left != NULL)
        q.push(curr->left);
      if (curr->right != NULL)
        q.push(curr->right);
    }
    cout << endl;
  }
}

int height(Node *root)
{
  if (root == NULL)
  {
    return 0;
  }
  int leftheight = height(root->left);
  int rightheight = height(root->right);
  return max(leftheight, rightheight) + 1;
}

int count(Node *root)
{
  if (root == NULL)
  {
    return 0;
  }
  int leftcount = count(root->left);
  int rightcount = count(root->right);
  return leftcount + rightcount + 1;
}

int sum(Node *root)
{
  if (root == NULL)
  {
    return 0;
  }
  int leftsum = sum(root->left);
  int rightsum = sum(root->right);
  return leftsum + rightsum + root->data;
}

int main()
{
  vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
  Node *root = buildTree(arr);
  cout << "preorder traversal" << endl;
  preorderTraversal(root);
  cout << endl;
  cout << "inorder traversal" << endl;
  inorderTraversal(root);
  cout << endl;
  cout << "postorder traversal" << endl;
  postorderTraversal(root);
  cout << endl;
  cout << "levelorder traversal" << endl;
  levelorder(root);
  cout << endl;
  cout << "Height of Tree is :" << height(root);
  cout << endl;
  cout << "Count of Nodes is :" << count(root);
  cout << endl;
  cout << "Sum of Nodes is :" << sum(root);

  return 0;
}