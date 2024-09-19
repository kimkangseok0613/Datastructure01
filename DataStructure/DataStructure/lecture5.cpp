#include "lectures.h"
#include "MyVector.h"
#include "RandomNumber.h"

// �н���ǥ : �����迭(Vector) - Array List
// 
// ����(Vector)
// ���� ����ϴ� �ڷᱸ�� �� �ϳ��Դϴ�. Linked List, Array List((Vector)
// �迭�� Ư¡�� ��� ���´�.
// int arr[10];
// ������ �����ε����� ����	[], ==, !=
// 
// ���� ����Ʈ VS ���� �迭
// 
//							| �ڷᱸ���� ũ�� ������ | �߰�����, �������	| ���� ���� ���	| ���� ���� ���
// ���� ����Ʈ(Linked List)	|			O			 |		   O		|		O		|		X
// ���� �迭 (Vector)		|			O			 |		   X		|		O		|		O
// �÷��̾��� �κ��丮 -> ���� ����Ʈ ���� Inventory, Vector Inventory
// 
// ���� : ũ�� �߰� ���� ��ɰ� ���� ���� ������� �� �ڷᱸ���� �������� ���� �� �ִ�.
// �߰� ����, ������ ���ų� ���� �߻��ϴ� ��쿡�� Vector�� ����ϸ� ����.
// �߰� ����, ������ ���� �߻��ϴ� ��쿡�� ���� ����Ʈ�� ����ϸ� ����.

void lecture5()
{
	MyVector<float> i_vec(20);
	MyVector<int> i_vec2;
	MyVector<float> i_vec3;

	if (i_vec != i_vec3)
	{
		std::cout << "������ �����ε��� ���������� ������";
	}

	i_vec.push_back(0.1f);
	i_vec.push_back(0.2f);
	i_vec.push_back(0.3f);
	i_vec.Print();

	int r_index = R_number(0, i_vec.GetSize());
	std::cout << "i_vec ���� ���ҿ� ���� : " << r_index + 1 << std::endl;

	std::cout << "���� �� : " << i_vec[r_index] << std::endl;

	std::cout << "i_vec 0��° ���ҿ� ����" << i_vec[0] << std::endl;

	std::cout << "private ����� vec�� ���� ������ : " << i_vec.GetVector()[0] << std::endl;

	i_vec.pop_back();
	i_vec.Print();

	// ������ ��������
	// vector�� Ư¡. ������ ���ҿ� �����ϴ� �ð��� 0(1);
	// vector ���� ���ҿ� �����ϴ� ��� ����
	//int randomNumber = <<		srand(time(nullptr)); rand() % 100 + 1;	���� seed	C++ <random>

}