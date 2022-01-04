#include <stdio.h>

/// 세 값의 최솟값을 구하는 함수 min3를 작성하세요.
int min3(int a, int b, int c)
{
	// 초기값 a로 삽입
	int min = a;

	if (min >= b) min = b;	// b와 비교, b가 min보다 값이 작거나 같다면 교체
	if (min >= c) min = c;	// c와 비교, c가 ...

	return min;
}

/// 네 값의 최솟값을 구하는 함수 min4를 작성하세요.
int min4(int a, int b, int c, int d)
{
	// 초기값 a로 삽입
	int min = a;

	if (min >= b) min = b;	// b와 비교, b가 min보다 값이 작거나 같다면 교체
	if (min >= c) min = c;	// c와 비교, c가 ...
	if (min >= d) min = d;	// d와 비교, d가 ...

	return min;
}

int main(void)
{
	int a = 4;
	int b = 3;
	int c = 2;
	int d = 1;

	printf("min3(%d, %d, %d) = %d\n", a, b, c, min3(a, b, c));
	printf("min4(%d, %d, %d, %d) = %d\n", a, b, c, d, min4(a, b, c, d));

	return 0;
}