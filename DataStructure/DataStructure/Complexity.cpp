#include "Complexity.h"

void Print()
{

}

void lecture1()
{
	// 시간 복잡도의 단순 계산1.

	// 1~n 까지의 합을 구하기 위한 해결 방법 - 시간 복잡도를 비교해보았다.

	float s = 0.0f;					// 연산 1번.
	for (int i = 0; i < 10; i++)	// (비교 1번, 덧셈 1번, 증감 연산 1) * n(10)
	{
		s += i;
	}								// 3n + 1번 연산  시간 복잡도 : 0(n)
	std::cout << "0부터 10까지의 합 : " << s << std::endl;

	// n의 범위를 아주 크게 해보겠습니다. 1 ~ 1억 덧셈. -> 3억 + 1 연산

	// 시간 복잡도의 단순 계산 1-2.      1 ~ n 더하기 : n(n+1)/2

	int sum = 0;
	int count = 100;
	sum = sum + 1;
	sum = sum / 2;
	sum = sum * count;		// 시간 복잡도 : 5 0(1);

	// 시간 복잡도를 계산하기 위한 방법 : 빅오 계산법
	// Best Case : 빅 오메가
	// Worst Case : 빅오 표기법
	// 평균 Case : 빅 세타

	// 빅오 표기법의 특징
	// 1. 가장 큰 차수 n^3+n^2+n+1	// 10억 x 10억 x 10억 
	// 2. 자주 사용하는 빅오의 차이

	// (빠른 순서) 0(1) < 0(log n) < 0(n) < 0(n log n) < 0(n^2) < o(n!)
	// a를 숫자를 n번 곱해서 = x		a^n = x		n = log aX;
	// 특정 수를 n번 나누었을때 언제 1이 되는지 구한다.
}

// 공간 복잡도 예시
float abc(float a, float b, float c)
{
	return(a + b + c + c + a + (a + a + c) / (a + b) + 4.0);

	// 공간 복잡도 : 0(문제 해결과 전혀 관계없는 메모리 공간)
}

float Sum(float a[], int n)
{
	float result = 0.0f;
	for (int i = 0; i <= n; i++)
	{
		result += a[i];
	}
	return result;			// a[] = n, n(1), r(1), i(1) => n + 3
}

// C언어가 처음 나왔을때.. 최근 하드웨어가 매우 발달을 했습니다.
// NASA 우주비행사asdfasdf