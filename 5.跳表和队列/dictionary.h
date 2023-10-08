#pragma once
using namespace std;

template<class K, class E>
class dictionary
{
public:
    virtual ~dictionary() {}
    // �����ֵ��Ƿ�Ϊ��
    virtual bool empty() const = 0;
    // �����ж��ټ�ֵ��
    virtual int size() const = 0;
    // ����K����E
    virtual pair<const K, E>* find(const K&) const = 0;
    // ����Kɾ����ֵ��
    virtual void erase(const K&) = 0;
    // ����һ����ֵ��
    virtual void insert(const pair<const K, E>&) = 0;
};

