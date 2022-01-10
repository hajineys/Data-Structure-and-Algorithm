#include <stdio.h>

int main(void)
{
	int i = 0;
	int j = 0;

	printf("----------- 곱셈표 ------------\n");
	printf(" X |");
	for (int k = 1; k <= 9; k++)
	{
		printf("%3d", k);
	}

	printf("\n");
	printf("---+---------------------------\n");

	// 행 루프
	for (i = 1; i <= 9; i++)
	{
		printf("%2d |", i);

		// 열 루프
		for (j = 1; j <= 9; j++)
		{
			printf("%3d", i * j);
		}

		printf("\n");
	}

	return 0;
}