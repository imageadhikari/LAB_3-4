#include <iostream>
#include "linkedBST.h"

bst::bst()
{
  root = nullptr;
}

bst::~bst()
{
}

void bst::add(int data)
{
  if (isEmpty())
  {
    Node *newNode = new Node();
    root = newNode;
    root->info = data;
  }
  else
  {
    Node *newnode = root;
    Node *pre = NULL;
    bool l = false;
    bool r = false;
    while (newnode != NULL)
    {
      pre = newnode;
      l = false;
      if (data < newnode->info)
      {
        newnode = newnode->left;
        l = true;
      }
      else if (data > newnode->info)
      {
        newnode = newnode->right;
      }
    }
    if (l)
    {
      Node *n = new Node();
      n->info = data;
      pre->left = n;
    }
    else
    {
      Node *n = new Node();
      n->info = data;
      pre->right = n;
    }
  }
}

void bst::preorderTraversal(Node *root)
{
  if (root == NULL)
    return;

  std::cout << root->info << " ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void bst::preorderTraversal()
{
  preorderTraversal(root);
}

void bst::inorderTraversal(Node *root)
{
  if (root == NULL)
    return;

  inorderTraversal(root->left);
  std::cout << root->info << " ";
  inorderTraversal(root->right);
}

void bst::inorderTraversal()
{
  inorderTraversal(root);
}

bool bst::search(int data)
{
  Node *prev;
  prev = root;
  while (prev != NULL)
  {
    if (prev->info == data)
    {
      return true;
    }
    else if (data < prev->info)
    {
      prev = prev->left;
    }
    else if (data > prev->info)
    {
      prev = prev->right;
    }
  }
  return false;
}

bool bst::isEmpty()
{
  if (root == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int bst::min(Node *root)
{
  Node *p = root;
  while (p->left != NULL)
  {
    p = p->left;
  }
  return p->info;
}

int bst::min()
{
  min(root);
}

int bst::max()
{
  max(root);
}

int bst::max(Node *root)
{
  Node *p = root;
  while (p->right != NULL)
  {
    p = p->right;
  }
  return p->info;
}

void bst::delete_node()
{
  delete_node(root, 6);
}

Node *bst::delete_node(Node *root, int key)
{
  if (root == NULL)
  {
    return root;
  }
  if (key < root->info)
  {
    return delete_node(root->left, key);
  }
  else if (key > root->info)
  {
    return delete_node(root->right, key);
  }
  else
  {
    if (root->left == NULL)
    {
      Node *temp = root->right;
      delete (root);
      return temp;
    }
    else if (root->right == NULL)
    {
      Node *temp = root->left;
      delete (root);
      return temp;
    }
    else
    {
      Node *current = root->right;
      while (current && current->left != NULL)
      {
        current = current->left;
      }
      Node *temp = current;
      root->info = temp->info;
      root->right = delete_node(root->right, temp->info);
    }
  }
  return root;
}

int main()
{
  bst a;
  a.add(7);
  a.add(5);
  a.add(4);
  a.add(2);
  a.add(1);
  a.add(8);
  a.add(6);

  std::cout << "PreOrder Traversal: ";
  a.preorderTraversal();
  std::cout << std::endl;

  std::cout << "InOrder Traversal: ";
  a.inorderTraversal();
  std::cout << std::endl;

  std::cout << "Delete 5" << std::endl;
  Node *p = a.delete_node(a.get_root(), 5);
  std::cout << "Inorder Traversal: ";
  a.inorderTraversal();
  std::cout << std::endl;

  if (a.search(6))
  {
    std::cout << "Search Successful. Data Found" << std::endl;
  }
  else
  {
    std::cout << "Search Successful. Data Not Found" << std::endl;
  }
  std::cout << "the Smallest Key is " << a.min() << std::endl;
  std::cout << "the Largest Key is " << a.max() << std::endl;
}
