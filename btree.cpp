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
    left = right = nullptr;
  }
};

Node *buildTree(vector<int> &preorder, int &idx)
{
  idx++;

  if (preorder[idx] == -1)
  {
    return nullptr;
  }

  Node *root = new Node(preorder[idx]);

  root->left = buildTree(preorder, idx);
  root->right = buildTree(preorder, idx);

  return root;
}

void preOrder(Node *root)
{
  if (!root)
    return;
  cout << root->data << endl;
  preOrder(root->left);
  preOrder(root->right);
}
void inOrder(Node *root)
{
  if (!root)
    return;

  inOrder(root->left);
  cout << root->data << endl;
  inOrder(root->right);
}

void postOrder(Node *root)
{
  if (!root)
    return;

  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << endl;
}

void levelOrder(Node* root){
  queue<Node*> q;

  q.push(root);

  while(q.size()>0){
    Node* curr= q.front();
    q.pop();
    cout<<curr->data<<endl;
    if(curr->left != NULL){
      q.push(curr->left);
    }
    if(curr->right != NULL){
      q.push(curr->right);
    }
  }

}


int height(Node * root){

  if(root==nullptr) 
     return 0;

  int leftht= height(root->left);
  int rightht= height(root->right);

  return max(leftht,rightht)+1;
}

int main()
{
  vector<int> preorder = {
      1, 2, -1, -1,
      3, 4, -1, -1,
      5, -1, -1};

  int idx = -1;
  Node *root = buildTree(preorder, idx);

  cout << "Root: " << root->data << endl;
  cout << "Left Child: " << root->left->data << endl;
  cout << "Right Child: " << root->right->data << endl;
  preOrder(root);
  inOrder(root);
  postOrder(root);
   levelOrder(root);

  cout << "Height = " << height(root) << endl;

  return 0;
}