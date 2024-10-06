#pragma once

#include "CancerData.h"

template <class T>
class AVLNode
{

public:
    AVLNode(T data);

    AVLNode(T data, AVLNode<T>* pLeft, AVLNode<T>* pRight, int heightAVLNode);

    ~AVLNode();

    AVLNode(const AVLNode& other);

    AVLNode& operator=(AVLNode& other);

    //Getter function
    T& getData();
    AVLNode<T>*& getpLeft(); //pointer memory location,
    AVLNode<T>*& getpRight();
    int getHeightAVLNode();

    //Setter function
    void setData(T data);
    void setpLeft(AVLNode<T>* pLeft);
    void setpRight(AVLNode<T>* pRight);
    void setHeightAVLNode(int heightAVLNode);
    //void setpRoot(AVLNode<T>* pRoot); needs to be taken out!!! Found an error!!

private:
    T data;
    AVLNode<T>* pLeft;
    AVLNode<T>* pRight;
    int heightAVLNode;
};

template <class T>
AVLNode<T>::AVLNode(T data)
{
    this->data = data; //it will just invoke the default constructor
    this->pLeft = nullptr;
    this->pRight = nullptr;
    this->heightAVLNode = 0;
}

template<class T>
AVLNode<T>::AVLNode(T data, AVLNode<T>* pLeft, AVLNode<T>* pRight, int heightAVLNode)
{
    this->data = data;
    this->pLeft = pLeft;
    this->pRight = pRight;
    this->heightAVLNode = heightAVLNode;
}

template <class T>
AVLNode<T>::~AVLNode()
{
}

template<class T>
AVLNode<T>::AVLNode(const AVLNode& other)
{
    this->data = other.data;
    this->pLeft = other.pLeft;
    this->pRight = other.pRight;
    this->heightAVLNode = other.heightAVLNode;
}

template<class T>
AVLNode<T>& AVLNode<T>::operator=(AVLNode<T>& other)
{
    this->data = other.data;
    this->pLeft = other.pLeft;
    this->pRight = other.pRight;
    this->heightAVLNode = other.heightAVLNode;
}

template <class T>
T& AVLNode<T>::getData()
{
    return this->data;
}

// with inline keyword when the compiler encounters calls to the function,
// it can choose to inline them at the callsite, improving peroformace
template <class T>
AVLNode<T>*& AVLNode<T>::getpLeft()
{
    return pLeft;
}

template <class T>
AVLNode<T>*& AVLNode<T>::getpRight()
{
    return pRight;
}

template <class T>
int AVLNode<T>::getHeightAVLNode()
{
    return this->heightAVLNode;
}

template <class T>
void AVLNode<T>::setData(T data)
{
    this->data = data;
}

template <class T>
void AVLNode<T>::setpLeft(AVLNode<T>* pLeft)
{
    this->pLeft = pLeft;
}

template <class T>
void AVLNode<T>::setpRight(AVLNode<T>* pRight)
{
    this->pRight = pRight;
}

template <class T>
void AVLNode<T>::setHeightAVLNode(int heightAVLNode)
{
    this->heightAVLNode = heightAVLNode;
}

/*
template<class T>
void AVLNode<T>::setpRoot(AVLNode<T>* pRoot)
{
    //this->pLeft = pRoot;
    this->pRoot = pRoot;
} // Found an error!!!! it should be this->pRoot   not this->pLeft!!!
//this cant be in AVLNode class but rather should be in AVLTree class!!!
*/