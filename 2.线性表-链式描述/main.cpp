#include"chain.hpp"

int main()
{
	Chain<int>* list_a = new Chain<int>(5);
	cout << "��ʼ����Ԫ��������" << list_a->size() << endl;
	list_a->insert(0, 0);
	list_a->insert(0, 1);
	list_a->insert(0, 2);
	list_a->insert(0, 3);
	list_a->insert(0, 4);
	list_a->insert(0, 5);
	list_a->insert(0, 6);
	list_a->insert(0, 7);
	cout << "�����ǰ����Ԫ�أ�";
	list_a->output();
	cout << endl;
	cout << "����Ԫ��'4', ��ȡ���λ�ã�" << list_a->get(4) << endl;
	cout << "����ID'5',   ��ȡԪ��Ϊ��" << list_a->indexOf(5) << endl;
	cout << endl;
	list_a->erase(3);
	cout << "�����ǰ����Ԫ�أ�";
	list_a->output();
}
