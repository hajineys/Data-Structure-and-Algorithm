#include <stdio.h>

/// <summary>
/// 양의 정수를 입력하고 자릿수를 출력하는 프로그램
/// </summary>
int main(void)
{
	int number = 0;
	int digits = 0;

	do
	{
		scanf_s("%d", &number);

		if (0 <= number)
		{
			printf("양의 정수 : %d\n", number);
		}
		else
		{
			printf("그 수는 양의 정수가 아닙니다. 다시 입력하세요\n");
		}
	} while (number <= 0);

	while (number > 0)
	{
		// 입력한 숫자가 0보다 작아질때까지 계속 10을 나눈다.
		number /= 10;

		// 숫자의 자릿수 만큼 +1이 된다.
		digits++;
	}

	printf("그 수는 %d자리입니다.", digits);
}