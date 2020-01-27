#include "IntegerArrayQueue.h"

using namespace std;

int main(void)	{

	IntegerArrayQueue queue;
	queue.enqueue(1);

	queue.enqueue(4);

	queue.enqueue(9);

	queue.enqueue(16);

	queue.dequeue();

	queue.enqueue(25);

	queue.enqueue(36);

	queue.enqueue(49);

	queue.enqueue(64);

	queue.dequeue();
	queue.printArrayQueue();
	return 0;
}
