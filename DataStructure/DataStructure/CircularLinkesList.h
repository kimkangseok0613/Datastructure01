#pragma once

// ���� ���� ����Ʈ ��ġ�մϴ�.
// tail�� next - nullptr;
// ���� ���� ����Ʈ : ������ next -> head
// 
// ���� ���� ����Ʈ
// ��尡 �װ� ��
// ���� ���� ���� ����Ʈ
// 
// ���� ����Ʈ�� ��� ����
// Head�� ���� �������� �ʾƵ� �ȴ�. - ��� ��尡 �������� �� �� �ִ�.
// 
// ���� ���� ����Ʈ�� head : head - prev : nullptr; �ڷᱸ������ ó�� �Է��ϴ� ������
// ���� ���� ����Ʈ ������ : 0, 1, 2, 3, 4, 5
// ���� ���� ����Ʈ�� �������� �ľ��ϴ� �Լ� : ó�� ������ head �ڷᱸ���� ������ �� ������ ���ش�. �������� �Ȱ��� ��尡 ���� �� : �ѹ����� ���Ҵ�.

struct cNode
{
	int value;
	cNode* next;
};

class CircularLinkedList
{
private:
	cNode* pHead;	// ������
	int iCount;

public:
	int IsEnd()
	{
		cNode* cur = pHead;
		int  iCount = 0;
		while (true)
		{
			iCount++;
			cur = cur->next;

			if (cur == pHead)
			{
				return;
			}
			return iCount;
		}
	}
};