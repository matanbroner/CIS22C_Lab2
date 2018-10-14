//
//  List.h
//  CIS22C_Lab2
//
//  Created by Matan Broner on 10/10/18.
//  Copyright © 2018 Matan Broner. All rights reserved.
//

#ifndef List_h
#define List_h
#include "Node.h"

template<typename T>
class List
{
private:
    int count;
    Node<T>* head;
    Node<T>* tail;
    
public:
    List<T>();
    int getCount();
    
    void addAtPos(int index, T data);
    T deleteAnywhere(int index);
    
    T getDataAtIndex(int i);
    int searchByData(T data);
    
    void emptyListContents();
    void sortListAcsending();
    void sortListDecsending();
    
    void addAtHead(T data);
    void addAtTail(T data);
    
    T deleteHead();
    T deleteTail();
    
    void printList();
};

template<typename T>
List<T>::List()
{
    this->head = NULL;
    this->tail = NULL;
    this->count = 0;
}

template<typename T>
int List<T>::getCount()
{
    return this->count;
}

template<typename T>
void List<T>::addAtPos(int index, T data)
{
    if (index >= this->getCount() || index < 0)
    {
        if (index == this->getCount())
        {
            this->addAtTail(data);
        }
        else
        std::cout<< "Attempting to access unavailable index!" << std::endl;
        return;
    }
   
    if (index == 0) // add at head
    {
        this->addAtHead(data);
    }
    
    
    else
    {
        Node<T>* newNode = new Node<T>;
        newNode->setData(data);
        
        Node<T>* tempPtr = this->head;
        while(index > 2)
        {
            tempPtr = tempPtr->getNext();
            index--;
        }
        if (tempPtr->getNext() != NULL)
        {
            newNode->setNext(tempPtr->getNext());
            tempPtr->setNext(newNode);
            this->count++;
        }

    }
}

template<typename T>
void List<T>::addAtHead(T data)
{
    Node<T>* newNode = new Node<T>;
    newNode->setData(data);
   
    newNode->setNext(this->head);
    this->head = newNode;
    this->count++;
}

template<typename T>
void List<T>::addAtTail(T data)
{
    Node<T>* newNode = new Node<T>;
    newNode->setData(data);
    newNode->setNext(NULL);

    if (this->head != NULL)
    {
        Node<T>* tempPtr = head;
        while(tempPtr->getNext() != NULL)
        {
            tempPtr = tempPtr->getNext();
        }
        tempPtr->setNext(newNode);
    }
    else this->head = newNode;
    this->count++;
}

template<typename T>
T List<T>::deleteHead()
{
    if (this->head)
    {
        Node<T>* tempPtr = this->head;
        this->head = tempPtr->getNext();
        this->count--;
        return tempPtr->getData();
    }
    else return NULL;
}

template<typename T>
T List<T>::deleteTail()
{
    if (this->head && this->count > 1)
    {
        Node<T>* curr = this->head;
        Node<T>* prev = NULL;
        while(curr->getNext())
        {
            prev = curr;
            curr = curr->getNext();
        }
        prev->setNext(NULL);
        this->count--;
        T temp = curr->getData();
        curr = NULL;
        return temp;
    }
    else {return this->deleteHead();}
    std::cout << "List empty, no tail to delete. Return NULL" << std::endl;
    return NULL;
}

template<typename T>
T List<T>::deleteAnywhere(int index)
{
    if (index < 0 || index > this->getCount() - 1)
    {
        std::cout << "Attempting to access invalid data point! Return NULL" << std::endl;
        return NULL;
    }
    if (index == 0)
        return this->deleteHead();
    else if (index >= this->getCount() - 1)
        return this->deleteTail();
    else
    {
        Node<T>* curr = this->head;
        Node<T>* prev = NULL;
        while(index > 0)
        {
            prev = curr;
            curr = curr->getNext();
            index--;
        }
        prev->setNext(curr->getNext());
        this->count--;
        T temp = curr->getData();
        curr = NULL;
        return temp;
    }
}

template<typename T>
T List<T>::getDataAtIndex(int i)
{
    Node<T>* tempPtr = this->head;
    while(tempPtr != NULL)
    {
        if (i == 0)
            return tempPtr->getData();
        i--;
        tempPtr = tempPtr->getNext();
    }
    
    std::cout << "Attempting to access data point past list end! Return NULL" << std::endl;
    return NULL;
}

template<typename T>
int List<T>::searchByData(T data)
{
    int count = 0;
    Node<T>* tempPtr = this->head;
    while(tempPtr->getNext())
    {
        if (tempPtr->getData() == data)
            return count;
        count++;
        tempPtr = tempPtr->getNext();
    }
    std::cout << "Data not contained in list, returning index 0" << std::endl;
    return 0;
}

template<typename T>
void List<T>::emptyListContents()
{
    this->head = NULL;
}

template<typename T>
void List<T>::sortListAcsending()
{
    for (Node<T> *index = this->head; index->getNext() != NULL; index = index->getNext())
    {
        for (Node<T> *selection = index->getNext(); selection != NULL; selection = selection->getNext())
        {
            if (index->getData() > selection->getData())
            {
                T tempData = index->getData();
                index->setData(selection->getData());
                selection->setData(tempData);
            }
        }
    }

}

template<typename T>
void List<T>::sortListDecsending()
{
    for (Node<T> *index = this->head; index->getNext() != NULL; index = index->getNext())
    {
        for (Node<T> *selection = index->getNext(); selection != NULL; selection = selection->getNext())
        {
            if (index->getData() < selection->getData())
            {
                T tempData = index->getData();
                index->setData(selection->getData());
                selection->setData(tempData);
            }
        }
    }
}

template <typename T>
void List<T>::printList()
{
    Node<T>* readPtr = this->head;
    while(readPtr != NULL)
    {
        std::cout << readPtr->getData();
        if (readPtr->getNext() != NULL)
            std::cout << " ";
        readPtr = readPtr->getNext();
    }
    std::cout << std::endl;
}

#endif /* List_h */
