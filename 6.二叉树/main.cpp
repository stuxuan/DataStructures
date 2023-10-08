#include <iostream>
#include "linkedBinaryTree.hpp"

using namespace std;

int main(void)
{
	linkedBinaryTree<int> a, x, y, z;
	y.makeTree(1, a, a);
	z.makeTree(2, a, a);
	x.makeTree(3, y, z);
	y.makeTree(4, x, a);
	cout << "Number of nodes = ";
	cout << y.size() << endl;
	cout << "height = ";
	cout << y.height() << endl;
	cout << endl;
	cout << "ǰ����� ";
	y.preOrder();
	cout << endl;
	cout << "������� ";
	y.inOrder();
	cout << endl;
	cout << "������� ";
	y.postOrder();
	cout << endl;
	cout << "������� ";
	y.levelOrder();
	cout << endl;

	return 0;
}
