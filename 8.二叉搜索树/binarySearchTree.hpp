#pragma once
#include "bsTree.h"
#include "../6.二叉树/linkedBinaryTree.hpp"

using namespace std;

template<class K, class E>
class binarySearchTree : public bsTree<K, E>, public linkedBinaryTree<pair<const K, E> >
{
public:
    // 字典的方法
    bool empty() const { return treeSize == 0; }
    int size() const { return treeSize; }
    pair<const K, E>* find(const K& theKey) const;
    void insert(const pair<const K, E>& thePair);
    void erase(const K& theKey);

    // 给二叉搜索树的方法
    void ascend() { inOrderOutput(); }
};

template<class K, class E>
pair<const K, E>* binarySearchTree<K, E>::find(const K& theKey) const
{// 返回关键字时K的元素指针
   // 从根节点 p 开始搜索，寻找关键字为 theKey 的元素
    binaryTreeNode<pair<const K, E> >* p = root;
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
    binaryTreeNode<pair<const K, E> >* p = root;
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
    if (root != NULL) // 判断树是否是空
        if (thePair.first < pp->element.first)
            pp->leftChild = newNode;
        else
            pp->rightChild = newNode;
    else
        root = newNode; // 直接将节点作为根节点
    treeSize++;
}

template<class K, class E>
void binarySearchTree<K, E>::erase(const K& theKey)
{// 删除关键字为 theKey 的节点

    // 查找关键字为 theKey 的节点
    binaryTreeNode<pair<const K, E> >* p = root;    // p 是要删除的节点
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

    // 重新构建树
    if (p->leftChild != NULL && p->rightChild != NULL)
    {// 当 P 有两个孩子节点时的处理
       // 转化为空或只有一个孩子
        binaryTreeNode<pair<const K, E>>* s = p->leftChild; // s: 左孩子的最大值, 替换 p
        binaryTreeNode<pair<const K, E>>* ps = p;           // ps: s 的双亲
        while (s->rightChild != NULL)
        {
            ps = s;
            s = s->rightChild;
        }

        // 把最大的元素 s 移动到要删除的节点 p
        binaryTreeNode<pair<const K, E> >* q = new binaryTreeNode<pair<const K, E>> (s->element, p->leftChild, p->rightChild);

        if (pp == NULL) // 如果要删除的节点 p 没有双亲, 则根节点就是新的节点
            root = q;
        else if (p == pp->leftChild)    // 如果 p 是左孩子, 则更新pp的左孩子
            pp->leftChild = q;
        else   // 如果 p 是右孩子, 则更新pp的右孩子
            pp->rightChild = q;
        if (ps == p) pp = q;
        else pp = ps;
        delete p;
        p = s;
    }

    // 如果p只有一个孩子
    binaryTreeNode<pair<const K, E> >* c;
    if (p->leftChild != NULL)
        c = p->leftChild;
    else
        c = p->rightChild;

    // 如果p时根节点
    if (p == root)
        root = c;
    else
    {// p 是 pp 的左孩子还是右孩子
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