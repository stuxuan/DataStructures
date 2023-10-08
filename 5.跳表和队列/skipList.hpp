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
    float cutOff;                           // ����ȷ������
    int level() const;                      // ��������������ڵ��ڵڼ�������
    int levels;                             // ��ǰ���ķǿ�����
    int dSize;                              // ��ֵ�Ը���
    int maxLevel;                           // ���������������
    K tailKey;                              // ���ؼ���
    skipNode<K, E>* search(const K&) const; // ����Key���ҽڵ�
    skipNode<K, E>* headerNode;             // ͷ�ڵ�ָ�루ÿһ����ͷ�ڵ�)
    skipNode<K, E>* tailNode;               // β�ڵ�ָ�루ÿһ����β�ڵ�)
    skipNode<K, E>** last;                  // last[i] ��ʾ�� i ������һ�����

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
{// ���캯��, �ؼ���С��largeKey, �Ҹ������ΪmaxPairs, ��������(0, 1)
    cutOff = prob * RAND_MAX;
    maxLevel = (int)ceil(logf((float)maxPairs) / logf(1 / prob)) - 1;
    levels = 0;  // ��ʼ������
    dSize = 0;
    tailKey = largeKey;

    // ����ͷ���β��������last
    pair<K, E> tailPair;
    tailPair.first = tailKey;
    headerNode = new skipNode<K, E>(tailPair, maxLevel + 1);
    tailNode = new skipNode<K, E>(tailPair, 0);
    last = new skipNode<K, E> *[maxLevel + 1];

    // ����Ϊ��ʱ, ����ͷ�ڵ㶼ָ��β�ڵ�
    for (int i = 0; i <= maxLevel; i++)
        headerNode->next[i] = tailNode;
}

template<class K, class E>
skipList<K, E>::~skipList()
{// ɾ�����нڵ��Լ�last����
    skipNode<K, E>* nextNode;

    // ���ݵ�0��ɾ�����нڵ�
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
{// ����ƥ��� ��ֵ��ָ�� �� NULL
    if (theKey >= tailKey)
        return NULL;

    // λ�� beforeNode �ǹؼ���Ϊ theKey �Ľڵ�֮ǰ���ұߵ�λ��
    skipNode<K, E>* beforeNode = headerNode;
    for (int i = levels; i >= 0; i--)                       // ���϶���: ���ϼ��������²���
        while (beforeNode->next[i]->element.first < theKey) // �������: �� i ����ָ������һֱ�����ƶ�
            beforeNode = beforeNode->next[i];

    if (beforeNode->next[0]->element.first == theKey)
        return &beforeNode->next[0]->element;

    return NULL;
}

template<class K, class E>
int skipList<K, E>::level() const
{// ����prob��1/2, ����������ǵڼ�������ĸ���, ��Խ�߸���Խ��, ��������ģ�㹻��ʱÿ�㶼������һ���1/2
    int lev = 0;
    while (rand() <= cutOff)    // ÿ��С�����ĸ��ʶ���1/2
        lev++;
    cout << "��λ�ڵ�" << lev << "������" << endl;
    return (lev <= maxLevel) ? lev : maxLevel;
}

template<class K, class E>
skipNode<K, E>* skipList<K, E>::search(const K& theKey) const
{// �����ؼ��� theKey, ��ÿһ��������Ҫ�鿴�����һ���ڵ�洢�� last ��
 // ���� theKey ��Ӧ�ļ�ֵ�ԣ�����еĻ�����insert�н������жϣ�
    skipNode<K, E>* beforeNode = headerNode;
    for (int i = levels; i >= 0; i--)
    {
        while (beforeNode->next[i]->element.first < theKey)
            beforeNode = beforeNode->next[i];
        last[i] = beforeNode;  // ��ÿһ��theKey��ǰһ����㶼�洢��last������
    }
    return beforeNode->next[0];
}

template<class K, class E>
void skipList<K, E>::insert(const pair<const K, E>& thePair)
{// �� thePair �����ֵ�, �򸲸����йؼ��ֵļ�ֵ��
    if (thePair.first >= tailKey)
    {
        cout << "�ؼ��ֹ���" << endl;
        return;
    }

    // �鿴�ؼ����Ƿ��Ѿ�����
    skipNode<K, E>* theNode = search(thePair.first);
    if (theNode->element.first == thePair.first)
    {   // �Ѿ���������¼�ֵ�Ե�ֵ
        theNode->element.second = thePair.second;
        return;
    }

    // ������������µļ�ֵ��
    int theLevel = level(); // �½ڵ�����ڼ�������
    // ������������̫����, ����ֻ��Ϊ��ǰ����ȼ�+1
    if (theLevel > levels)
    {
        theLevel = ++levels;
        last[theLevel] = headerNode;
    }

    skipNode<K, E>* newNode = new skipNode<K, E>(thePair, theLevel + 1);
    for (int i = 0; i <= theLevel; i++)
    {// ��ÿһ������ýڵ�
        newNode->next[i] = last[i]->next[i];
        last[i]->next[i] = newNode;
    }

    dSize++;
    return;
}

template<class K, class E>
void skipList<K, E>::erase(const K& theKey)
{// ɾ���ؼ���ΪtheKey������
    if (theKey >= tailKey)
        return;

    // �ж��Ƿ���ƥ��ļ�ֵ��
    skipNode<K, E>* theNode = search(theKey);
    if (theNode->element.first != theKey)
        return;

    // ������ɾ����ֵ��
    for (int i = 0; i <= levels && last[i]->next[i] == theNode; i++)
        last[i]->next[i] = theNode->next[i];
 
    // ���µ�����
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