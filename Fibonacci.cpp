#include <stdio.h>

// 피보나치 수열 구현 함수(위키백과 참고)
int Fibonacci(int num)
{
	int result = 0;

	// 첫째 및 둘째 항은
	if (num == 0 || num == 1)
	{
		return 1;	// 1이다
	}
	// 그 뒤의 모든 항은 바로 앞 두 항의 합인 수열이다.
	else
	{
		return Fibonacci(num - 1) + Fibonacci(num - 2);
	}
}

int main(void)
{
	int number = 0;

	scanf_s("%d", &number);

	// n항에 따른 값을 차례로 출력
	for (int i = 0; i <= number; i++)
	{
		printf("%d", Fibonacci(i));
		printf(" ");
	}
}