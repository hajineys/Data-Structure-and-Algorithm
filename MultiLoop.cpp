#include <stdio.h>

int main(void)
{
	int i = 0;
	int j = 0;

#pragma region 곱셈표
	printf("----------- 곱셈표 ------------\n");
	printf(" X |");
	for (int k = 1; k <= 9; k++)
	{
		printf("%3d", k);	// 행
	}

	printf("\n---+---------------------------\n");

	// 열 루프(세로)
	for (i = 1; i <= 9; i++)
	{
		printf("%2d |", i);

		// 행 루프(가로)
		for (j = 1; j <= 9; j++)
		{
			printf("%3d", i * j);
		}

		printf("\n");
	}
#pragma endregion

	printf("\n");

#pragma region 덧셈표
	printf("----------- 덧셈표 ------------\n");
	printf(" + |");
	for (int k = 1; k <= 9; k++)
	{
		printf("%3d", k);	// 행
	}

	printf("\n---+---------------------------\n");

	// 열 루프(세로) 
	for (i = 1; i <= 9; i++)
	{
		printf("%2d |", i);

		// 행 루프(가로)
		for (j = 1; j <= 9; j++)
		{
			printf("%3d", i + j);
		}

		printf("\n");
	}
#pragma endregion

	return 0;
}