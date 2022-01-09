#include <stdio.h>

/// <summary>
/// 두 변수 a, b에 정수를 입력하고, b-a를 출력하는 프로그램
/// 
/// do문 while(제어식) 사용
/// </summary>
int main(void)
{
	int a = 0;
	int b = 0;

	scanf_s("%d", &a);
	printf("a의 값 : %d\n", a);

	do
	{
		scanf_s("%d", &b);
		printf("b의 값 : %d\n", b);

		if (b < a)
		{
			printf("a보다 큰 값을 입력하세요!\n");
		}
	} while (b < a);	// b가 a의 값보다 작다면 계속 진행!(계속 조건)

	printf("b - a는 %d입니다.", b - a);
}