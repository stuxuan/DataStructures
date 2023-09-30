#include"chain.hpp"

int main()
{
	Chain<int>* list_a = new Chain<int>(5);
	cout << "初始数组元素数量：" << list_a->size() << endl;
	list_a->insert(0, 0);
	list_a->insert(0, 1);
	list_a->insert(0, 2);
	list_a->insert(0, 3);
	list_a->insert(0, 4);
	list_a->insert(0, 5);
	list_a->insert(0, 6);
	list_a->insert(0, 7);
	cout << "输出当前数组元素：";
	list_a->output();
	cout << endl;
	cout << "根据元素'4', 获取序号位置：" << list_a->get(4) << endl;
	cout << "根据ID'5',   获取元素为：" << list_a->indexOf(5) << endl;
	cout << endl;
	list_a->erase(3);
	cout << "输出当前数组元素：";
	list_a->output();
}
