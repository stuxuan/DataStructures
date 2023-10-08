#pragma once
using namespace std;
template<class T>
class maxPriorityQueue
{
public:
    virtual ~maxPriorityQueue() {}
    // 队列是否为空
    virtual bool empty() const = 0;
    // 队列大小
    virtual int size() const = 0;
    // 返回优先级最高的元素
    virtual const T& top() = 0;
    // 弹出优先级最高的元素
    virtual void pop() = 0;
    // 插入元素
    virtual void push(const T& theElement) = 0;
};

