#pragma once
#include "maxPriorityQueue.h"
#include <iostream>
#include <algorithm>

using namespace std;

template<class T>
class maxHeap : public maxPriorityQueue<T>
{
private:
    int heapSize;       // �����е�Ԫ������
    int arrayLength;    // ���е�����
    T* heap;            // Ԫ������ 

public:
    maxHeap(int initialCapacity = 10);
    ~maxHeap() { delete[] heap; }
    bool empty() const { return heapSize == 0; }
    int size() const { return heapSize; }
    const T& top()
    {// �������ȼ�����Ԫ��
        if (heapSize == 0)
        {
            cout << "����Ϊ��" << endl;
            return NULL;
        }
        return heap[1];
    }
    void pop();
    void push(const T&);
    void initialize(T*, int);
    void deactivateArray()
    {
        heap = NULL; arrayLength = heapSize = 0;
    }
    void output() const;
};


template<class T>
void changeLength(T*& a, int oldLength, int newLength)
{// �ı����鳤��
    if (newLength < 1)return;
    T* temp = new T[newLength];              // �µ�����
    int number = min(oldLength, newLength);  // ��Ҫ���Ƶ�Ԫ�ظ���
    copy(a, a + number, temp);
    delete[] a;                              // �����ڴ�
    a = temp;
}

template<class T>
maxHeap<T>::maxHeap(int initialCapacity)
{// ���캯��
    if (initialCapacity < 1)
    {
        cout << "�������ѵ������������1" << endl;
        return;
    }
    arrayLength = initialCapacity + 1;
    heap = new T[arrayLength];
    heapSize = 0;
}

template<class T>
void maxHeap<T>::push(const T& theElement)
{// ��Ԫ�ز��뵽�����

   // �����������
    if (heapSize == arrayLength - 1)
    {
        changeLength(heap, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
    }

    // ΪtheElementѰ�Ҳ���λ��, currentNode����Ҷ�ӽڵ㿪ʼ�����ƶ�
    int currentNode = ++heapSize;
    while (currentNode != 1 && heap[currentNode / 2] < theElement)
    {
        heap[currentNode] = heap[currentNode / 2]; // Ԫ�������ƶ�
        currentNode /= 2;                          // currentNode�ƶ�������˫��
    }

    heap[currentNode] = theElement;
}

template<class T>
void maxHeap<T>::pop()
{// �Ӵ����ɾ������Ԫ��

    if (heapSize == 0)   // ������Ƿ�Ϊ��
        return;

    // ɾ������Ԫ��
    heap[1].~T();

    // �õ����һ��Ԫ��, ���������Ԫ��������1
    T lastElement = heap[heapSize--];

    // �Ӹ��ڵ㿪ʼ, Ϊ���һ��Ԫ�ز��Ҳ���λ��
    int currentNode = 1;    // ��ǰ˫�׽ڵ�
    int child = 2;          // ��ǰ���ӽڵ�
    while (child <= heapSize)
    {
        // heap[child] Ӧ���� currentNode ����ĺ���
        if (child < heapSize && heap[child] < heap[child + 1])
            child++;

        // �Ա� lastElement �Ƿ���Բ��뵽 currentNode
        if (lastElement >= heap[child])
            break;   // ���Բ�����ֱ�ӽ���

        // �����Բ��������ѭ��
        heap[currentNode] = heap[child]; // �ӽڵ������ƶ�
        currentNode = child;             // ��ǰָ��ڵ��ƶ����ӽڵ�
        child *= 2;
    }
    heap[currentNode] = lastElement;
}

template<class T>
void maxHeap<T>::initialize(T* theHeap, int theSize)
{// ������ theHeap[1:theSize] �г�ʼ�������
    delete[] heap;
    heap = theHeap;
    heapSize = theSize;

    // �ѻ�
    for (int root = heapSize / 2; root >= 1; root--)
    {
        T rootElement = heap[root];

        // ��Ԫ�� rootElement Ѱ��λ��
        int child = 2 * root; // ���� child ��˫���� rootElement ��λ��
        // ȷ�� rootElement ��λ��
        while (child <= heapSize)
        {
            // heap[child] �ҵ�������������һ��
            if (child < heapSize && heap[child] < heap[child + 1])
                child++;

            // �Ƿ���԰� rootElement ���뵽��λ��
            if (rootElement >= heap[child])
                break;  // ����

            // ������
            heap[child / 2] = heap[child]; // ���������ƶ�
            child *= 2;                    // ����һ��鿴
        }
        heap[child / 2] = rootElement;
    }
}

template<class T>
void maxHeap<T>::output() const
{
    for (int i = 1; i < heapSize; i++)
    {
        cout << this->heap[i] << " ";
    }
    cout << endl;
}