#include"linearList.h"
#include<iostream>
using namespace std;

template<class T>
class ArrayList :public LinearList<T>
{
protected:
	T* element;								// 线性表元素指针
	int arrayLength;						// 容量
	int listSize;							// 元素个数
	bool checkIndex(int theIndex) const;	// 检查索引是否有效
	void changeLength();					// 扩充数组长度

public:
	// 构造函数
	ArrayList(int initialCapacity = 10);
	// 拷贝构造函数
	ArrayList(const ArrayList<T>& theList);
	// 析构函数
	~ArrayList() 
	{
		delete[] element;
	}

	// 线性表是否为空
	bool empty() const { return listSize == 0; }

	// 线性表大小
	int size() const { return listSize; }

	// 线性表容量
	int capacity() const { return arrayLength; }

	// 根据ID获取线性表元素
	T& get(int theIndex) const;

	// 根据元素获取元素对应ID
	int indexOf(const T& theElement) const;

	// 删除ID处的元素
	void erase(int theIndex);

	// 在ID处插入元素
	void insert(int theIndex, const T& theElement);

	// 输出线性表
	void output();

};


// 构造函数
template<class T>
ArrayList<T>::ArrayList(int initialCapacity)
{
	if (initialCapacity < 1) 
	{
		cout << "初始化容量必须大于0" << endl;
		return;
	}
	this->arrayLength = initialCapacity;
	this->element = new T[arrayLength];
	listSize = 0;
}

// 复制构造函数
template<class T>
ArrayList<T>::ArrayList(const ArrayList<T>& theList)
{
	this->arrayLength = theList.arrayLength;
	this->listSize = theList.listSize;
	this->element = new T[arrayLength];
	copy(theList.element, theList.element + listSize, element);
}

// 越界, false 表示越界, true 表示没有越界
template<class T>
bool ArrayList<T>::checkIndex(int theIndex) const
{
	bool ret = !(theIndex < 0 || theIndex > listSize);
	return ret;
}


// 获取元素
template<class T>
T& ArrayList<T>::get(int theIndex) const
{
	if (checkIndex(theIndex))
	{
		return element[theIndex];
	}
}

// 根据元素获取ID
template<class T>
int ArrayList<T>::indexOf(const T& theElement) const
{
	int theIndex = (int)find(element, element + listSize, theElement);
	return theIndex == listSize ? -1 : (theIndex-(int)element)/sizeof(T);
}

// 删除ID处元素
template<class T>
void ArrayList<T>::erase(int theIndex)
{
	if (checkIndex(theIndex))
	{
		copy(element + theIndex + 1, element + listSize, element + theIndex);
		element[--listSize].~T();
	}
}

// 扩充数组长度
template<class T>
void ArrayList<T>::changeLength()
{
	T* temp = new T[arrayLength * 2];
	copy(element, element + arrayLength, temp);
	delete[] element;
	element = temp;
	arrayLength = 2 * arrayLength;
}


// 在ID处插入元素
template<class T>
void ArrayList<T>::insert(int theIndex, const T& theElement)
{
	if (!checkIndex(theIndex))
	{
		cout << "无效索引" << endl;
		return;
	}
	if (listSize == arrayLength)
	{
		changeLength();
	}
	copy_backward(element + theIndex, element + listSize, element + listSize + 1);
	element[theIndex] = theElement;
	listSize++;
}

// 输出线性表
template<class T>
void ArrayList<T>::output()
{
	for (int i = 0; i < listSize; i++)
	{
		cout << element[i] << " ";
	}
	cout << endl;
}