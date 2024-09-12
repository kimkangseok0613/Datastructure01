#include "lectures.h"
#include "DoubleLikedList.h"

void lecture3()
{
	DoubliyLinkedList dList;

	dList.PushFront("����1");
	dList.PushBack("����2");
	dList.Insert(1, "����1-2");
	dList.Insert(1, "����1-1");
	dList.RemoveFront();
	dList.RemoveBack();


	std::cout << dList.FrontValue() << std::endl;
	std::cout << dList.BackValue() << std::endl;

	dList.Print();
}