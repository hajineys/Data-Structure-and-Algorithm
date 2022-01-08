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
void SumGauss(int n, int sum)
{
	// 전체 정수 개수 구하기
	int range = n + 1;

	// 정수의 개수가 짝수일 경우
	if (n % 2 == 0)
	{
		// 이 숫자에 전체 정수 개수를 2로 나눈 수를 곱한다
		range *= (range / 2);

		sum = range;
	}
	// 홀수일 경우
	else
	{
		int middleNumber = range / 2;	// 1과 n사이의 중간 숫자를 구한다

		// n의 절반을 총 정수 개수에 곱한다
		// int형 변수기 때문에 소수점 뒷 자리는 날라간다
		range *= (n / 2);	

		sum = range + middleNumber;		// 남은 중간 숫자를 최종적으로 더해준다
	}

	printf("가우스의 덧셈 : %d", sum);
}

/// <summary>
/// 1부터 n까지의 정수 합을 구하는 알고리즘
/// </summary>
int main(void)
{
	int i = 1;	// 반복을 제어하기 위한 변수, 1로 초기화
	int n = 0;	// 원하는 숫자
	int sum = 0;	// 합계

	scanf_s("%d", &n);

	SumWhile(i, n, sum);
	printf("\n");
	SumFor(i, n, sum);
	printf("\n");
	SumGauss(n, sum);
}
