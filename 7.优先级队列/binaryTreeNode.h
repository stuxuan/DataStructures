#pragma once
using namespace std;

template <class T>
struct binaryTreeNode
{
    T element;
    binaryTreeNode<T>* leftChild;   // ������
    binaryTreeNode<T>* rightChild;  // ������

    binaryTreeNode() { leftChild = rightChild = NULL; }
    binaryTreeNode(const T& theElement) :element(theElement)
    {
        leftChild = rightChild = NULL;
    }
    binaryTreeNode(const T& theElement,
        binaryTreeNode* theLeftChild, binaryTreeNode* theRightChild) :element(theElement)
    {
        leftChild = theLeftChild;
        rightChild = theRightChild;
    }
};