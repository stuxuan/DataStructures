#include"sortedChain.hpp"
#include"skipList.hpp"
#include"hashTable.hpp"
#include"hashChains.hpp"
#include<iostream>
#include<string>
using namespace std;



int main()
{
	// ˳�������ֵ�
	cout << "---------˳�������ֵ����---------" << endl;
	sortedChain<char, string>* m_sortedChain = new sortedChain<char, string>();
	m_sortedChain->insert(pair<char, string>('h', "h hello world!"));
	m_sortedChain->insert(pair<char, string>('a', "a hello world!"));
	m_sortedChain->insert(pair<char, string>('b', "b hello world!"));
	m_sortedChain->insert(pair<char, string>('d', "d hello world!"));
	m_sortedChain->output();
	cout << endl;
	// ����
	cout << "-----------�����ֵ����-----------" << endl;
	skipList<char, string>* m_skipList = new skipList<char, string>('z');
	m_skipList->insert(pair<char, string>('a', "aa!"));
	m_skipList->insert(pair<char, string>('b', "bb!"));
	m_skipList->insert(pair<char, string>('c', "cc!"));
	m_skipList->insert(pair<char, string>('d', "dd!"));
	m_skipList->insert(pair<char, string>('e', "ee!"));
	m_skipList->insert(pair<char, string>('f', "ff!"));
	m_skipList->insert(pair<char, string>('g', "gg!"));
	m_skipList->insert(pair<char, string>('h', "hh!"));
	m_skipList->insert(pair<char, string>('i', "ii!"));
	m_skipList->insert(pair<char, string>('j', "jj!"));
	m_skipList->output();
	m_skipList->find('b');
	cout << endl;

	// ɢ�е�����ʵ��
	cout << "-----------����ɢ�в���-----------" << endl;
	hashTable<char, string>* m_hashTable = new hashTable<char, string>(5);
	m_hashTable->insert(pair<char, string>('a', "aa!"));
	m_hashTable->insert(pair<char, string>('b', "bb!"));
	m_hashTable->insert(pair<char, string>('c', "cc!"));
	m_hashTable->insert(pair<char, string>('d', "dd!"));
	m_hashTable->insert(pair<char, string>('e', "aaa!"));
	m_hashTable->insert(pair<char, string>('f', "bbb!"));
	m_hashTable->insert(pair<char, string>('g', "bbb!"));
	m_hashTable->output();

	// ɢ�е���ʽʵ��
	cout << "-----------��ʽɢ�в���-----------" << endl;
	hashChains<char, string>* m_hashChain = new hashChains<char, string>(5);
	m_hashChain->insert(pair<char, string>('a', "aa!"));
	m_hashChain->insert(pair<char, string>('b', "bb!"));
	m_hashChain->insert(pair<char, string>('c', "cc!"));
	m_hashChain->insert(pair<char, string>('d', "dd!"));
	m_hashChain->insert(pair<char, string>('e', "aaa!"));
	m_hashChain->insert(pair<char, string>('f', "bbb!"));
	m_hashChain->insert(pair<char, string>('g', "bbb!"));
	m_hashChain->output();

}