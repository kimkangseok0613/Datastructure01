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

	if (nullptr == pHead)	// Head�� ����Ű�� �ִ� ������ null ����ִ� �ڷᱸ��.
	{
		// Head �����͸� ���ο� ���� �������ش�.
		pHead = pNewNode;
		pTail = pNewNode;
	}

	pNewNode->pNext = pHead;	// ���ο� ����� next �ּҸ� head�� ����Ű���� ������.
	pHead = pNewNode;			// ���� head�� ���ο� ���� �����ض�.

	++iCount;	// �ڷᱸ���� ����ִ� �������� �� ����
}

void IntLikedList::PushBack(const int& _data)
{
	IntNode* pNewNode = new IntNode;
	pNewNode->value = _data;

	// �����Ͱ� ó�� �� �� ����
	if (nullptr == pTail)
	{
		pHead = pNewNode;
		pTail = pNewNode;
	}
	pTail->pNext = pNewNode;	// ���ο� ����� next �ּҸ� head�� ����Ű���� ������.
	pTail = pNewNode;

	++iCount;
}

void IntLikedList::RemoveFront()
{
	if (nullptr == pHead)	// bool IsEmpty()
	{
		std::cout << "�����Ͱ� �����ϴ�. ������ ����մϴ�." << std::endl;
		return;
	}

	IntNode* p01dNode = pHead;		// pHead �ӽ� �����͸� �������ش�.
	
	if (nullptr == p01dNode)
	{
		pHead = nullptr;
		pTail = nullptr;
	}
	pHead = p01dNode->pNext;		// pHead->pNext : head�� �����.

}

void IntLikedList::RemoveBack()
{

}

void IntLikedList::FrontValue()
{
	std::cout << "���� �ڷᱸ���� �� ���� : " << iCount << "," << "ù��° ������ �� ��� : " << pHead->value << std::endl;
}

void IntLikedList::TailValue()
{
	std::cout << "���� �ڷᱸ���� �� ���� : " << iCount << "," << "������ ������ �� ��� : " << pTail->value << std::endl;
}
