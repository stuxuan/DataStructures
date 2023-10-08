#pragma once
#include <iostream>
#include <string>

using namespace std;

// 把 Key 转换成非负整数
template<class K> class myhash;
template<>
class myhash<string>
{
public:
    size_t operator()(const string theKey) const
    {
        unsigned long hashValue = 0;
        int length = (int)theKey.length();
        for (int i = 0; i < length; i++)
            hashValue = 5 * hashValue + theKey.at(i);

        return size_t(hashValue);
    }
};

template<>
class myhash<int>
{
public:
    size_t operator()(const int theKey) const
    {
        return size_t(theKey);
    }
};

template<>
class myhash<char>
{
public:
    size_t operator()(const char theKey) const
    {
        int ret = (int)theKey;
        return size_t(ret);
    }
};