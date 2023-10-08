#pragma once

template <class K, class E>
struct skipNode
{
    typedef pair<const K, E> pairType;
    pairType element;
    skipNode<K, E>** next;   // ָ������

    skipNode(const pairType& thePair, int size):element(thePair) 
    {
        next = new skipNode<K, E>*[size];
    }
};