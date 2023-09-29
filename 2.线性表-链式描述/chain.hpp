#include"linearList.h"
#include"chianNode.h"
#include<iostream>
using namespace std;
template<class T>
class Chain :public LinearList<T>
{
protected:
	ChainNode<T>* firstNode;
	int listSize;
	void checkIndex(int theIndex) const;

public:
	Chain(int initialCapacity = 10);
	Chain(const Chain<T>&);
	~Chain();

	bool empty() const { return listSize == 0; };
	// ���Ա��С
	int size() const { return listSize; }
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

// ��ͨ�Ĺ��캯��
template<class T>
Chain<T>::Chain(int initialCapacity)
{
	if (initialCapacity < 1)
	{
		cout << "��ʼ�������ñ������0" << endl;
	}
	firstNode = NULL;
	listSize = 0;
}

// �������캯��
template<class T>
Chain<T>::Chain(const Chain<T>& theList)
{
	listSize = theList.listSize;
	if (listSize == 0)
	{
		firstNode = NULL;
		return;
	}
	ChainNode<T>* sourceNode = theList.firstNode;
	firstNode = new ChainNode<T>(sourceNode->element);
	sourceNode = sourceNode->next;
	ChainNode<T>* targetNode = firstNode;
	while (sourceNode != NULL)
	{
		targetNode->next = new ChainNode<T>(sourceNode->element);
		targetNode = targetNode->next;
		sourceNode = sourceNode->next;
	}
	targetNode->next = NULL;
}

// ��������
template<class T>
Chain<T>::~Chain()
{
	while (firstNode != NULL)
	{
		ChainNode<T>* nextNode = firstNode->next;
		delete firstNode;
		firstNode = nextNode;
	}
}

template<class T>
T& Chain<T>::get(int theIndex) const
{
	if (checkIndex(theIndex))
	{
		ChainNode<T>* currentNode = firstNode;
		for (int i = 0; i < theIndex; i++)
		{
			currentNode = currentNode->next;
		}
		return currentNode->element;
	}
}

template<class T>
int Chain<T>::indexOf(const T& theElement) const
{
	ChainNode<T>* currentNode = firstNode;
	int index = 0;
	while (currentNode->element != theElement && currentNode != NULL)
	{
		currentNode = currentNode->next;
		index++;
	}
	return currentNode == NULL ? -1 : index;
}

template<class T>
void Chain<T>::erase(int theIndex)
{
	if (checkIndex(theIndex))
	{
		ChainNode<T>* deleteNode;
		if (theIndex == 0)
		{
			deleteNode = firstNode;
			firstNode = firstNode->next;
		}
		else
		{
			ChainNode<T>* p = firstNode;
			for (int i = 0; i < theIndex; i++)
			{
				p = p->next;
			}
			deleteNode = p->next;
			p->next = p->next->next;
		}
		listSize--;
		delete deleteNode;
	}
}

template<class T>
void Chain<T>::insert(int theIndex, const T& theElement)
{
	if (checkIndex(theIndex))
	{
		if (theIndex == 0)
		{
			firstNode = new ChainNode<T>(theElement, firstNode);
		}
		else
		{
			ChainNode<T>* p = firstNode;
			for (int i = 0; i < theIndex - 1; i++)
			{
				p = p->next;
			}
			p->next = new ChainNode<T>(theElement, p->next);
		}
		listSize++;
	}
}


template<class T>
void Chain<T>::output()
{
	ChainNode<T>* currentNode = firstNode;
	while (currentNode != NULL)
	{
		cout << currentNode->element << "  ";
		currentNode = currentNode->next;
	}
	cout << endl;
}