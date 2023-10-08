#pragma once
#include <iostream>
#include "dictionary.h"
#include "pairNode.h"

using namespace std;

template<class K, class E>
class sortedChain : public dictionary<K, E>
{
protected:
    pairNode<K, E>* firstNode; // ��һ�����
    int dSize;                 // �ֵ�Ĵ�С

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
{// ����ƥ���ָ��, �������򷵻�NULL
    pairNode<K, E>* currentNode = firstNode;

    while (currentNode != NULL && currentNode->element.first != theKey)
        currentNode = currentNode->next;

    if (currentNode != NULL && currentNode->element.first == theKey)
        return &currentNode->element;

    return NULL;
}

template<class K, class E>
void sortedChain<K, E>::insert(const pair<const K, E>& thePair)
{// ���ֵ��в���һ����ֵ��, ���Ҹ����Ѿ����ڵļ�ֵ��
    pairNode<K, E>* p = firstNode;
    pairNode<K, E>* tp = NULL;

    while (p != NULL && p->element.first < thePair.first)
    {// ��ֹ��Ҫ����Ľ����tp��, p֮ǰ
        tp = p;
        p = p->next;
    }

    if (p != NULL && p->element.first == thePair.first)
    {// �����ƥ��ļ�ֵ��, �滻��ֵ
        p->element.second = thePair.second;
        return;
    }

    // ���û��ƥ��ļ�ֵ��, ����һ���µĽڵ�, �ýڵ����һ�����Ϊp
    pairNode<K, E>* newNode = new pairNode<K, E>(thePair, p);

    if (tp == NULL) firstNode = newNode;
    else tp->next = newNode;

    dSize++;
    return;
}

template<class K, class E>
void sortedChain<K, E>::erase(const K& theKey)
{// �������, ɾ���ؼ���ΪtheKey�ļ�ֵ��
    pairNode<K, E>* p = firstNode;
    pairNode<K, E>* tp = NULL;

    // �������, tpΪtheKeyǰһ�����, pΪtheKey���
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