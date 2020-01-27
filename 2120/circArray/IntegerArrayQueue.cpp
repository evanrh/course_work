#include "IntegerArrayQueue.h"

using namespace std;

bool IntegerArrayQueue::enqueue(int value)	{
	
	int temp = front;

	if(front == 0)
		temp = size;
	
	if( temp - back ==  2)
		return false;
	else if (back == size - 1)
		back = 0;
	else
		back++;
	
	array[back] = value;
	return true;

}

int IntegerArrayQueue::dequeue()	{
	
	if( array[front] == 0 )
		return 0;
	else if( front == size - 1)
		front = 0;
		
	int temp = array[front];
	array[front++] = 0;
	return temp;
}
