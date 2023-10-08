#include<iostream>
#include"arrayQueue.hpp"

int main()
{
	arrayQueue<char>* queue1 = new arrayQueue<char>(4);
	queue1->push('a');
	queue1->push('b');
	queue1->push('c');
	queue1->push('d');
	queue1->pop();
	queue1->pop();
	queue1->pop();
	queue1->pop();
}