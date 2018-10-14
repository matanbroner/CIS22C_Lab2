//
//  Stack.h
//  CIS22C_Lab2
//
//  Created by Matan Broner on 10/12/18.
//  Copyright © 2018 Matan Broner. All rights reserved.
//

#ifndef Stack_h
#define Stack_h
#include "List.h"

template <typename T>
class Stack : private List<T>
{
public:
    void push(T data);
    T pop();
    
    bool isEmpty();
    void sortStackAscending();
    void sortStackDescending();
    int stackCount();
};

template <typename T>
void Stack<T>::push(T data)
{
    this->addAtTail(data);
}

template <typename T>
T Stack<T>::pop()
{
    return this->deleteTail();
}

template <typename T>
bool Stack<T>::isEmpty()
{
    if (this->getCount() > 0)
        return false;
    else return true;
}

template <typename T>
void Stack<T>::sortStackAscending()
{
    this->sortListAcsending();
}

template <typename T>
void Stack<T>::sortStackDescending()
{
    this->sortListDecsending();
}

template<typename T>
int Stack<T>::stackCount()
{
    return this->getCount();
}

#endif /* Stack_h */
