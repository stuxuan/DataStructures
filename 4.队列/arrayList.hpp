#include"linearList.h"
#include<iostream>
using namespace std;

template<class T>
class arrayList :public LinearList<T>
{
protected:
	T* element;								// ���Ա�Ԫ��ָ��
	int arrayLength;						// ����
	int listSize;							// Ԫ�ظ���
	bool checkIndex(int theIndex) const;	// ��������Ƿ���Ч
	void changeLength();					// �������鳤��

public:
	// ���캯��
	arrayList(int initialCapacity = 10);
	// �������캯��
	arrayList(const arrayList<T>& theList);
	// ��������
	~arrayList()
	{
		delete[] element;
	}

	// ���Ա��Ƿ�Ϊ��
	bool empty() const { return listSize == 0; }

	// ���Ա��С
	int size() const { return listSize; }

	// ���Ա�����
	int capacity() const { return arrayLength; }

	// ����ID��ȡ���Ա�Ԫ��
	T& get(int theIndex) const;

	// ����Ԫ�ػ�ȡԪ�ض�ӦID
	int indexOf(const T& theElement) const;

	// ɾ��ID����Ԫ��
	void erase(int theIndex);

	// ��ID������Ԫ��
	void insert(int theIndex, const T& theElement);

	// ������Ա�
	void output();

};


// ���캯��
template<class T>
arrayList<T>::arrayList(int initialCapacity)
{
	if (initialCapacity < 1)
	{
		cout << "��ʼ�������������0" << endl;
		return;
	}
	this->arrayLength = initialCapacity;
	this->element = new T[arrayLength];
	listSize = 0;
}

// ���ƹ��캯��
template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
	this->arrayLength = theList.arrayLength;
	this->listSize = theList.listSize;
	this->element = new T[arrayLength];
	copy(theList.element, theList.element + listSize, element);
}

// Խ��, false ��ʾԽ��, true ��ʾû��Խ��
template<class T>
bool arrayList<T>::checkIndex(int theIndex) const
{
	bool ret = !(theIndex < 0 || theIndex > listSize);
	return ret;
}


// ��ȡԪ��
template<class T>
T& arrayList<T>::get(int theIndex) const
{
	if (checkIndex(theIndex))
	{
		return element[theIndex];
	}
}

// ����Ԫ�ػ�ȡID
template<class T>
int arrayList<T>::indexOf(const T& theElement) const
{
	int theIndex = (int)find(element, element + listSize, theElement);
	return theIndex == listSize ? -1 : (theIndex - (int)element) / sizeof(T);
}

// ɾ��ID��Ԫ��
template<class T>
void arrayList<T>::erase(int theIndex)
{
	if (checkIndex(theIndex))
	{
		copy(element + theIndex + 1, element + listSize, element + theIndex);
		element[--listSize].~T();
	}
}

// �������鳤��
template<class T>
void arrayList<T>::changeLength()
{
	T* temp = new T[arrayLength * 2];
	copy(element, element + arrayLength, temp);
	delete[] element;
	element = temp;
	arrayLength = 2 * arrayLength;
}


// ��ID������Ԫ��
template<class T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{
	if (!checkIndex(theIndex))
	{
		cout << "��Ч����" << endl;
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

// ������Ա�
template<class T>
void arrayList<T>::output()
{
	for (int i = 0; i < listSize; i++)
	{
		cout << element[i] << " ";
	}
	cout << endl;
}