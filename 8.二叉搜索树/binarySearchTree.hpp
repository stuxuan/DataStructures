#pragma once
#include "bsTree.h"
#include "../6.������/linkedBinaryTree.hpp"

using namespace std;

template<class K, class E>
class binarySearchTree : public bsTree<K, E>, public linkedBinaryTree<pair<const K, E> >
{
public:
    // �ֵ�ķ���
    bool empty() const { return this->treeSize == 0; }
    int size() const { return this->treeSize; }
    pair<const K, E>* find(const K& theKey) const;
    void insert(const pair<const K, E>& thePair);
    void erase(const K& theKey);

    // �������������ķ���
    void ascend() { linkedBinaryTree<pair<const K, E>>inOrder(); }
};

template<class K, class E>
pair<const K, E>* binarySearchTree<K, E>::find(const K& theKey) const
{// ���عؼ���ʱK��Ԫ��ָ��
   // �Ӹ��ڵ� p ��ʼ������Ѱ�ҹؼ���Ϊ theKey ��Ԫ��
    binaryTreeNode<pair<const K, E> >* p = this->root;
    while (p != NULL)
        // ���Ԫ��
        if (theKey < p->element.first)
            p = p->leftChild;
        else
            if (theKey > p->element.first)
                p = p->rightChild;
            else // �ҵ�ƥ���Ԫ��
                return &p->element;

    // δ�ҵ�ƥ���Ԫ��
    return NULL;
}

template<class K, class E>
void binarySearchTree<K, E>::insert(const pair<const K, E>& thePair)
{// ����thePair�ڵ㣬���������ͬ��Key�򸲸�Ԫ��
    binaryTreeNode<pair<const K, E> >* p = this->root;
    binaryTreeNode<pair<const K, E> >* pp = NULL;

    // ���ѭ������δ�ҵ���Ԫ��, ��ppԪ�ؾ��Ǹ�Ԫ�صĸ��ڵ�
    while (p != NULL)
    {// ���Ԫ��p
        pp = p;
        // ��p�ƶ������ĺ��ӽڵ�
        if (thePair.first < p->element.first)
            p = p->leftChild;
        else
            if (thePair.first > p->element.first)
                p = p->rightChild;
            else
            {// �������ͬ��key, ���Ǿɵ�ֵ
                p->element.second = thePair.second;
                return;
            }
    }

    // ΪthePair����һ���ڵ�, Ȼ����pp����
    binaryTreeNode<pair<const K, E> >* newNode = new binaryTreeNode<pair<const K, E> >(thePair);
    if (this->root != NULL) // �ж����Ƿ��ǿ�
        if (thePair.first < pp->element.first)
            pp->leftChild = newNode;
        else
            pp->rightChild = newNode;
    else
        this->root = newNode; // ֱ�ӽ��ڵ���Ϊ���ڵ�
    this->treeSize++;
}

template<class K, class E>
void binarySearchTree<K, E>::erase(const K& theKey)
{// ɾ���ؼ���Ϊ theKey �Ľڵ�

    // ���ҹؼ���Ϊ theKey �Ľڵ�
    binaryTreeNode<pair<const K, E> >* p = this->root;    // p ��Ҫɾ���Ľڵ�
    binaryTreeNode<pair<const K, E> >* pp = NULL;   // pp �� p ��˫��
    while (p != NULL && p->element.first != theKey)
    {// p�ƶ������ĺ��ӽڵ�
        pp = p;
        if (theKey < p->element.first)
            p = p->leftChild;
        else
            p = p->rightChild;
    }
    if (p == NULL)
        return; // δ�ҵ���ֱ�ӽ���

    // �ҵ�һ�� s Ԫ���滻Ҫɾ����Ԫ�� p, Ȼ����Ԫ�� s ����һ����
    // ������ת��Ϊɾ��Ԫ�� s �Ĳ���, s ֻ�����ӻ���û�к���
    if (p->leftChild != NULL && p->rightChild != NULL)
    {
        binaryTreeNode<pair<const K, E>>* s = p->leftChild; // s: �� p ���������ҵ�����Ԫ��
        binaryTreeNode<pair<const K, E>>* ps = p;           // ps: s ��˫��
        while (s->rightChild != NULL)
        {
            ps = s;
            s = s->rightChild;
        }

        // ��Ԫ�� s ����һ����, ���Ԫ�� p ��λ��
        binaryTreeNode<pair<const K, E> >* q = new binaryTreeNode<pair<const K, E>> (s->element, p->leftChild, p->rightChild);

        // ���Ҫɾ����û��˫��, ���ڵ���� q, ����Ѻ��ӽڵ����Ϊ q
        if (pp == NULL) { this->root = q; }
        else if (p == pp->leftChild) { pp->leftChild = q; }
        else { pp->rightChild = q; }

        // ��� s ǡ����Ҫɾ��Ԫ�� p ����һ���ڵ�, ��������һ��
        if (ps == p) { pp = q; }
        else { pp = ps; }

        // �ͷ�Ԫ�� p �Ŀռ�, �� p ��ָ��ָ�� s, �������Ĺ�����ɾ�� s
        delete p;
        p = s;
    }

    // ��������: Ԫ�� p ֻ��һ�����ӻ���û�к���
    // ָ�� c ָ����Ԫ�� p �ĺ��ӻ��� NULL
    binaryTreeNode<pair<const K, E> >* c;
    if (p->leftChild != NULL) { c = p->leftChild; }
    else if (p->leftChild != NULL) { c = p->rightChild; }
    else { c = NULL; }

    // ���Ҫɾ���� p �Ǹ��ڵ�
    if (p == this->root)
        this->root = c;
    else
    {// ���� pp �ĺ�����Ϊ p
        if (p == pp->leftChild)
            pp->leftChild = c;
        else pp->rightChild = c;
    }
    this->treeSize--;
    delete p;
}

// overload << for pair
template <class K, class E>
ostream& operator<<(ostream& out, const pair<K, E>& x)
{
    out << x.first << ' ' << x.second; return out;
}