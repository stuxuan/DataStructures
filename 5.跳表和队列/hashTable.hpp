#pragma once
#include <iostream>
#include "hash.h"

using namespace std;

template<class K, class E>
class hashTable
{
protected:
    int search(const K&) const;
    pair<const K, E>** table;  // ��ϣ��
    myhash<K> hash;            // ��Kת��Ϊ�Ǹ�����
    int dSize;                 // �ֵ�Ĵ�С
    int divisor;               // �ڵ����

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

    // ��������Ŀռ�
    table = new pair<const K, E>*[divisor];
    for (int i = 0; i < divisor; i++)
        table[i] = NULL;
}

template<class K, class E>
int hashTable<K, E>::search(const K& theKey) const
{// ���ҹؼ���Ϊ theKey �ļ�ֵ��, �������ƥ��ļ�ֵ���򷵻�����λ��, ����������򷵻ؿ��Բ����λ��

    int i = (int)hash(theKey) % divisor;  // ��ʼͰ
    int j = i;    // j ����ʼͰ��ʼ����
    do
    {
        if (table[j] == NULL || table[j]->first == theKey)
            return j;
        j = (j + 1) % divisor;  // j �ƶ�����һ��Ͱ
    } while (j != i);           // �ص���ʼͰλ��

    return j;  // ����
}

template<class K, class E>
pair<const K, E>* hashTable<K, E>::find(const K& theKey) const
{// ����ƥ���ָ���NULL

    int b = search(theKey);

    // �ջ��ߺ�Key����ȶ�˵��û��ƥ��ļ�ֵ��
    if (table[b] == NULL || table[b]->first != theKey)
        return NULL;

    return table[b];  // ƥ�䵽��ֵ��
}

template<class K, class E>
void hashTable<K, E>::insert(const pair<const K, E>& thePair)
{// ����thePair, ��������ͬ�������ֵ, ������ӡ��ʾ

    int b = search(thePair.first);

    if (table[b] == NULL)
    {
        // û��ƥ��ļ�ֵ�������
        table[b] = new pair<const K, E>(thePair);
        dSize++;
    }
    else
    {
        if (table[b]->first == thePair.first)
        {// ƥ��ļ�ֵ����������ֵ
            table[b]->second = thePair.second;
        }
        else // �����˵�����Ѿ���
            cout << "ɢ�б�����" << endl;
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