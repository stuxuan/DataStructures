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
    {// 合并传入的左高树
        merged(this->root, theHblt.root);
        this->treeSize += theHblt.treeSize;
        theHblt.root = NULL;
        theHblt.treeSize = 0;
    }
    void output();
};

template<class T>
void maxHblt<T>::merged(binaryTreeNode<pair<int, T> >*& x, binaryTreeNode<pair<int, T> >*& y)
{// 合并两棵左高树, x是自己的根节点地址, y是传入的根节点地址
    if (y == NULL)   // 如果传入的树为空, 不需要操作
        return;
    if (x == NULL)   // 如果x节点为空, 则直接让该节点的值等于传入节点的值
    {
        x = y; return;
    }

    // 维护堆的性质, 保证 x 是更大的那一个
    if (x->element.second < y->element.second)
        swap(x, y);

    // 接下来进行递归, x 向其右孩子移动一位
    merged(x->rightChild, y);

    // 最后是回溯的过程, 需要维护左高树的性质, 保证左孩子的路径长度大于右孩子
    if (x->leftChild == NULL)
    {// 左树为空直接交换即可
        x->leftChild = x->rightChild;
        x->rightChild = NULL;
        x->element.first = 1;
    }
    else
    {// 左树不为空则对比他们的路径长度
        if (x->leftChild->element.first < x->rightChild->element.first)
            swap(x->leftChild, x->rightChild);
        // 最后更新路径长度
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
{// 根据给定的数组初始化左高树
    arrayQueue<binaryTreeNode<pair<int, T> >*> q(theSize);

    // 初始化树的队列
    for (int i = 1; i <= theSize; i++)
        // 建立一个只有一个节点的树插入队列
        q.push(new binaryTreeNode<pair<int, T> >
            (pair<int, T>(1, theElements[i])));

    // 从队列中重复取出树进行合并操作
    for (int i = 1; i <= theSize - 1; i++)
    {// 从队列中取出2个树
        binaryTreeNode<pair<int, T> >* b = q.front();
        q.pop();
        binaryTreeNode<pair<int, T> >* c = q.front();
        q.pop();
        merged(b, c);
        // 把合并后的树插入队列
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