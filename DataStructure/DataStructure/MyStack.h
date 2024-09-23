#pragma once

// �ڷᱸ�� �����̳� : Array, Vector, Linked List
// 
// ���� �����̳ʸ� �����ؼ� (�ڷḦ ����, ����) ����� �����ؼ� ���α׷��� ����ȭ�� ������ �ڷᱸ����.

// Stack �ڷᱸ��
// ���� : �����̰��� �״�.
// ��Ź�� �ٱ��Ͽ� ���� �׾Ƽ� �ѹ��� ��Ź�⿡ �������� �Ѵ�.
// ���� ���� �������� ���� �༮���� ��Ź�⿡ ����.
// ���� ù��°�� ���� �༮��(First In) ���� �������� ������. (Last Out) -> FILO
// ���� �������� ���� �༮��(Last In) ���� ���� ������.(First Out) -> LIFO
// 
// Vector ,Linked List, Array �ڷᱸ���� �� ����ϰ� �־��µ�
// Stack, Queue, Priority Queue �� ����ؾ� �ұ��?
// 
// ������ ����
// 1. Ŭ���� �����ϱⰡ ����.
// 2. LIFO �������, ������� �����մϴ�.
// 
// 1. ���� ���(Undo)	: Ctrl + z �������� ������ ���� �ʴ´ٸ�.. int count..
// 2. ���� ǥ���		: �����ϱⰡ ���ϴ�. ��ǻ�Ͱ� �б⿡ ���� ǥ���� ���� ǥ����Դϴ�.
// ex) 1 + 1 + 2	=>	   112++
// 
// �迭 ��� Stack
template <typename T>
class MyArrayStack
{
	// �ʵ�
private:
	T*	stackArray;	// ���� �����͸� �����ϱ����� �迭
	int capacity;	// ������ �ִ� ũ��
	int top;		// ���� ���� ��ܿ� �ִ� Index
	// ���
public:
	// ������
	// capacity (size : int) �ִ� ũ�⸦ �Ҵ��ϴ� �����ڸ� �����غ�����.
	// top�� ����Ű�� �ε����� "-1" : �����Ͱ� �������� ������ ǥ���ϱ� ���� �� -1
	// top�� ����Ű�� �ε����� "0"  : ����� ���� ���� �������� ǥ���� �� �ִ�.
	// stackArray�� capacity�� ���� �Ҵ����ش�.
	MyArrayStack(int size)
	{
		stackArray = new T[size];
		capacity = size;
		size--;
	}
	~MyArrayStack()
	{
		// stackArray�� null�� �ƴҶ��� �����ϼ���.
		if (stackArray != nullptr)
			delete[] stackArray;
	}

	// Resize()
	// TŸ���� newArray �����Ҵ� �մϴ�.
	// stackArray �ε��� 0���� top������ �����͸� newArray �����Ѵ�.
	// ���� stackArray delete[] ���ݴϴ�.
	// stackArray newArray�� �����ͷ� ���� �Ҵ��Ѵ�.
	// this.capacity = _capacity;

	void Resize()
	{
		T* newArray = new T[newSize];

		for (int i = 0; i < top; i++)
		{
			newArray[i] = stackArray[i];
		}
		delete[] stackArray;
		stackArray = newArray;
		capacity = newSize;
	}
	
	// IsFull()
	// top == capacity - 1

	bool IsFull() { return top == capacity - 1 ? true : false; }

	// IsEmpty()
	// top�� ����Ű�� �ִ� �༮�� "-1" true, false

	bool IsEmpty() { return top <= -1 ? true : false; }
	
	// Push()
	// ���࿡ Full�̶�� Resize( capacity * 2 );
	// stackAarray ������ �߰� [top] <-- ������ �߰�
	// top�� 1 ���� �����ش�.

	void Push(T data)
	{
		if (IsFull())
		{
			Resize(capacity * 2);
		}

		top++;
		stackArray[top] = data;
	}
	
	// Pop()
	// IsEmpty() -> ���� ���ÿ� �����Ͱ� ������ϴ� ���
	// retrun
	// top 1 ���ҽ�Ų��.

	void Pop()
	{
		if (IsEmpty())
		{
			std::cout << "���� ���ÿ� �����Ͱ� �����ϴ�. Stack is UnderFlow. ������ ����� �� �� �����ϴ�." << std::endl;
			return;
		}
		std::cout << Top() << std::endl;
		--top;
	}

	T Top() const
	{
		return stackArray[top];
	}

	void Clear()
	{
		capacity = 10;
		top = -1;
	}
};

// ������ ����Ʈ ��� Stack




void StackExample()
{
	MyArrayStack<int> mStack(10);
	mStack.Push(5);
	mStack.Push(4);
	mStack.Push(3);
	mStack.Push(2);
	mStack.Push(1);

	mStack.Pop();
	mStack.Pop();
	mStack.Pop();
	mStack.Pop();
	mStack.Pop();
}

