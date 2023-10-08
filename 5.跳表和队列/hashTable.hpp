#pragma once
#include <iostream>
#include "hash.h"

using namespace std;

template<class K, class E>
class hashTable
{
protected:
    int search(const K&) const;
    pair<const K, E>** table;  // 哈希表
    myhash<K> hash;            // 将K转换为非负整数
    int dSize;                 // 字典的大小
    int divisor;               // 节点个数

public:
    hashTable(int theDivisor = 11);
    ~hashTable() { delete[] table; }

    bool empty() const { return dSize == 0; }
    int size() const { return dSize; }
    pair<const K, E>* find(const K&) const;
    void insert(const pair<const K, E>&);
    void output() const;
};

template<class K, class E>
hashTable<K, E>::hashTable(int theDivisor)
{
    divisor = theDivisor;
    dSize = 0;

    // 分配数组的空间
    table = new pair<const K, E>*[divisor];
    for (int i = 0; i < divisor; i++)
        table[i] = NULL;
}

template<class K, class E>
int hashTable<K, E>::search(const K& theKey) const
{// 查找关键字为 theKey 的键值对, 如果存在匹配的键值对则返回他的位置, 如果不存在则返回可以插入的位置

    int i = (int)hash(theKey) % divisor;  // 起始桶
    int j = i;    // j 从起始桶开始搜索
    do
    {
        if (table[j] == NULL || table[j]->first == theKey)
            return j;
        j = (j + 1) % divisor;  // j 移动到下一个桶
    } while (j != i);           // 回到起始桶位置

    return j;  // 表满
}

template<class K, class E>
pair<const K, E>* hashTable<K, E>::find(const K& theKey) const
{// 返回匹配的指针或NULL

    int b = search(theKey);

    // 空或者和Key不相等都说明没有匹配的键值对
    if (table[b] == NULL || table[b]->first != theKey)
        return NULL;

    return table[b];  // 匹配到键值对
}

template<class K, class E>
void hashTable<K, E>::insert(const pair<const K, E>& thePair)
{// 插入thePair, 若存在相同的则更新值, 表满打印提示

    int b = search(thePair.first);

    if (table[b] == NULL)
    {
        // 没有匹配的键值对则插入
        table[b] = new pair<const K, E>(thePair);
        dSize++;
    }
    else
    {
        if (table[b]->first == thePair.first)
        {// 匹配的键值对相等则更新值
            table[b]->second = thePair.second;
        }
        else // 不相等说明表已经满
            cout << "散列表已满" << endl;
    }
}

template<class K, class E>
void hashTable<K, E>::output() const
{
    for (int i = 0; i < divisor; i++)
    {
        if (table[i] == NULL)
            cout << "NULL" << endl;
        else
            cout << table[i]->first << " "
            << table[i]->second << endl;
    }
}