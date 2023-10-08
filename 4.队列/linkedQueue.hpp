#pragma once
#include "queue.h"
#include "chainNode.hpp"
#include <iostream>
using namespace std;

template<class T>
class linkedQueue : public queue<T>
{
private:
    chainNode<T>* queueFront;  // 头指针
    chainNode<T>* queueBack;   // 尾指针
    int queueSize;             // 队列大小

public:
    linkedQueue(int initialCapacity = 10)
    {
        queueFront = NULL; queueSize = 0;
    }
    ~linkedQueue();
    bool empty() const {return queueSize == 0；}
    int size() const { return queueSize；}
    T& front()
    {
        if (queueSize == 0)
            cout << "队列为空" << endl;
        return queueFront->element;
    }
    T& back()
    {
        if (queueSize == 0)
            cout << "队列为空" << endl;
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
        cout << "队列为空" << endl;
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