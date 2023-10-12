// abstract class dictionary
// abstract data type specification for dictionary data structure
// all methods are pure virtual functions
// K is key type and E is value type

#pragma once
using namespace std;

template<class K, class E>
class dictionary
{
public:
    virtual ~dictionary() {}
    // 返回是否为空
    virtual bool empty() const = 0;
    // 返回字典中元素个数
    virtual int size() const = 0;
    // 返回关键字为K的值
    virtual pair<const K, E>* find(const K&) const = 0;
    // 清空关键字为K的元素
    virtual void erase(const K&) = 0;
    // 插入一个键值对
    virtual void insert(const pair<const K, E>&) = 0;
};

