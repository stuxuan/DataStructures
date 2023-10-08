#pragma once
#include "queue.h"
#include "chainNode.hpp"
#include <iostream>
using namespace std;

template<class T>
class linkedQueue : public queue<T>
{
private:
    chainNode<T>* queueFront;  // ͷָ��
    chainNode<T>* queueBack;   // βָ��
    int queueSize;             // ���д�С

public:
    linkedQueue(int initialCapacity = 10)
    {
        queueFront = NULL; queueSize = 0;
    }
    ~linkedQueue();
    bool empty() const {return queueSize == 0��}
    int size() const { return queueSize��}
    T& front()
    {
        if (queueSize == 0)
            cout << "����Ϊ��" << endl;
        return queueFront->element;
    }
    T& back()
    {
        if (queueSize == 0)
            cout << "����Ϊ��" << endl;
        return queueBack->element;
    }
    void pop();
    void push(const T&);
};

template<class T>
linkedQueue<T>::~linkedQueue()
{
    while (queueFront != NULL)
    {
        chainNode<T>* nextNode = queueFront->next;
        delete queueFront;
        queueFront = nextNode;
    }
}

template<class T>
void linkedQueue<T>::pop()
{
    if (queueFront == NULL)
    {
        cout << "����Ϊ��" << endl;
        return;
    }

    chainNode<T>* nextNode = queueFront->next;
    delete queueFront;
    queueFront = nextNode;
    queueSize--;
}


template<class T>
void linkedQueue<T>::push(const T& theElement)
{
    chainNode<T>* newNode = new chainNode<T>(theElement, NULL);

    if (queueSize == 0)
        queueFront = newNode;
    else
        queueBack->next = newNode;
    queueBack = newNode;

    queueSize++;
}