#include "lectures.h"
#include "LinkedList.h"

void lecture2()
{
	IntLikedList iList;

	iList.PushFront(10);
	iList.FrontValue();
	iList.PushFront(5);
	iList.FrontValue();

	iList.PushBack(7);
	iList.TailValue();
}
