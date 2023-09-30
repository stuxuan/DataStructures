#pragma once
template<class T>
class Stack
{
public:
	// 析构函数
	virtual ~Stack() {}
	// 栈是否为空
	virtual bool empty() const = 0;
	// 栈的大小
	virtual int size() const = 0;
	// 栈顶元素
	virtual T& top() = 0;
	// 出栈
	virtual void pop() = 0;
	// 入栈
	virtual void push(const T& theElement) = 0;
};