#pragma once
using namespace std;

template<class T>
class binaryTree
{
public:
    virtual ~binaryTree() {}
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    // ǰ�����
    virtual void preOrder() = 0;
    // �������
    virtual void inOrder() = 0;
    // �������
    virtual void postOrder() = 0;
    // ��α���
    virtual void levelOrder() = 0;
};