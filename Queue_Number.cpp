#include <stdio.h>
#include <Windows.h>
#include <conio.h>

int main()
{
	//큐 배열 공간 5로 선언, 4까지 사용하고 나머지 1공간은 인덱스가 포화상태인지 아닌지 판단하기 위해 남겨놓음.
	int Queue[5] = { 0, };
	int RearIndexOfStack = 0;
	int FrontIndexOfStack = 0;

	int InputMenu = 0;
	int InputNumber = 0;

	while (true)
	{
		printf("[1] PUSH / [2] POP \n");
		scanf_s("%d", &InputMenu);

		if (InputMenu == 1)
		{
			printf("\nPUSH 선택, 넣을 숫자를 입력하세요. \n");
			scanf_s("%d", &InputNumber);

			printf("\n입력한 숫자 : %d", InputNumber);

			if (RearIndexOfStack <= 4)
			{
				Queue[RearIndexOfStack] = InputNumber;
				RearIndexOfStack++;
			}
			else
			{
				printf("\nQueue의 공간이 초과되었습니다.");
				RearIndexOfStack = 0;
			}

			printf(" (Rear 인덱스넘버 : %d)", RearIndexOfStack);
			printf("\n");
		}
		else if (InputMenu == 2)
		{
			if (FrontIndexOfStack < 4)
			{
				int result = Queue[FrontIndexOfStack];
				printf("POP 된 숫자 : %d", result);
				Queue[FrontIndexOfStack] = 0;
				FrontIndexOfStack++;
			}
			else
			{
				printf("\n더이상 Queue공간에 뺄 값이 존재하지 않습니다.");
				FrontIndexOfStack = 0;
			}

			printf(" (Front 인덱스넘버 : %d)", FrontIndexOfStack);
			printf("\n");
		}
		printf("-------------------------------------\n");
		printf("큐의 내용 : \n");
		for (int i = 0; i < 4; i++)
		{
			printf("[%d]", Queue[i]);
		}
		printf("\n");
		printf("-------------------------------------\n");
	}
}