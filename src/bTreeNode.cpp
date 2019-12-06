#include "bTreeNode.h"

template<class T>
bTreeNode<T>::bTreeNode()
{
    //ctor
}
template<class T>
bTreeNode<T>::bTreeNode(const T & val){///with initial value
    frontElement = backElement = new node<T>(val);
    sz=1;
}
template<class T>
bTreeNode<T>::bTreeNode(node<T>*frontElement,node<T>*backElement,int sz,bTreeNode<T>*leftestSonV){
    this->frontElement=frontElement;
    this->backElement=backElement;
    this->sz = sz ;
    this->leftestSonV=leftestSonV;
}
template<class T>
bTreeNode<T>::~bTreeNode()
{
    //dtor
}
template<class T>
node<T> * bTreeNode<T>::front(){
    return frontElement;
}
template<class T>
node<T> * bTreeNode<T>::back(){
    return backElement;
}
template<class T>
bTreeNode<T> * bTreeNode<T>::leftestSon(){
    return leftestSonV;
}
template<class T>
int bTreeNode<T>::size(){
    return sz ;
}
template<class T>
void bTreeNode<T>::setFront(node<T>*frontElement){
    this->frontElement = frontElement;
}
template<class T>
void bTreeNode<T>::setBack(node<T>*backElement){
    this->backElement = backElement;
}
template<class T>
void bTreeNode<T>::setSize(int sz){
    this->sz=sz;
}
template<class T>
void bTreeNode<T>::setLeftestSon(bTreeNode<T>*leftestSonV){
    this->leftestSonV = leftestSonV;
}
