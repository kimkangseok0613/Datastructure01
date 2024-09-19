#include "lectures.h"
#include "MyVector.h"
#include "RandomNumber.h"

// 학습목표 : 가변배열(Vector) - Array List
// 
// 벡터(Vector)
// 자주 사용하는 자료구조 중 하나입니다. Linked List, Array List((Vector)
// 배열의 특징을 모두 갖는다.
// int arr[10];
// 연산자 오버로딩으로 구현	[], ==, !=
// 
// 연결 리스트 VS 가변 배열
// 
//							| 자료구조의 크기 변경기능 | 중간삽입, 삭제기능	| 순차 접근 기능	| 랜덤 접근 기능
// 연결 리스트(Linked List)	|			O			 |		   O		|		O		|		X
// 가변 배열 (Vector)		|			O			 |		   X		|		O		|		O
// 플레이어의 인벤토리 -> 연결 리스트 버전 Inventory, Vector Inventory
// 
// 정리 : 크게 중간 삽입 기능과 랜덤 접근 기능으로 두 자료구조의 차이점을 말할 수 있다.
// 중간 삽입, 삭제가 없거나 적게 발생하는 경우에는 Vector를 사용하면 좋다.
// 중간 삽입, 삭제가 자주 발생하는 경우에는 연결 리스트를 사용하면 좋다.

void lecture5()
{
	MyVector<float> i_vec(20);
	MyVector<int> i_vec2;
	MyVector<float> i_vec3;

	if (i_vec != i_vec3)
	{
		std::cout << "연산자 오버로딩이 정상적으로 구현됨";
	}

	i_vec.push_back(0.1f);
	i_vec.push_back(0.2f);
	i_vec.push_back(0.3f);
	i_vec.Print();

	int r_index = R_number(0, i_vec.GetSize());
	std::cout << "i_vec 랜덤 원소에 접근 : " << r_index + 1 << std::endl;

	std::cout << "랜덤 값 : " << i_vec[r_index] << std::endl;

	std::cout << "i_vec 0번째 원소에 접근" << i_vec[0] << std::endl;

	std::cout << "private 선언된 vec에 직접 접근함 : " << i_vec.GetVector()[0] << std::endl;

	i_vec.pop_back();
	i_vec.Print();

	// 간단한 도전과제
	// vector의 특징. 임의의 원소에 접근하는 시간이 0(1);
	// vector 랜덤 원소에 접근하는 기능 구현
	//int randomNumber = <<		srand(time(nullptr)); rand() % 100 + 1;	난수 seed	C++ <random>

}