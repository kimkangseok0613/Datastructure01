#pragma once

#include <iostream>
#include <string>

// 배열 : 크기가 고정되어 있다.
// 배열의 길이를 바꿀 수 있는 클래스로 만들어보자.
// 배열의 전체길이 : capacity
// 현재 배열에 담긴 원소의 수 : size
// push_back() => size++; 조건 : capacity <= size -> 최대 용량을 늘려준다.(알고리즘)

template <typename T>
class MyVector
{
private:
	T* vec;			// 원소를 담을 시작 주소
	int size;		// vec에 현재 담겨있는 크기
	int capacity;	// 최대로 담을 수 있는 크기
public:
	// 생성자 & 소멸자

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
	
	// 연산자 오버로딩 [], ==, !=
	
	T& operator[](int index)	// 배열의 index에 접근하는 기능 구현
	{
		return vec[index];
	}
	bool operator==(MyVector& other)
	{
		if (size != other.size) // 현재 자료구조의 원소 갯수, other 원소 갯수 비교
			return false;		// 다르다.

		if (capacity != other.capacity)// custom : 최대 용량수가 다르면 다른것으로 간주한다.
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

	// 원소 추가, 삭제
	void ResizeVector(int newSize)	// 주의사항 : 배열의 크기가 증가하는 case만 Resize 해준다.
	{
		// 1. 동적 할당 : new 키워드 capacity 크기만큼 T타입의 데이터 배열을 만든다.

		T* newVec = new T[newSize];

		// 2. 새로 만든 배열에 기존 배열을 대입한다.

		for (int i=0; i < size; i++)
		{
			newVec[i] = vec[i];
		}
		delete[] vec;
		vec = newVec;
	}

	void push_back(T data)
	{
		if (capacity <= size) // 최대 수용량 <= 원소의 크기
		{
			capacity = capacity * 2;	// 최대 수용량
			ResizeVector(capacity);		// 기존 배열 -> 새로 만든 배열 옮기는 작업
		}

		vec[size] = data; // vec[0] ~ vec[size] = data
		size++;
	}

	void pop_back()
	{
		size = size > 0 ? size - 1 : 0;	// 현재 갯수가 0보다 크면 size - 1, 0보다 작거나 같으면 size = 0;
	}

	void Print()
	{
		std::cout << "----------------------------------------------------" << std::endl;
		for (int i = 0; i < size; i++)
		{
			std::cout << i + 1 << "번째 값 출력" << vec[i] << std::endl;
		}
		std::cout << "----------------------------------------------------" << std::endl;
	}

	T* GetVector() { return vec; } // vec에 직접 접근할수 있는 GetVector함수

	int GetSize() { return size; } // 현재 vec의 원소 갯수를 리턴하는 함수

	// 도전과제
	// 로비 시스템, Room - Player, Add, Remove 유저가 방에 들어갔다 나왔다.
	// Player - Inventory - Item system
};