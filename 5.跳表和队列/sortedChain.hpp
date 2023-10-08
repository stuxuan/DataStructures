#pragma once
#include <iostream>
#include "dictionary.h"
#include "pairNode.h"

using namespace std;

template<class K, class E>
class sortedChain : public dictionary<K, E>
{
protected:
    pairNode<K, E>* firstNode; // 第一个结点
    int dSize;                 // 字典的大小

public:
    sortedChain() { firstNode = NULL; dSize = 0; }
    ~sortedChain();

    bool empty() const { return dSize == 0; }
    int size() const { return dSize; }
    pair<const K, E>* find(const K&) const;
    void erase(const K&);
    void insert(const pair<const K, E>&);
    void output();
};

template<class K, class E>
sortedChain<K, E>::~sortedChain()
{
    while (firstNode != NULL)
    {
        pairNode<K, E>* nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

template<class K, class E>
pair<const K, E>* sortedChain<K, E>::find(const K& theKey) const
{// 返回匹配的指针, 不存在则返回NULL
    pairNode<K, E>* currentNode = firstNode;

    while (currentNode != NULL && currentNode->element.first != theKey)
        currentNode = currentNode->next;

    if (currentNode != NULL && currentNode->element.first == theKey)
        return &currentNode->element;

    return NULL;
}

template<class K, class E>
void sortedChain<K, E>::insert(const pair<const K, E>& thePair)
{// 在字典中插入一个键值对, 并且覆盖已经存在的键值对
    pairNode<K, E>* p = firstNode;
    pairNode<K, E>* tp = NULL;

    while (p != NULL && p->element.first < thePair.first)
    {// 终止后要插入的结点在tp后, p之前
        tp = p;
        p = p->next;
    }

    if (p != NULL && p->element.first == thePair.first)
    {// 如果有匹配的键值对, 替换旧值
        p->element.second = thePair.second;
        return;
    }

    // 如果没有匹配的键值对, 创建一个新的节点, 该节点的下一个结点为p
    pairNode<K, E>* newNode = new pairNode<K, E>(thePair, p);

    if (tp == NULL) firstNode = newNode;
    else tp->next = newNode;

    dSize++;
    return;
}

template<class K, class E>
void sortedChain<K, E>::erase(const K& theKey)
{// 如果存在, 删除关键字为theKey的键值对
    pairNode<K, E>* p = firstNode;
    pairNode<K, E>* tp = NULL;

    // 如果存在, tp为theKey前一个结点, p为theKey结点
    while (p != NULL && p->element.first < theKey)
    {
        tp = p;
        p = p->next;
    }

    if (p != NULL && p->element.first == theKey)
    {
        if (tp == NULL) firstNode = p->next;
        else tp->next = p->next;

        delete p;
        dSize--;
    }
}
template<class K, class E>
void sortedChain<K, E>::output()
{
    pairNode<K, E>* p = firstNode;
    while (p != NULL)
    {
        cout << p->element.first << " " << p->element.second << " ";
        cout << endl;
        p = p->next;
    }
}