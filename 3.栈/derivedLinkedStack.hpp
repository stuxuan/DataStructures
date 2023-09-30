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
	// 栈是否为空
	bool empty() const { return Chain<T>::empty(); }
	// 栈的大小
	int size() const { return Chain<T>::size(); }
	// 栈顶元素
	T& top()
	{
		if (Chain<T>::empty())
			cout << "栈为空" << endl;
		else
			return Chain<T>::get(Chain<T>::listSize - 1);
	}
	// 出栈
	void pop() 
	{
		if (Chain<T>::empty())
			cout << "栈为空" << endl;
		else
		{ 
			cout << "出栈元素为：" << Chain<T>::get(Chain<T>::listSize - 1) << endl;
			Chain<T>::erase(Chain<T>::listSize - 1);
		}
	}
	// 入栈
	void push(const T& theElement)
	{
		Chain<T>::insert(Chain<T>::size(), theElement);
	}
};