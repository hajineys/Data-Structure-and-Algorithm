#include <stdio.h>

int SumOf(int a, int b)
{
	int min = 0;
	int max = 0;
	int range = 0;

	// a보다 b가 크다면
	if (a < b)
	{
		min = a;
		max = b;
	}
	// b보다 a가 크다면
	else if (b < a)
	{
		min = b;
		max = a;
	}
	else
	{
		// a+b
		return a;
	}

	// min와 max사이 정수의 개수를 구한다.
	range = (max + 1) - min;

	// 정수의 개수가 짝수면
	if (range % 2 == 0)
	{
		// min + max 값에 총 개수 / 2 만큼 곱한다.
		return (min + max) * (range / 2);
	}
	// 정수의 개수가 홀수면
	else
	{
		// 중간 값을 추가로 더해준다.
		return ((min + max) * (range / 2)) + ((min + max) / 2);
	}
}

/// <summary>
/// 특정 정수 a부터 b까지의 정수 합을 구하는 알고리즘
/// </summary>
int main(void)
{
	int a = 0;
	int b = 0;
	int sum = 0;

	scanf_s("%d", &a);
	scanf_s("%d", &b);

	printf("%d", SumOf(a, b));
}