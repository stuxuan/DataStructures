#pragma once
#include<iostream>
using namespace std;
template <class T>
struct ChainNode
{
	// 数据成员
	T element;
	ChainNode<T>* next;

	// 方法
	ChainNode() {}
	ChainNode(const T& element)
	{
		this->element = element;
	}
	ChainNode(const T& element, ChainNode<T>* next)
	{
		this->element = element;
		this->next = next;
	}
};