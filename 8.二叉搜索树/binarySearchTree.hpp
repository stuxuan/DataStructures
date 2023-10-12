#pragma once
#include "bsTree.h"
#include "../6.������/linkedBinaryTree.hpp"

using namespace std;

template<class K, class E>
class binarySearchTree : public bsTree<K, E>, public linkedBinaryTree<pair<const K, E> >
{
public:
    // �ֵ�ķ���
    bool empty() const { return treeSize == 0; }
    int size() const { return treeSize; }
    pair<const K, E>* find(const K& theKey) const;
    void insert(const pair<const K, E>& thePair);
    void erase(const K& theKey);

    // �������������ķ���
    void ascend() { inOrderOutput(); }
};

template<class K, class E>
pair<const K, E>* binarySearchTree<K, E>::find(const K& theKey) const
{// ���عؼ���ʱK��Ԫ��ָ��
   // �Ӹ��ڵ� p ��ʼ������Ѱ�ҹؼ���Ϊ theKey ��Ԫ��
    binaryTreeNode<pair<const K, E> >* p = root;
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
    binaryTreeNode<pair<const K, E> >* p = root;
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
    if (root != NULL) // �ж����Ƿ��ǿ�
        if (thePair.first < pp->element.first)
            pp->leftChild = newNode;
        else
            pp->rightChild = newNode;
    else
        root = newNode; // ֱ�ӽ��ڵ���Ϊ���ڵ�
    treeSize++;
}

template<class K, class E>
void binarySearchTree<K, E>::erase(const K& theKey)
{// ɾ���ؼ���Ϊ theKey �Ľڵ�

    // ���ҹؼ���Ϊ theKey �Ľڵ�
    binaryTreeNode<pair<const K, E> >* p = root;    // p ��Ҫɾ���Ľڵ�
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

    // ���¹�����
    if (p->leftChild != NULL && p->rightChild != NULL)
    {// �� P ���������ӽڵ�ʱ�Ĵ���
       // ת��Ϊ�ջ�ֻ��һ������
        binaryTreeNode<pair<const K, E>>* s = p->leftChild; // s: ���ӵ����ֵ, �滻 p
        binaryTreeNode<pair<const K, E>>* ps = p;           // ps: s ��˫��
        while (s->rightChild != NULL)
        {
            ps = s;
            s = s->rightChild;
        }

        // ������Ԫ�� s �ƶ���Ҫɾ���Ľڵ� p
        binaryTreeNode<pair<const K, E> >* q = new binaryTreeNode<pair<const K, E>> (s->element, p->leftChild, p->rightChild);

        if (pp == NULL) // ���Ҫɾ���Ľڵ� p û��˫��, ����ڵ�����µĽڵ�
            root = q;
        else if (p == pp->leftChild)    // ��� p ������, �����pp������
            pp->leftChild = q;
        else   // ��� p ���Һ���, �����pp���Һ���
            pp->rightChild = q;
        if (ps == p) pp = q;
        else pp = ps;
        delete p;
        p = s;
    }

    // ���pֻ��һ������
    binaryTreeNode<pair<const K, E> >* c;
    if (p->leftChild != NULL)
        c = p->leftChild;
    else
        c = p->rightChild;

    // ���pʱ���ڵ�
    if (p == root)
        root = c;
    else
    {// p �� pp �����ӻ����Һ���
        if (p == pp->leftChild)
            pp->leftChild = c;
        else pp->rightChild = c;
    }
    treeSize--;
    delete p;
}

// overload << for pair
template <class K, class E>
ostream& operator<<(ostream& out, const pair<K, E>& x)
{
    out << x.first << ' ' << x.second; return out;
}