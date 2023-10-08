#pragma once
#include <iostream>
#include "hash.h"           // ��Kת��Ϊ�Ǹ�����
#include "dictionary.h"     // �ֵ�
#include "sortedChain.hpp"  // ˳�������ֵ�

using namespace std;

template<class K, class E>
class hashChains : public dictionary<K, E>
{
protected:
    sortedChain<K, E>* table;  // ɢ�б�
    myhash<K> hash;            // ��Kת��Ϊ�Ǹ�����
    int dSize;                 // Ԫ�ظ���
    int divisor;               // �ڵ����

public:
    hashChains(int theDivisor = 11)
    {
        divisor = theDivisor;
        dSize = 0;

        // ��ʼ��һ��˳�������ֵ��������Ϊɢ�б�
        table = new sortedChain<K, E>[divisor];
    }

    ~hashChains() { delete[] table; }

    bool empty() const { return dSize == 0; }
    int size() const { return dSize; }

    pair<const K, E>* find(const K& theKey) const
    {// ֻ��Ҫȷ����ʼͰ��λ��Ȼ�����˳�������ֵ�Ĳ��Ҽ���
        return table[hash(theKey) % divisor].find(theKey);
    }

    void insert(const pair<const K, E>& thePair)
    {
        int homeBucket = (int)hash(thePair.first) % divisor;    // ��ʼͰλ��
        int homeSize = table[homeBucket].size();                // ��ǰ��Ͱ��С
        table[homeBucket].insert(thePair);                      // ����thePair
        if (table[homeBucket].size() > homeSize)                // ���Ͱ��С�����ı�
            dSize++;                                            // �ֵ�Ԫ�ظ���++
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