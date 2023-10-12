#pragma once
#include "maxPriorityQueue.h"
#include "linkedBinaryTree.hpp"
#include "arrayQueue.hpp"
#include "binaryTreeNode.h"
#include <sstream>

using namespace std;
template<class T>
class maxHblt : public maxPriorityQueue<T>, public linkedBinaryTree<pair<int, T>>
{
private:
    void merged(binaryTreeNode<pair<int, T> >*&, binaryTreeNode<pair<int, T> >*&);
public:
    bool empty() const { return this->treeSize == 0; }
    int size() const { return this->treeSize; }
    const T& top()
    {
        if (this->treeSize == 0)
            return NULL;
        return this->treeSize;
    }
    void pop();
    void push(const T&);
    void initialize(T*, int);
    void merged(maxHblt<T>& theHblt)
    {// �ϲ�����������
        merged(this->root, theHblt.root);
        this->treeSize += theHblt.treeSize;
        theHblt.root = NULL;
        theHblt.treeSize = 0;
    }
    void output();
};

template<class T>
void maxHblt<T>::merged(binaryTreeNode<pair<int, T> >*& x, binaryTreeNode<pair<int, T> >*& y)
{// �ϲ����������, x���Լ��ĸ��ڵ��ַ, y�Ǵ���ĸ��ڵ��ַ
    if (y == NULL)   // ����������Ϊ��, ����Ҫ����
        return;
    if (x == NULL)   // ���x�ڵ�Ϊ��, ��ֱ���øýڵ��ֵ���ڴ���ڵ��ֵ
    {
        x = y; return;
    }

    // ά���ѵ�����, ��֤ x �Ǹ������һ��
    if (x->element.second < y->element.second)
        swap(x, y);

    // ���������еݹ�, x �����Һ����ƶ�һλ
    merged(x->rightChild, y);

    // ����ǻ��ݵĹ���, ��Ҫά�������������, ��֤���ӵ�·�����ȴ����Һ���
    if (x->leftChild == NULL)
    {// ����Ϊ��ֱ�ӽ�������
        x->leftChild = x->rightChild;
        x->rightChild = NULL;
        x->element.first = 1;
    }
    else
    {// ������Ϊ����Ա����ǵ�·������
        if (x->leftChild->element.first < x->rightChild->element.first)
            swap(x->leftChild, x->rightChild);
        // ������·������
        x->element.first = x->rightChild->element.first + 1;
    }
}

template<class T>
void maxHblt<T>::push(const T& theElement)
{// Insert theElement into the leftist tree.
 // Create tree with one node.
    binaryTreeNode<pair<int, T> >* q =
        new binaryTreeNode<pair<int, T> >(pair<int, T>(1, theElement));

    // meld q and original tree
    merged(this->root, q);
    this->treeSize++;
}

template<class T>
void maxHblt<T>::pop()
{// Delete max element.
    if (this->root == NULL)
        return;

    // tree not empty
    binaryTreeNode<pair<int, T> >* left = this->root->leftChild,
        * right = this->root->rightChild;
    delete this->root;
    this->root = left;
    merged(this->root, right);
    this->treeSize--;
}

template<class T>
void maxHblt<T>::initialize(T* theElements, int theSize)
{// ���ݸ����������ʼ�������
    arrayQueue<binaryTreeNode<pair<int, T> >*> q(theSize);

    // ��ʼ�����Ķ���
    for (int i = 1; i <= theSize; i++)
        // ����һ��ֻ��һ���ڵ�����������
        q.push(new binaryTreeNode<pair<int, T> >
            (pair<int, T>(1, theElements[i])));

    // �Ӷ������ظ�ȡ�������кϲ�����
    for (int i = 1; i <= theSize - 1; i++)
    {// �Ӷ�����ȡ��2����
        binaryTreeNode<pair<int, T> >* b = q.front();
        q.pop();
        binaryTreeNode<pair<int, T> >* c = q.front();
        q.pop();
        merged(b, c);
        // �Ѻϲ�������������
        q.push(b);
    }

    if (theSize > 0)
        this->root = q.front();
    this->treeSize = theSize;
}

template<class T>
void maxHblt<T>::output()
{
    linkedBinaryTree<pair<int, T>>::levelOrder();
}