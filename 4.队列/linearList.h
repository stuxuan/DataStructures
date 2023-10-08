#pragma once
template <class T>
class LinearList
{
public:
	// ���Ա��Ƿ�Ϊ��
	virtual bool empty() const = 0;
	// ���Ա��С
	virtual int size() const = 0;
	// ����ID��ȡ���Ա�Ԫ��
	virtual T& get(int theIndex) const = 0;
	// ����Ԫ�ػ�ȡԪ�ض�ӦID
	virtual int indexOf(const T& theElement) const = 0;
	// ɾ��ID����Ԫ��
	virtual void erase(int theIndex) = 0;
	// ��ID������Ԫ��
	virtual void insert(int theIndex, const T& theElement) = 0;
	// ������Ա�
	virtual void output() = 0;
};