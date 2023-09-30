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
	// ջ�Ƿ�Ϊ��
	bool empty() const { return ArrayList<T>::empty(); }
	// ջ�Ĵ�С
	int size() const { return ArrayList<T>::size(); }
	// ջ��Ԫ��
	T& top() 
	{
		if (ArrayList<T>::empty())
			cout << "ջΪ��" << endl;
		else 
			return ArrayList<T>::get(ArrayList<T>::size() - 1);
	}
	// ��ջ
	void pop()
	{
		if (ArrayList<T>::empty())
			cout << "ջΪ��" << endl;
		else
		{
			cout << "��ջԪ��Ϊ��" << ArrayList<T>::get(ArrayList<T>::size() - 1) << endl;
			ArrayList<T>::erase(ArrayList<T>::size() - 1);
		}			
	}
	// ��ջ
	void push(const T& theElement)
	{
		ArrayList<T>::insert(ArrayList<T>::size(), theElement);
	}
};


