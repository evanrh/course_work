#include "doublyLinkedSwap.h"

using namespace std;

void swapWithNext( Node * p)	{

	// Check for p being a valid node in the list
	if( p->next == nullptr or p == nullptr);
	
	// Check for p being the head or tail of the list
	else if( !( p->next->next == nullptr or p->prev->prev == nullptr))	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		p->next = p->next->next;
		p->prev->next->next = p;
		p->prev = p->next->prev;
		p->next->prev = p;
	}
}
