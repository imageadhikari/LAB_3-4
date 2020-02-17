#ifndef BinaryTree_h
#define BinaryTree_h
class BinarySearchTree {
	public:
		virtual void preorder()=0;
		virtual void add(int data)=0;
		virtual int search(int data)=0;
		virtual int min(int i=1) =0;
		virtual int max(int i=1) =0; 
		virtual void inorder(int i=1)=0;
		virtual void delete_node(int data)=0;
		
};
#endif
