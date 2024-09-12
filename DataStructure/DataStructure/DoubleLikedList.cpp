#include "DoubleLikedList.h"

void DoubliyLinkedList::PushFront(const string _data)
{
	StringNode* newNode = new StringNode;	// ���� �Ҵ����� Node ����. next, prev 
	newNode->value = _data;					// ���->value =  _data;
	newNode->pNext = nullptr;
	newNode->pPrev = nullptr;

	if (nullptr == pHead)	// head�� nullptr�� ��
	{
		pHead = newNode;
		pTail = newNode;
	}

	// �� �̿��� ��� - �� �տ� ��� ��带 ��ġ�ϰ�, ���� ��带 ���ο� ���� �����Ѵ�.
	newNode->pPrev = nullptr;	// ���ο� ����� prev ����־���Ѵ�.
	newNode->pNext = pHead;		// ���ο� ����� next ������ head�����Ѵ�.
	pHead = newNode;			// ���ο� �Ӹ��� ���ο� ���� �������ش�.

	iCount++;
}

void DoubliyLinkedList::PushBack(const string _data)
{
	StringNode* newNode = new StringNode;	// ���� �Ҵ����� Node ����. next, prev 
	newNode->value = _data;					// ���->value =  _data;
	newNode->pNext = nullptr;
	newNode->pPrev = nullptr;

	if (nullptr == pHead)	// head�� nullptr�� ��
	{
		pHead = newNode;
		pTail = newNode;
	}

	// �� �̿��� ��� - �� �տ� ��� ��带 ��ġ�ϰ�, ���� ��带 ���ο� ���� �����Ѵ�.
	newNode->pPrev = pTail;		// ���ο� ����� prev ������ tail.
	newNode->pNext = nullptr;	// ���ο� ����� next ����־���Ѵ�.
	pTail->pNext = newNode;		// ���ο� ��� ���� ����� ���� ��尡 newNode
	pTail = newNode;			// ���ο� ������ ���ο� ���� �������ش�.

	iCount++;
}

void DoubliyLinkedList::Insert(int index, const string _data)
{
	// iCount�� 0���� ������ iCount

	if (index < 0 || index >= iCount)
	{
		cout << "�ε��� ���� �߻�" << endl;
		return;
	}
	else if (index == 0) // index 0 (PushFront �Լ� ����)
	{
		PushFront(_data);
	}
	else if (index == iCount) // index iCount = 1 (PushBack �Լ� ����)
	{
		PushBack(_data);
	}
	else // Node -> NewNode -> Node
	{
		StringNode* newNode = new StringNode;
		newNode->value = _data;
		newNode->pNext = nullptr;
		newNode->pPrev = nullptr;

		StringNode* cur = pHead;	// �Ӹ�����	//StringNode* tail = pTail;	// ��������
		
		// index�� n�̶�� ����

		int i = 0;
		while (i < index - 1)
		{						//cur = pHead->pNext;
			cur = cur->pNext;	//cur = pHead->pNext->pNext;
			i++;				//newNode = pHead->pNext...n
		}

		newNode->pPrev = cur;		 // ���ο� ����� ���� : ���� ���
		newNode->pNext = cur->pNext; // ���ο� ����� ���� : ���� ����� next ���
		cur->pNext->pPrev = newNode; // ���� ����� ���� : ���ο� ���
		cur->pNext = newNode;		 // ���� ����� ���� ��尡 �⸮Ű�� �ִ� ���� : ���ο� ���
		
		iCount++;
	}
}

void DoubliyLinkedList::Print()
{
	StringNode* printNode = pHead;

	while (nullptr != printNode)
	{
		// printNode �������� ���� printNode->value
		if (printNode->pNext == nullptr)	// printNode->next nullptr
		{
			cout << printNode->value << endl;
		}
		else
		{
			cout << printNode->value << " " << "<->" << " ";
		}
		printNode = printNode->pNext;
	}
}

void DoubliyLinkedList::RemoveFront()
{
	if (pHead != nullptr)
	{
		StringNode* remove = pHead;

		// pHead->pNext null�̸� 1���� ����

		if (nullptr == remove->pNext)
		{
			pHead = pTail = nullptr;
		}
		else // �ƴҶ�
		{
			pHead = pHead->pNext;
			pHead->pPrev = nullptr;
			delete remove;
		}
	}
}

void DoubliyLinkedList::RemoveBack()
{
	if (pTail != nullptr)
	{
		StringNode* remove = pTail;

		// pHead->pNext null�̸� 1���� ����

		if (nullptr == remove->pNext)
		{
			pTail = pHead = nullptr;
		}
		else // �ƴҶ�
		{
			pTail = pTail->pNext;
			pTail->pPrev = nullptr;
			delete remove;
		}
	}
}

void DoubliyLinkedList::RemoveAt(int index)
{

}
