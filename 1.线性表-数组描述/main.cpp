#include"arrayList.hpp"

int main()
{
	LinearList<int>* list_a = new ArrayList<int>(5);
	cout << "�����С��" << list_a->size() << endl;
	list_a->insert(0, 0);
	list_a->insert(0, 1);
	list_a->insert(0, 2);
	list_a->insert(0, 3);
	list_a->insert(0, 4);
	list_a->insert(0, 5);
	list_a->insert(0, 6);
	list_a->insert(0, 7);
	cout << "�Ƿ�Ϊ�գ�" << list_a->empty() << endl;
	cout << "����Ԫ�ػ�ȡλ�ã�" << list_a->get(4) << endl;
	cout << "����ID��ȡԪ�أ�" << list_a->indexOf(5) << endl;
	list_a->erase(3);
	cout << "�����С��" << list_a->size() << endl;
}
