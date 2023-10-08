#pragma once
using namespace std;

template<class K, class E>
class dictionary
{
public:
    virtual ~dictionary() {}
    // 返回字典是否为空
    virtual bool empty() const = 0;
    // 返回有多少键值对
    virtual int size() const = 0;
    // 根据K返回E
    virtual pair<const K, E>* find(const K&) const = 0;
    // 根据K删除键值对
    virtual void erase(const K&) = 0;
    // 插入一个键值对
    virtual void insert(const pair<const K, E>&) = 0;
};

