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
    binaryTreeNode<E>* root;          // ���ڵ�ָ��
    int treeSize;                     // ���ڵ����
public:
    // ���캯��
    linkedBinaryTree() { root = NULL; treeSize = 0; }
    // ��������
    ~linkedBinaryTree() { erase(); };
    // �������Ƿ�Ϊ��
    bool empty() const { return treeSize == 0; }
    // ��������С
    int size() const { return treeSize; }
    // ���ڵ�
    E* rootElement() const { return treeSize == 0 ? NULL : &root->element; }
    // ����������
    void makeTree(const E& element, linkedBinaryTree<E>& left, linkedBinaryTree<E>& right);
    // ǰ�����
    void preOrder() { m_preOrder(root); }
    void m_preOrder(binaryTreeNode<E>*);
    // �������
    void inOrder() { m_inOrder(root); }
    void m_inOrder(binaryTreeNode<E>*);
    // �������
    void postOrder() { m_postOrder(root); }
    void m_postOrder(binaryTreeNode<E>*);
    // �������
    void levelOrder() { m_levelOrder(root); }
    void m_levelOrder(binaryTreeNode<E>*);
    // �������
    int height() { return m_height(root); }
    int m_height(binaryTreeNode<E>*) const;
    // �ͷſռ�
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
{// ǰ�����
    if (p != NULL)
    {
        cout << p->element << " ";
        m_preOrder(p->leftChild);
        m_preOrder(p->rightChild);
    }
}


template<class E>
void linkedBinaryTree<E>::m_inOrder(binaryTreeNode<E>* p)
{// �������
    if (p != NULL)
    {
        m_inOrder(p->leftChild);
        cout << p->element << " ";
        m_inOrder(p->rightChild);
    }
}

template<class E>
void linkedBinaryTree<E>::m_postOrder(binaryTreeNode<E>* p)
{// �������
    if (p != NULL)
    {
        m_postOrder(p->leftChild);
        m_postOrder(p->rightChild);
        cout << p->element << " ";
    }
}

template <class E>
void linkedBinaryTree<E>::m_levelOrder(binaryTreeNode<E>* t)
{// �������
    queue<binaryTreeNode<E>*> q;
    while (t != NULL)
    {
        cout << t->element << " ";

        // �Ѻ��ӷ������
        if (t->leftChild != NULL)
            q.push(t->leftChild);
        if (t->rightChild != NULL)
            q.push(t->rightChild);

        // ��ȡ��һ��Ҫ���ʵĽڵ�
        if (q.size() == 0)
            return;
        t = q.front();
        q.pop();
    }
}

template <class E>
int linkedBinaryTree<E>::m_height(binaryTreeNode<E>* t) const
{// �������ĸ߶�
    if (t == NULL)
        return 0;                   // ����
    int hl = m_height(t->leftChild);  // ���
    int hr = m_height(t->rightChild); // �Ҳ�
    if (hl > hr)
        return ++hl;
    else
        return ++hr;
}

template<class E>
void linkedBinaryTree<E>::erase()
{// ɾ�����нڵ�
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