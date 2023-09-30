#pragma once
template<class T>
class Stack
{
public:
	// ��������
	virtual ~Stack() {}
	// ջ�Ƿ�Ϊ��
	virtual bool empty() const = 0;
	// ջ�Ĵ�С
	virtual int size() const = 0;
	// ջ��Ԫ��
	virtual T& top() = 0;
	// ��ջ
	virtual void pop() = 0;
	// ��ջ
	virtual void push(const T& theElement) = 0;
};