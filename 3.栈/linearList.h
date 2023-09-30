#pragma once
template <class T>
class LinearList
{
public:
	// 线性表是否为空
	virtual bool empty() const = 0;
	// 线性表大小
	virtual int size() const = 0;
	// 根据ID获取线性表元素
	virtual T& get(int theIndex) const = 0;
	// 根据元素获取元素对应ID
	virtual int indexOf(const T& theElement) const = 0;
	// 删除ID处的元素
	virtual void erase(int theIndex) = 0;
	// 在ID处插入元素
	virtual void insert(int theIndex, const T& theElement) = 0;
	// 输出线性表
	virtual void output() = 0;
};