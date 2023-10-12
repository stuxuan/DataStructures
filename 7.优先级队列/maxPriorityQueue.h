#pragma once
using namespace std;
template<class T>
class maxPriorityQueue
{
public:
    virtual ~maxPriorityQueue() {}
    // �����Ƿ�Ϊ��
    virtual bool empty() const = 0;
    // ���д�С
    virtual int size() const = 0;
    // �������ȼ���ߵ�Ԫ��
    virtual const T& top() = 0;
    // �������ȼ���ߵ�Ԫ��
    virtual void pop() = 0;
    // ����Ԫ��
    virtual void push(const T& theElement) = 0;
};

