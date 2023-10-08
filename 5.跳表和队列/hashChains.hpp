#pragma once
#include <iostream>
#include "hash.h"           // 将K转换为非负整数
#include "dictionary.h"     // 字典
#include "sortedChain.hpp"  // 顺序链表字典

using namespace std;

template<class K, class E>
class hashChains : public dictionary<K, E>
{
protected:
    sortedChain<K, E>* table;  // 散列表
    myhash<K> hash;            // 将K转换为非负整数
    int dSize;                 // 元素个数
    int divisor;               // 节点个数

public:
    hashChains(int theDivisor = 11)
    {
        divisor = theDivisor;
        dSize = 0;

        // 初始化一个顺序链表字典的数组作为散列表
        table = new sortedChain<K, E>[divisor];
    }

    ~hashChains() { delete[] table; }

    bool empty() const { return dSize == 0; }
    int size() const { return dSize; }

    pair<const K, E>* find(const K& theKey) const
    {// 只需要确定初始桶的位置然后调用顺序链表字典的查找即可
        return table[hash(theKey) % divisor].find(theKey);
    }

    void insert(const pair<const K, E>& thePair)
    {
        int homeBucket = (int)hash(thePair.first) % divisor;    // 初始桶位置
        int homeSize = table[homeBucket].size();                // 当前该桶大小
        table[homeBucket].insert(thePair);                      // 插入thePair
        if (table[homeBucket].size() > homeSize)                // 如果桶大小发生改变
            dSize++;                                            // 字典元素个数++
    }

    void erase(const K& theKey)
    {
        table[hash(theKey) % divisor].erase(theKey);
    }

    void output() const
    {
        for (int i = 0; i < divisor; i++)
            if (table[i].size() == 0)
                cout << "NULL" << endl;
            else
                table[i].output();
    }
};