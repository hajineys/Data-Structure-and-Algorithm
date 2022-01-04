#include <stdio.h>

/// 네 값의 최댓값을 구하는 함수 max4를 작성하세요.
int max4(int a, int b, int c, int d)
{
	// 초기값 a로 삽입
	int max = a;

	if (b >= max) max = b;	// b와 비교, b가 max보다 값이 크거나 같다면 교체
	if (c >= max) max = c;	// c와 비교, c가 ...
	if (d >= max) max = d;	// d와 비교, d가 ...

	return max;
}

int main(void)
{
	int a = 4;
	int b = 3;
	int c = 2;
	int d = 1;

	printf("max4(%d, %d, %d, %d) = %d\n", a, b, c, d, max4(a, b, c, d));

	return 0;
}