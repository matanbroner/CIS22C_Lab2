//
//  Node.h
//  CIS22C_Lab2
//
//  Created by Matan Broner on 10/10/18.
//  Copyright © 2018 Matan Broner. All rights reserved.
//

#ifndef Node_h
#define Node_h

template<typename T>
class Node
{
private:
    T data;
    Node<T> *pNode;
public:
    void setData(T dataAdd);
    T getData();
    void setNext(Node<T> *ptr);
    Node<T>* getNext();
};

template<typename T>
void Node<T>::setData(T dataAdd)
{
    this->data = dataAdd;
}

template<typename T>
T Node<T>::getData()
{
    return this->data;
}

template<typename T>
void Node<T>::setNext(Node<T> *ptr)
{
    this->pNode = ptr;
}

template<typename T>
Node<T>* Node<T>::getNext()
{
    return this->pNode;
}
#endif /* Node_h */
