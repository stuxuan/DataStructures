#pragma once
#include"stack.h"
#include"arrayList.hpp"
#include<iostream>
using namespace std;
template<class T>
class DerivedArrayStack :private ArrayList<T>, public Stack<T>
{
public:
	DerivedArrayStack(int initialCapacity = 10) :ArrayList<T>(initialCapacity) {}
	// 栈是否为空
	bool empty() const { return ArrayList<T>::empty(); }
	// 栈的大小
	int size() const { return ArrayList<T>::size(); }
	// 栈顶元素
	T& top() 
	{
		if (ArrayList<T>::empty())
			cout << "栈为空" << endl;
		else 
			return ArrayList<T>::get(ArrayList<T>::size() - 1);
	}
	// 出栈
	void pop()
	{
		if (ArrayList<T>::empty())
			cout << "栈为空" << endl;
		else
		{
			cout << "出栈元素为：" << ArrayList<T>::get(ArrayList<T>::size() - 1) << endl;
			ArrayList<T>::erase(ArrayList<T>::size() - 1);
		}			
	}
	// 入栈
	void push(const T& theElement)
	{
		ArrayList<T>::insert(ArrayList<T>::size(), theElement);
	}
};


