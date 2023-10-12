#include"maxHeap.hpp"
#include"maxHblt.hpp"

int main()
{
	maxHeap<int>* heap = new maxHeap<int>(12);
	int a[] = { 1,5,6,2,7,8,8,12,3 };
	heap->initialize(a, 9);
	heap->output();
 
	maxHblt<int>* hblt = new maxHblt<int>();
	hblt->initialize(a, 9);

	cout << endl;
	hblt->output();

	return 0;
}