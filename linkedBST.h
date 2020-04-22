#include "BinarySearchTree.h"

class Node
{
public:
  int info;
  Node *left;
  Node *right;
};

class bst : public BinarySearchTree
{
private:
  Node *root;

public:
  bst();
  ~bst();
  void preorderTraversal();
  void preorderTraversal(Node *root);
  void inorderTraversal();
  void inorderTraversal(Node *root);
  void add(int data);
  bool search(int data);
  bool isEmpty();
  int min(Node *root);
  int max(Node *root);
  int min();
  int max();
  void delete_node();
  Node *delete_node(Node *root, int key);

  Node *get_root()
  {
    return root;
  }
};
