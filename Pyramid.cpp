#include <stdio.h>

/// <summary>
/// for문을 활용하여 피라미드를 출력하세요
/// </summary>
int main(void)
{
	int height = 5;

	for (int i = 1; i <= height; i++)
	{
		// 빈칸 규칙적으로 채워넣기
		for (int j = 1; j <= height-i; j++)				// j = 1 / 1 <= 5-1 = 4 -> 0000
		{												// j = 2 / 2 <= 5-2 = 3 -> 000
			printf(" ");
		}

		// i의 값이 *를 출력하는 횟수
		for (int k = 1; k <= (k - 1) * 2 + 1; k++)		// k = 1 / 1 - 1 * 2 + 1 = 1	 *
		{												// k = 2 / 2 - 1 * 2 + 1 = 3	***
			printf("*");								// k = 3 / 3 - 1 * 2 + 1 = 5   *****
		}

		printf("\n");
	}

	return 0;
}