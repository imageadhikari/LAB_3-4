
#ifndef BinarySearchTree_h
#define BinarySearchTree_h

class BinarySearchTree{
    public:
        virtual void preorderTraversal() = 0;
        virtual void add(int) = 0;
        virtual bool search(int) = 0;

        virtual int max() = 0;
        virtual int min() = 0;
};

#endif