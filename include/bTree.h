#ifndef BTREE_H
#define BTREE_H

#include<iostream>
#include "bTreeNode.h"

enum ord{pre,in,pos};

template<class T>
class bTree
{
    public:
        bTree();
        bTree(int minNodes);
        virtual ~bTree();
        bool insert(const T & val);///true if element is not repeated
        bool remove(const T & val);///false if element does not exist
        void printPreorder();
        void printInorder();
        void printPosorder();
        int getHeight();
        int getRootSize();
        int countRootSize();
        int size();
    protected:

    private:
        bTreeNode<T> * root = NULL ;
        bool insertF(bTreeNode<T>* bNode,const T & val,bTreeNode<T>*bBefore,node<T>*left,node<T>*right,bTreeNode<T>*bBeforeOfBefore);
        bool removeF(bTreeNode<T>* bNode,bTreeNode<T>*parentBNode,const T & val,bTreeNode<T>*leftBNode,bTreeNode<T>*rightBNode,node<T>*leftParentNode,node<T>*parentNode);
        void fixDeletion(bTreeNode<T>*bNode,bTreeNode<T>*parentBNode,bTreeNode<T>*leftBNode,bTreeNode<T>*rightBNode,node<T>*leftParentNode,node<T>*parentNode);
        void fixInsertion(bTreeNode<T>*bNode,bTreeNode<T>*bBefore,node<T>*left,node<T>*right);
        void deleteInLeaf(bTreeNode<T>*bNode,node<T>*left,node<T>*nodeToDelete);
        void handleRemove(bTreeNode<T>*bNode,node<T>*left,node<T>*nodeToDelete);
        void printOrder(bTreeNode<T>*bNode,const ord & order);
        T getLeftest(bTreeNode<T>*bNode);
        int getHeightF(bTreeNode<T>*bNode);
        int sizeF(bTreeNode<T>*bNode);
        int minNodes=1;
};

#endif // BTREE_H
