#pragma once
#include <iostream>
#include <string>
#include "dictionary.h"
#include "skipNode.h"

using namespace std;

template<class K, class E>
class skipList : public dictionary<K, E>
{
protected:
    float cutOff;                           // 用来确定层数
    int level() const;                      // 用随机数计算插入节点在第几级链表
    int levels;                             // 当前最大的非空链表
    int dSize;                              // 键值对个数
    int maxLevel;                           // 允许的最大链表层数
    K tailKey;                              // 最大关键字
    skipNode<K, E>* search(const K&) const; // 根据Key查找节点
    skipNode<K, E>* headerNode;             // 头节点指针（每一级的头节点)
    skipNode<K, E>* tailNode;               // 尾节点指针（每一级的尾节点)
    skipNode<K, E>** last;                  // last[i] 表示第 i 层的最后一个结点

public:
    skipList(K, int maxPairs = 10000, float prob = 0.5);
    ~skipList();

    bool empty() const { return dSize == 0; }
    int size() const { return dSize; }
    pair<const K, E>* find(const K&) const;
    void erase(const K&);
    void insert(const pair<const K, E>&);
    void output() const;

};

template<class K, class E>
skipList<K, E>::skipList(K largeKey, int maxPairs, float prob)
{// 构造函数, 关键字小于largeKey, 且个数最多为maxPairs, 概率因子(0, 1)
    cutOff = prob * RAND_MAX;
    maxLevel = (int)ceil(logf((float)maxPairs) / logf(1 / prob)) - 1;
    levels = 0;  // 初始化层数
    dSize = 0;
    tailKey = largeKey;

    // 创建头结点尾结点和数组last
    pair<K, E> tailPair;
    tailPair.first = tailKey;
    headerNode = new skipNode<K, E>(tailPair, maxLevel + 1);
    tailNode = new skipNode<K, E>(tailPair, 0);
    last = new skipNode<K, E> *[maxLevel + 1];

    // 链表为空时, 所有头节点都指向尾节点
    for (int i = 0; i <= maxLevel; i++)
        headerNode->next[i] = tailNode;
}

template<class K, class E>
skipList<K, E>::~skipList()
{// 删除所有节点以及last数组
    skipNode<K, E>* nextNode;

    // 根据第0级删除所有节点
    while (headerNode != tailNode)
    {
        nextNode = headerNode->next[0];
        delete headerNode;
        headerNode = nextNode;
    }
    delete tailNode;

    delete[] last;
}

template<class K, class E>
pair<const K, E>* skipList<K, E>::find(const K& theKey) const
{// 返回匹配的 键值对指针 或 NULL
    if (theKey >= tailKey)
        return NULL;

    // 位置 beforeNode 是关键字为 theKey 的节点之前最右边的位置
    skipNode<K, E>* beforeNode = headerNode;
    for (int i = levels; i >= 0; i--)                       // 自上而下: 从上级链表向下查找
        while (beforeNode->next[i]->element.first < theKey) // 自左而右: 第 i 级的指针链表一直向右移动
            beforeNode = beforeNode->next[i];

    if (beforeNode->next[0]->element.first == theKey)
        return &beforeNode->next[0]->element;

    return NULL;
}

template<class K, class E>
int skipList<K, E>::level() const
{// 假设prob是1/2, 这里就是它是第几级链表的概率, 级越高概率越低, 数据量规模足够大时每层都是下面一层的1/2
    int lev = 0;
    while (rand() <= cutOff)    // 每次小于它的概率都是1/2
        lev++;
    cout << "它位于第" << lev << "级链表" << endl;
    return (lev <= maxLevel) ? lev : maxLevel;
}

template<class K, class E>
skipNode<K, E>* skipList<K, E>::search(const K& theKey) const
{// 搜索关键字 theKey, 把每一级链表中要查看的最后一个节点存储在 last 中
 // 返回 theKey 对应的键值对（如果有的话，在insert中进行了判断）
    skipNode<K, E>* beforeNode = headerNode;
    for (int i = levels; i >= 0; i--)
    {
        while (beforeNode->next[i]->element.first < theKey)
            beforeNode = beforeNode->next[i];
        last[i] = beforeNode;  // 把每一层theKey的前一个结点都存储到last数组里
    }
    return beforeNode->next[0];
}

template<class K, class E>
void skipList<K, E>::insert(const pair<const K, E>& thePair)
{// 把 thePair 插入字典, 或覆盖已有关键字的键值对
    if (thePair.first >= tailKey)
    {
        cout << "关键字过大" << endl;
        return;
    }

    // 查看关键字是否已经存在
    skipNode<K, E>* theNode = search(thePair.first);
    if (theNode->element.first == thePair.first)
    {   // 已经存在则更新键值对的值
        theNode->element.second = thePair.second;
        return;
    }

    // 不存在则插入新的键值对
    int theLevel = level(); // 新节点存在于几级链表
    // 如果这个链表级别太高了, 让他只变为当前链表等级+1
    if (theLevel > levels)
    {
        theLevel = ++levels;
        last[theLevel] = headerNode;
    }

    skipNode<K, E>* newNode = new skipNode<K, E>(thePair, theLevel + 1);
    for (int i = 0; i <= theLevel; i++)
    {// 在每一级插入该节点
        newNode->next[i] = last[i]->next[i];
        last[i]->next[i] = newNode;
    }

    dSize++;
    return;
}

template<class K, class E>
void skipList<K, E>::erase(const K& theKey)
{// 删除关键字为theKey的数对
    if (theKey >= tailKey)
        return;

    // 判断是否有匹配的键值对
    skipNode<K, E>* theNode = search(theKey);
    if (theNode->element.first != theKey)
        return;

    // 从跳表删除键值对
    for (int i = 0; i <= levels && last[i]->next[i] == theNode; i++)
        last[i]->next[i] = theNode->next[i];
 
    // 更新调表级数
    while (levels > 0 && headerNode->next[levels] == tailNode)
        levels--;

    delete theNode;
    dSize--;
}

template<class K, class E>
void skipList<K, E>::output() const 
{
    skipNode<K, E>* p;
    for (int i = levels; i >= 0; i--)
    {
        p = headerNode;
        while (p->next[i]->element.first < tailKey)
        {
            p = p->next[i];
            cout << p->element.second << ", ";
        }
        cout << endl;
    }
}