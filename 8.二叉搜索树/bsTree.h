#pragma once
#include "dictionary.h"

using namespace std;

template<class K, class E>
class bsTree : public dictionary<K, E>
{
public:
    // �������������
    virtual void ascend() = 0;
};