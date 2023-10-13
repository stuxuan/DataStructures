#pragma once
#include "bsTree.h"
#include "../6.二叉树/linkedBinaryTree.hpp"

using namespace std;

template<class K, class E>
class binarySearchTree : public bsTree<K, E>, public linkedBinaryTree<pair<const K, E> >
{
public:
    // 字典的方法
    bool empty() const { return this->treeSize == 0; }
    int size() const { return this->treeSize; }
    pair<const K, E>* find(const K& theKey) const;
    void insert(const pair<const K, E>& thePair);
    void erase(const K& theKey);

    // 给二叉搜索树的方法
    void ascend() { linkedBinaryTree<pair<const K, E>>inOrder(); }
};

template<class K, class E>
pair<const K, E>* binarySearchTree<K, E>::find(const K& theKey) const
{// 返回关键字时K的元素指针
   // 从根节点 p 开始搜索，寻找关键字为 theKey 的元素
    binaryTreeNode<pair<const K, E> >* p = this->root;
    while (p != NULL)
        // 检查元素
        if (theKey < p->element.first)
            p = p->leftChild;
        else
            if (theKey > p->element.first)
                p = p->rightChild;
            else // 找到匹配的元素
                return &p->element;

    // 未找到匹配的元素
    return NULL;
}

template<class K, class E>
void binarySearchTree<K, E>::insert(const pair<const K, E>& thePair)
{// 插入thePair节点，如果存在相同的Key则覆盖元素
    binaryTreeNode<pair<const K, E> >* p = this->root;
    binaryTreeNode<pair<const K, E> >* pp = NULL;

    // 如果循环结束未找到该元素, 则pp元素就是该元素的父节点
    while (p != NULL)
    {// 检查元素p
        pp = p;
        // 将p移动到它的孩子节点
        if (thePair.first < p->element.first)
            p = p->leftChild;
        else
            if (thePair.first > p->element.first)
                p = p->rightChild;
            else
            {// 如果有相同的key, 覆盖旧的值
                p->element.second = thePair.second;
                return;
            }
    }

    // 为thePair创建一个节点, 然后与pp连接
    binaryTreeNode<pair<const K, E> >* newNode = new binaryTreeNode<pair<const K, E> >(thePair);
    if (this->root != NULL) // 判断树是否是空
        if (thePair.first < pp->element.first)
            pp->leftChild = newNode;
        else
            pp->rightChild = newNode;
    else
        this->root = newNode; // 直接将节点作为根节点
    this->treeSize++;
}

template<class K, class E>
void binarySearchTree<K, E>::erase(const K& theKey)
{// 删除关键字为 theKey 的节点

    // 查找关键字为 theKey 的节点
    binaryTreeNode<pair<const K, E> >* p = this->root;    // p 是要删除的节点
    binaryTreeNode<pair<const K, E> >* pp = NULL;   // pp 是 p 的双亲
    while (p != NULL && p->element.first != theKey)
    {// p移动到它的孩子节点
        pp = p;
        if (theKey < p->element.first)
            p = p->leftChild;
        else
            p = p->rightChild;
    }
    if (p == NULL)
        return; // 未找到则直接结束

    // 找到一个 s 元素替换要删除的元素 p, 然后用元素 s 构建一棵树
    // 接下来转换为删除元素 s 的操作, s 只有左孩子或者没有孩子
    if (p->leftChild != NULL && p->rightChild != NULL)
    {
        binaryTreeNode<pair<const K, E>>* s = p->leftChild; // s: 在 p 的左孩子中找到最大的元素
        binaryTreeNode<pair<const K, E>>* ps = p;           // ps: s 的双亲
        while (s->rightChild != NULL)
        {
            ps = s;
            s = s->rightChild;
        }

        // 用元素 s 构建一棵树, 替代元素 p 的位置
        binaryTreeNode<pair<const K, E> >* q = new binaryTreeNode<pair<const K, E>> (s->element, p->leftChild, p->rightChild);

        // 如果要删除的没有双亲, 根节点就是 q, 否则把孩子节点更换为 q
        if (pp == NULL) { this->root = q; }
        else if (p == pp->leftChild) { pp->leftChild = q; }
        else { pp->rightChild = q; }

        // 如果 s 恰好是要删除元素 p 的下一个节点, 单独处理一下
        if (ps == p) { pp = q; }
        else { pp = ps; }

        // 释放元素 p 的空间, 把 p 的指针指向 s, 接下来的工作是删除 s
        delete p;
        p = s;
    }

    // 下面的情况: 元素 p 只有一个孩子或者没有孩子
    // 指针 c 指向了元素 p 的孩子或者 NULL
    binaryTreeNode<pair<const K, E> >* c;
    if (p->leftChild != NULL) { c = p->leftChild; }
    else if (p->leftChild != NULL) { c = p->rightChild; }
    else { c = NULL; }

    // 如果要删除的 p 是根节点
    if (p == this->root)
        this->root = c;
    else
    {// 否则将 pp 的孩子置为 p
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