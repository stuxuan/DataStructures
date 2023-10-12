#pragma once

#include<iostream>
using namespace std;
template<class T>
class arrayQueue :public queue<T>
{
private:
    int theFront;       // ��һ��Ԫ�ص�ǰһ��
    int theBack;        // ���һ��Ԫ��
    int arrayLength;    // ���г���
    T* queue;           // ���б���
public:
    arrayQueue(int initialCapacity = 10);
    ~arrayQueue() { delete[] queue; }
    bool empty() const { return theFront == theBack; }
    int size() const
    {
        return (theBack - theFront + arrayLength) % arrayLength;
    }
    T& front()
    {
        if (theFront == theBack)
        {
            cout << "����Ϊ��" << endl;
        }
        return queue[(theFront + 1) % arrayLength];
    }
    T& back()
    {
        if (theFront == theBack)
        {
            cout << "����Ϊ��" << endl;
        }
        return queue[theBack];
    }
    void pop()
    {
        if (theFront == theBack)
        {
            cout << "����Ϊ��" << endl;
            return;
        }
        cout << queue[(theFront + 1) % arrayLength];
        theFront = (theFront + 1) % arrayLength;
        queue[theFront].~T();
    }
    void push(const T& theElement);
};


template<class T>
arrayQueue<T>::arrayQueue(int initialCapacity)
{
    if (initialCapacity < 1)
    {
        cout << "initialCapacity ����Ϊ������" << endl;
        return;
    }
    arrayLength = initialCapacity;
    queue = new T[arrayLength];
    theFront = 0;
    theBack = 0;
}

template<class T>
void arrayQueue<T>::push(const T& theElement)
{
    if ((theBack + 1) % arrayLength == theFront)
    {
        T* newQueue = new T[2 * arrayLength];

        int start = (theFront + 1) % arrayLength;
        if (start < 2)
            copy(queue + start, queue + start + arrayLength - 1, newQueue);
        else
        {
            copy(queue + start, queue + arrayLength, newQueue);
            copy(queue, queue + theBack + 1, newQueue + arrayLength - start);
        }

        theFront = 2 * arrayLength - 1;
        theBack = arrayLength - 2;
        arrayLength *= 2;
        queue = newQueue;
    }

    theBack = (theBack + 1) % arrayLength;
    queue[theBack] = theElement;
}