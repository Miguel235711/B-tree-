#ifndef BTREENODE_H
#define BTREENODE_H

#include<iostream>
template<class T>
class bTreeNode;

template <class T>
struct node{
    T val ;
    node<T>*next=NULL;
    bTreeNode<T>*rightSon=NULL;
    node(){}
    node(T val){
        this->val=val;
    }
};

template<class T>
class bTreeNode
{
    public:
        bTreeNode();
        bTreeNode(const T & val);
        bTreeNode(node<T>*frontElement,node<T>*backElement,int sz,bTreeNode<T>*leftestSonV);
        virtual ~bTreeNode();
        node<T> * front();
        node<T> * back();
        int size();
        void setFront(node<T>*frontElement);
        void setBack(node<T>*backElement);
        void setSize(int sz);
        void setLeftestSon(bTreeNode<T>*leftestSonV);
        bTreeNode <T> * leftestSon();
        ///implement basic operations!!!
        /*node<T> * find(const T & val); /// get node or last node
        void split(const int & index,bTreeNode<T>*left,bTreeNode<T>*right);///split using this index as middle and returning the result to the reference parameters
        bTreeNode<T>* join(bTreeNode<T>*left,bTreeNode<T>*right);*/
    protected:
    private:
        node<T> * frontElement=NULL,*backElement=NULL;
        bTreeNode<T> * leftestSonV = NULL ;
        int sz = 0 ;
};

#endif // BTREENODE_H
