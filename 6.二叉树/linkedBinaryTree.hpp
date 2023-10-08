#pragma once
#include<iostream>
#include"binaryTree.h"
#include"binaryTreeNode.h"
#include<queue>
using namespace std;

template<class E>
class linkedBinaryTree : public binaryTree<binaryTreeNode<E>>
{
protected:
    binaryTreeNode<E>* root;          // 根节点指针
    int treeSize;                     // 树节点个数
public:
    // 构造函数
    linkedBinaryTree() { root = NULL; treeSize = 0; }
    // 析构函数
    ~linkedBinaryTree() { erase(); };
    // 二叉树是否为空
    bool empty() const { return treeSize == 0; }
    // 二叉树大小
    int size() const { return treeSize; }
    // 根节点
    E* rootElement() const { return treeSize == 0 ? NULL : &root->element; }
    // 制作二叉树
    void makeTree(const E& element, linkedBinaryTree<E>& left, linkedBinaryTree<E>& right);
    // 前序遍历
    void preOrder() { m_preOrder(root); }
    void m_preOrder(binaryTreeNode<E>*);
    // 中序遍历
    void inOrder() { m_inOrder(root); }
    void m_inOrder(binaryTreeNode<E>*);
    // 后序遍历
    void postOrder() { m_postOrder(root); }
    void m_postOrder(binaryTreeNode<E>*);
    // 层序遍历
    void levelOrder() { m_levelOrder(root); }
    void m_levelOrder(binaryTreeNode<E>*);
    // 树的深度
    int height() { return m_height(root); }
    int m_height(binaryTreeNode<E>*) const;
    // 释放空间
    void erase();
};

template<class E>
void linkedBinaryTree<E>::makeTree(const E& element, linkedBinaryTree<E>& left, linkedBinaryTree<E>& right)
{
    root = new binaryTreeNode<E>(element, left.root, right.root);
    treeSize = left.treeSize + right.treeSize + 1;

    left.root = right.root = NULL;
    left.treeSize = right.treeSize = 0;
}

template<class E>
void linkedBinaryTree<E>::m_preOrder(binaryTreeNode<E>* p)
{// 前序遍历
    if (p != NULL)
    {
        cout << p->element << " ";
        m_preOrder(p->leftChild);
        m_preOrder(p->rightChild);
    }
}


template<class E>
void linkedBinaryTree<E>::m_inOrder(binaryTreeNode<E>* p)
{// 中序遍历
    if (p != NULL)
    {
        m_inOrder(p->leftChild);
        cout << p->element << " ";
        m_inOrder(p->rightChild);
    }
}

template<class E>
void linkedBinaryTree<E>::m_postOrder(binaryTreeNode<E>* p)
{// 后序遍历
    if (p != NULL)
    {
        m_postOrder(p->leftChild);
        m_postOrder(p->rightChild);
        cout << p->element << " ";
    }
}

template <class E>
void linkedBinaryTree<E>::m_levelOrder(binaryTreeNode<E>* t)
{// 层序遍历
    queue<binaryTreeNode<E>*> q;
    while (t != NULL)
    {
        cout << t->element << " ";

        // 把孩子放入队列
        if (t->leftChild != NULL)
            q.push(t->leftChild);
        if (t->rightChild != NULL)
            q.push(t->rightChild);

        // 获取下一个要访问的节点
        if (q.size() == 0)
            return;
        t = q.front();
        q.pop();
    }
}

template <class E>
int linkedBinaryTree<E>::m_height(binaryTreeNode<E>* t) const
{// 返回树的高度
    if (t == NULL)
        return 0;                   // 空树
    int hl = m_height(t->leftChild);  // 左侧
    int hr = m_height(t->rightChild); // 右侧
    if (hl > hr)
        return ++hl;
    else
        return ++hr;
}

template<class E>
void linkedBinaryTree<E>::erase()
{// 删除所有节点
    binaryTreeNode<E>* p = root;
    if (p != NULL)
    {
        m_postOrder(p->leftChild);
        m_postOrder(p->rightChild);
        delete p;
    }
    root = NULL;
    treeSize = 0;
}