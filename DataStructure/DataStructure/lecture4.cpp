#include "lectures.h"
#include <iostream>
#include <list>
#include <string>

// ���� ����Ʈ - std::list template
// 
// ���� ������. ����, �߰� - �κ��丮
// �迭 - ���� ����Ʈ
// ���� : ������ ���� ������ ������.		<-> ������ ���� ������ �Ұ����ϴ�.
// �ܴ� : �������� ���� �� �߰��� ������.	<-> ������ ���� �� �߰��� ������.

class Item
{
private:
	int itemCode;
	std::string name;
public:
	Item(int _itemcode, std::string _name) :itemCode(_itemcode), name(_name) {}

	void ShowInfo()
	{
		std::cout << "������ �ڵ� : " << itemCode << std::endl;
		std::cout << "������ �̸� : " << name << std::endl;
	}
};

template<typename T>
class Node
{
	T value;
	Node* next;
};

template<typename T>
class LinkedList
{

};


void lecture4()
{
	std::cout << "STL : ���� ����Ʈ ���" << std::endl;
	
	// �����Ҵ� : std::list<int>* iList = new std::list<int>();

	// std::list<int> iList;	// Ŭ���� ����
	std::list<Item> inventory;

	// ������ �տ� ���� pushFront		- push_front
	// ������ �ڿ� ���� pushBack		- push_back
	// �տ� ������ ���� removeFront	- pop_front
	// �ڿ� ������ ���� removeBack	- pop_back

	Item* newItem = new Item(1001, "���");
	Item* newItem2 = new Item(1002, "�Ѽհ�");
	Item* newItem3 = new Item(1003, "�ظ�");
	inventory.push_front(*newItem);
	inventory.push_back(*newItem2);
	inventory.push_back(*newItem3);

	std::list<Item>::iterator iPos = inventory.begin();

	inventory.insert(iPos, 1, *newItem3);

	inventory.pop_back();

	// iterator : �����͸� �Ϲ�ȭ��Ų Ŭ����

	std::list<Item>::iterator iterEnd = inventory.end();

	for (std::list<Item>::iterator iterPos = inventory.begin(); iterPos != iterEnd; ++iterPos)
	{
		iterPos->ShowInfo();
	}




	// Ŭ���� ����

	// LinkedList.h - int, DoubliyLinkedList.h -string

	// LinkedList<int> iList1;
	// std::list<int> iList2;

	// DoubliyLinkedList dList1;
	// std::list<string> dList2;


	// ���� ����

	// ������ Ŭ������ ���Ǹ� �մϴ�.
	// A(50, 200) B(20, 80) C(75, 10) D(130, 80) E(100, 200)
	// class Pos( posX, posY )
	// Pos value�� ����, node�� ������

	Pos A = Pos(50, 200, 'A');
	Pos B = Pos(50, 200, 'B');
	Pos C = Pos(50, 200, 'C');
	Pos D = Pos(50, 200, 'D');
	Pos E = Pos(50, 200, 'E');

	// (1)
	std::list<Point> Star;

	Star.push_back(A);
	Star.push_back(B);
	Star.push_back(C);
	Star.push_back(D);
	Star.push_back(E);

	// (2)

	Point A_P = Point(A);
	Point B_P = Point(B);
	Point C_P = Point(C);
	Point D_P = Point(D);
	Point E_P = Point(E);

	A_P.next = &B_P;
	B_P.next = &C_P;
	C_P.next = &D_P;
	D_P.next = &E_P;
	E_P.next = &A_P;
}

class Pos
{
private:
	int posX;
	int posY;
	char tag;
public:
	Pos(int x, int y, char z) :posX(x), posY(y), tag(z) {}
};

class Point
{
	Pos data;
	Point* next;
public:
	Point(Pos _data) : data(_data) {}
};