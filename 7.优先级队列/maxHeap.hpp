#pragma once
#include "maxPriorityQueue.h"
#include <iostream>
#include <algorithm>

using namespace std;

template<class T>
class maxHeap : public maxPriorityQueue<T>
{
private:
    int heapSize;       // 队列中的元素数量
    int arrayLength;    // 队列的容量
    T* heap;            // 元素数组 

public:
    maxHeap(int initialCapacity = 10);
    ~maxHeap() { delete[] heap; }
    bool empty() const { return heapSize == 0; }
    int size() const { return heapSize; }
    const T& top()
    {// 返回优先级最大的元素
        if (heapSize == 0)
        {
            cout << "队列为空" << endl;
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
{// 改变数组长度
    if (newLength < 1)return;
    T* temp = new T[newLength];              // 新的数组
    int number = min(oldLength, newLength);  // 需要复制的元素个数
    copy(a, a + number, temp);
    delete[] a;                              // 清理内存
    a = temp;
}

template<class T>
maxHeap<T>::maxHeap(int initialCapacity)
{// 构造函数
    if (initialCapacity < 1)
    {
        cout << "构造大根堆的数量必须大于1" << endl;
        return;
    }
    arrayLength = initialCapacity + 1;
    heap = new T[arrayLength];
    heapSize = 0;
}

template<class T>
void maxHeap<T>::push(const T& theElement)
{// 将元素插入到大根堆

   // 检查数组容量
    if (heapSize == arrayLength - 1)
    {
        changeLength(heap, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
    }

    // 为theElement寻找插入位置, currentNode从新叶子节点开始向上移动
    int currentNode = ++heapSize;
    while (currentNode != 1 && heap[currentNode / 2] < theElement)
    {
        heap[currentNode] = heap[currentNode / 2]; // 元素向下移动
        currentNode /= 2;                          // currentNode移动到他的双亲
    }

    heap[currentNode] = theElement;
}

template<class T>
void maxHeap<T>::pop()
{// 从大根堆删除最大的元素

    if (heapSize == 0)   // 大根堆是否为空
        return;

    // 删除最大的元素
    heap[1].~T();

    // 拿到最后一个元素, 并将大根堆元素数量减1
    T lastElement = heap[heapSize--];

    // 从根节点开始, 为最后一个元素查找插入位置
    int currentNode = 1;    // 当前双亲节点
    int child = 2;          // 当前孩子节点
    while (child <= heapSize)
    {
        // heap[child] 应该是 currentNode 更大的孩子
        if (child < heapSize && heap[child] < heap[child + 1])
            child++;

        // 对比 lastElement 是否可以插入到 currentNode
        if (lastElement >= heap[child])
            break;   // 可以插入则直接结束

        // 不可以插入则继续循环
        heap[currentNode] = heap[child]; // 子节点向上移动
        currentNode = child;             // 当前指向节点移动到子节点
        child *= 2;
    }
    heap[currentNode] = lastElement;
}

template<class T>
void maxHeap<T>::initialize(T* theHeap, int theSize)
{// 在数组 theHeap[1:theSize] 中初始化大根堆
    delete[] heap;
    heap = theHeap;
    heapSize = theSize;

    // 堆化
    for (int root = heapSize / 2; root >= 1; root--)
    {
        T rootElement = heap[root];

        // 给元素 rootElement 寻找位置
        int child = 2 * root; // 孩子 child 的双亲是 rootElement 的位置
        // 确定 rootElement 的位置
        while (child <= heapSize)
        {
            // heap[child] 找到孩子里更大的那一个
            if (child < heapSize && heap[child] < heap[child + 1])
                child++;

            // 是否可以把 rootElement 插入到该位置
            if (rootElement >= heap[child])
                break;  // 可以

            // 不可以
            heap[child / 2] = heap[child]; // 孩子向上移动
            child *= 2;                    // 下移一层查看
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