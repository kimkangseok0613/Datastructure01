#pragma once

#include <iostream>
#include <string>

// �迭 : ũ�Ⱑ �����Ǿ� �ִ�.
// �迭�� ���̸� �ٲ� �� �ִ� Ŭ������ ������.
// �迭�� ��ü���� : capacity
// ���� �迭�� ��� ������ �� : size
// push_back() => size++; ���� : capacity <= size -> �ִ� �뷮�� �÷��ش�.(�˰���)

template <typename T>
class MyVector
{
private:
	T* vec;			// ���Ҹ� ���� ���� �ּ�
	int size;		// vec�� ���� ����ִ� ũ��
	int capacity;	// �ִ�� ���� �� �ִ� ũ��
public:
	// ������ & �Ҹ���

	MyVector(int temp = 10)
	{
		vec = new T[temp];
		size = 0;
		capacity = temp;
	}
	~MyVector()
	{
		delete[] vec;
	}
	
	// ������ �����ε� [], ==, !=
	
	T& operator[](int index)	// �迭�� index�� �����ϴ� ��� ����
	{
		return vec[index];
	}
	bool operator==(MyVector& other)
	{
		if (size != other.size) // ���� �ڷᱸ���� ���� ����, other ���� ���� ��
			return false;		// �ٸ���.

		if (capacity != other.capacity)// custom : �ִ� �뷮���� �ٸ��� �ٸ������� �����Ѵ�.
			return false;

		for (int i = 0;i < size;i++)
		{
			if (vec[i] != other[i])
				return false;
		}
		return true;
	}

	bool operator!=(MyVector& other)
	{
		return !(*this == other);
	}

	// ���� �߰�, ����
	void ResizeVector(int newSize)	// ���ǻ��� : �迭�� ũ�Ⱑ �����ϴ� case�� Resize ���ش�.
	{
		// 1. ���� �Ҵ� : new Ű���� capacity ũ�⸸ŭ TŸ���� ������ �迭�� �����.

		T* newVec = new T[newSize];

		// 2. ���� ���� �迭�� ���� �迭�� �����Ѵ�.

		for (int i=0; i < size; i++)
		{
			newVec[i] = vec[i];
		}
		delete[] vec;
		vec = newVec;
	}

	void push_back(T data)
	{
		if (capacity <= size) // �ִ� ���뷮 <= ������ ũ��
		{
			capacity = capacity * 2;	// �ִ� ���뷮
			ResizeVector(capacity);		// ���� �迭 -> ���� ���� �迭 �ű�� �۾�
		}

		vec[size] = data; // vec[0] ~ vec[size] = data
		size++;
	}

	void pop_back()
	{
		size = size > 0 ? size - 1 : 0;	// ���� ������ 0���� ũ�� size - 1, 0���� �۰ų� ������ size = 0;
	}

	void Print()
	{
		std::cout << "----------------------------------------------------" << std::endl;
		for (int i = 0; i < size; i++)
		{
			std::cout << i + 1 << "��° �� ���" << vec[i] << std::endl;
		}
		std::cout << "----------------------------------------------------" << std::endl;
	}

	T* GetVector() { return vec; } // vec�� ���� �����Ҽ� �ִ� GetVector�Լ�

	int GetSize() { return size; } // ���� vec�� ���� ������ �����ϴ� �Լ�

	// ��������
	// �κ� �ý���, Room - Player, Add, Remove ������ �濡 ���� ���Դ�.
	// Player - Inventory - Item system
};