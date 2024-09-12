#include "LinkedList.h"

IntLikedList::IntLikedList()
{

}

IntLikedList::~IntLikedList()
{

}

void IntLikedList::PushFront(const int& _data)
{
	IntNode* pNewNode = new IntNode;
	pNewNode->value = _data;

	if (nullptr == pHead)	// Head가 가리키고 있는 포인터 null 비어있는 자료구조.
	{
		// Head 포인터를 새로운 노드로 변경해준다.
		pHead = pNewNode;
		pTail = pNewNode;
	}

	pNewNode->pNext = pHead;	// 새로운 노드의 next 주소를 head를 가리키도록 만들어라.
	pHead = pNewNode;			// 기존 head를 새로운 노드로 변경해라.

	++iCount;	// 자료구조에 들어있는 데이터의 총 갯수
}

void IntLikedList::PushBack(const int& _data)
{
	IntNode* pNewNode = new IntNode;
	pNewNode->value = _data;

	// 데이터가 처음 들어갈 때 조건
	if (nullptr == pTail)
	{
		pHead = pNewNode;
		pTail = pNewNode;
	}
	pTail->pNext = pNewNode;	// 새로운 노드의 next 주소를 head를 가리키도록 만들어라.
	pTail = pNewNode;

	++iCount;
}

void IntLikedList::RemoveFront()
{
	if (nullptr == pHead)	// bool IsEmpty()
	{
		std::cout << "데이터가 없습니다. 실행을 취소합니다." << std::endl;
		return;
	}

	IntNode* p01dNode = pHead;		// pHead 임시 데이터를 생성해준다.
	
	if (nullptr == p01dNode)
	{
		pHead = nullptr;
		pTail = nullptr;
	}
	pHead = p01dNode->pNext;		// pHead->pNext : head로 만든다.

}

void IntLikedList::RemoveBack()
{

}

void IntLikedList::FrontValue()
{
	std::cout << "현재 자료구조의 총 갯수 : " << iCount << "," << "첫번째 원소의 값 출력 : " << pHead->value << std::endl;
}

void IntLikedList::TailValue()
{
	std::cout << "현재 자료구조의 총 갯수 : " << iCount << "," << "마지막 원소의 값 출력 : " << pTail->value << std::endl;
}
