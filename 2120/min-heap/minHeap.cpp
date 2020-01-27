
#include "minHeap.h"

// Construction of heap from vector
minHeap::minHeap(vector<int> data)	{

//	heap.assign(data.begin(),data.end());
	for(int i = data.size() - 1; i >= 0; i--)
		heap.push_back(data[i]);

	for(int i = heap.size() - 1; i >= 0; i--)
		siftDown(i);
		
}

void minHeap::insert(int value)	{

	heap.push_back(value);

	siftUp(heap.size() - 1);

}

int minHeap::removeMin()	{

	int output = heap[0];
	heap[0] = heap[heap.size() - 1];
	heap.pop_back();
	siftDown(0);
	
	return output;
}

void minHeap::siftUp(int pos)	{

	int parent = (pos - 1) / 2;

	if( heap[pos] < heap[parent] )	{

		this->swap(pos, parent);		
		siftUp(parent);
	}

}

void minHeap::siftDown(int pos)	{

	int swapPos = pos;
	unsigned int leftChild = 2 * pos + 1;
	unsigned int rightChild = 2 * pos + 2;
	
	if(leftChild < heap.size() && heap[swapPos] > heap[leftChild])
		swapPos = leftChild;
	if(rightChild < heap.size() && heap[swapPos] > heap[rightChild])
		swapPos = rightChild;


	if(pos != swapPos)	{
		

		this->swap(pos,swapPos);	
		siftDown(swapPos);
	}

}

void minHeap::swap(int i, int j)	{
	
	int temp = heap[i];
	heap[i] = heap[j];
	heap[j] = temp;
	/*heap[i] ^= heap[j];
	heap[j] ^= heap[i];
	heap[i] ^= heap[j];*/
}
