#include <stdio.h>

// 정수의 합 While 버전
void SumWhile(int i, int n, int sum)
{
	// i가 n보다 크거나 같을 때까지 반복
	while (i <= n)
	{
		sum += i;
		i++;		// i를 1씩 증가시켜준다.
	}

	printf("sum = %d\n", sum);
	printf("최종 i의 값은 %d이다\n", i);
}

// 정수의 합 For 버전
void SumFor(int i, int n, int sum)
{
	/// n이 3이면 '1 + 2 + 3 = 6'로 출력하는 코드 작성
	for (i; i <= n; i++)
	{
		sum += i;

		if (i < n)	// i가 n보다 작으면
		{
			printf("%d + ", i);
		}
		else
		{
			printf("%d", i);
		}
	}

	// 최종 합계
	printf(" = %d\n", sum);
}

// 정수의 합 가우스의 덧셈 버전
void SumGauss(int i, int n, int sum)
{
	// 정수의 개수가 짝수일 경우
	if (n % 2 == 0)
	{
		// 맨 끝의 숫자에 1을 더하고
		n += 1;

		// 이 숫자에 전체 정수 개수를 2로 나눈 수를 곱한다
		n *= (n / 2);

		sum = n;
	}
	else
	{
		// 홀수일 경우
	}

	printf("가우스의 덧셈 : %d", sum);
}

/// <summary>
/// 1부터 n까지의 정수 합을 구하는 알고리즘
/// </summary>
int main(void)
{
	int i = 1;		// 반복을 제어하기 위한 변수, 1로 초기화
	int n = 0;		// 원하는 숫자
	int sum = 0;	// 합계

	scanf_s("%d", &n);

	SumWhile(i, n, sum);
	printf("\n");
	SumFor(i, n, sum);
	printf("\n");
	SumGauss(i, n, sum);
}