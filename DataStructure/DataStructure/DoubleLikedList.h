#pragma once

#include <iostream>
#include <string>

using namespace std;

// ���� ���� ����Ʈ
// ���� ���� ����Ʈ�� ��� Ȯ��� ����. Node : value, next, prev
// ���� : ������ ���� ã�Ⱑ �� ��������.
// ���� : �޸� ������ ���� �� ����Ѵ�.
// 
// ���ڿ��� �����ϴ� ���

struct StringNode
{
	string value;
	StringNode* pNext;
	StringNode* pPrev;
};

class DoubliyLinkedList
{
private:
	StringNode* pHead;
	StringNode* pTail;
	int iCount;
public:
	DoubliyLinkedList() {}
	~DoubliyLinkedList() {}

	// �Է±��
	void PushFront(const string _data);	// Front
	void PushBack(const string _data);
	void Insert(int index, const string _data);

	// ��±��
	string FrontValue() { return pHead->value; }
	string BackValue(){ return pTail->value; }
	void Print();	// ù��° ������ -> ������ ������ ���

	// �������
	void RemoveFront();
	void RemoveBack();
	void RemoveAt(int index);
};