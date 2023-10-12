#pragma once
using namespace std;

template<class T>
class binaryTree
{
public:
    virtual ~binaryTree() {}
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    // 前序遍历
    virtual void preOrder() = 0;
    // 中序遍历
    virtual void inOrder() = 0;
    // 后序遍历
    virtual void postOrder() = 0;
    // 层次遍历
    virtual void levelOrder() = 0;
};