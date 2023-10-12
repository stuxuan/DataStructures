// abstract class dictionary
// abstract data type specification for dictionary data structure
// all methods are pure virtual functions
// K is key type and E is value type

#pragma once
using namespace std;

template<class K, class E>
class dictionary
{
public:
    virtual ~dictionary() {}
    // �����Ƿ�Ϊ��
    virtual bool empty() const = 0;
    // �����ֵ���Ԫ�ظ���
    virtual int size() const = 0;
    // ���عؼ���ΪK��ֵ
    virtual pair<const K, E>* find(const K&) const = 0;
    // ��չؼ���ΪK��Ԫ��
    virtual void erase(const K&) = 0;
    // ����һ����ֵ��
    virtual void insert(const pair<const K, E>&) = 0;
};

