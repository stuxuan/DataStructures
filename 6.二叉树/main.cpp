#include <iostream>
#include "linkedBinaryTree.hpp"
using namespace std;
int main(void)
{
	linkedBinaryTree<int> a, x, y, z;
	y.makeTree(1, a, a);	// y: a 1 a					         4
	z.makeTree(2, a, a);	// z: a 2 a				      3           null
	x.makeTree(3, y, z);	// x: y 3 z				 1	        2
	y.makeTree(4, x, a);	// y: x 4 a			 null null  null null
	cout << "节点个数 = ";
	cout << y.size() << endl;
	cout << "高度 = ";
	cout << y.height() << endl;
	cout << "前序遍历 ";
	y.preOrder();
	cout << endl;
	cout << "中序遍历 ";
	y.inOrder();
	cout << endl;
	cout << "后序遍历 ";
	y.postOrder();
	cout << endl;
	cout << "层序遍历 ";
	y.levelOrder();
	cout << endl;

	return 0;
}
