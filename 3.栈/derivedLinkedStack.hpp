#pragma once
#include"chain.hpp"
#include"stack.h"
#include<iostream>
using namespace std;
template<class T>
class DerivedLinkedStack :private Chain<T>, public Stack<T>
{
public:
	DerivedLinkedStack(int initialCapacity = 10) :Chain<T>(initialCapacity) {}
	// ջ�Ƿ�Ϊ��
	bool empty() const { return Chain<T>::empty(); }
	// ջ�Ĵ�С
	int size() const { return Chain<T>::size(); }
	// ջ��Ԫ��
	T& top()
	{
		if (Chain<T>::empty())
			cout << "ջΪ��" << endl;
		else
			return Chain<T>::get(Chain<T>::listSize - 1);
	}
	// ��ջ
	void pop() 
	{
		if (Chain<T>::empty())
			cout << "ջΪ��" << endl;
		else
		{ 
			cout << "��ջԪ��Ϊ��" << Chain<T>::get(Chain<T>::listSize - 1) << endl;
			Chain<T>::erase(Chain<T>::listSize - 1);
		}
	}
	// ��ջ
	void push(const T& theElement)
	{
		Chain<T>::insert(Chain<T>::size(), theElement);
	}
};