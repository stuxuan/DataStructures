#pragma once
#include<iostream>
using namespace std;
template <class T>
struct ChainNode
{
	// ���ݳ�Ա
	T element;
	ChainNode<T>* next;

	// ����
	ChainNode() {}
	ChainNode(const T& element)
	{
		this->element = element;
	}
	ChainNode(const T& element, chainNode<T>* next)
	{
		this->element = element;
		this->next = next;
	}
	~ChainNode()
	{
		cout << "�ұ�������" << endl;
	}
};