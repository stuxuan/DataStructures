#include"derivedArrayStack.hpp"
#include"derivedLinkedStack.hpp"

int main()
{
	DerivedArrayStack<char>* arrayStack = new DerivedArrayStack<char>(5);
	arrayStack->push('5');
	arrayStack->push('4');
	arrayStack->push('3');
	arrayStack->push('2');
	arrayStack->push('1');
	arrayStack->push('0');
	arrayStack->pop();
	arrayStack->pop();
	arrayStack->pop();
	arrayStack->pop();
	arrayStack->pop();
	arrayStack->pop();
	arrayStack->pop();

	DerivedLinkedStack<char>* linkedstack = new DerivedLinkedStack<char>(5);
	linkedstack->push('5');
	linkedstack->push('4');
	linkedstack->push('3');
	linkedstack->push('2');
	linkedstack->push('1');
	linkedstack->push('0');
	linkedstack->pop();
	linkedstack->pop();
	linkedstack->pop();
	linkedstack->pop();
	linkedstack->pop();
	linkedstack->pop();
	linkedstack->pop();
}
