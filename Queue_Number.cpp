#include <stdio.h>
#include <Windows.h>
#include <conio.h>

int main()
{
	//ť �迭 ���� 5�� ����, 4���� ����ϰ� ������ 1������ �ε����� ��ȭ�������� �ƴ��� �Ǵ��ϱ� ���� ���ܳ���.
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
			printf("\nPUSH ����, ���� ���ڸ� �Է��ϼ���. \n");
			scanf_s("%d", &InputNumber);

			printf("\n�Է��� ���� : %d", InputNumber);

			if (RearIndexOfStack <= 4)
			{
				Queue[RearIndexOfStack] = InputNumber;
				RearIndexOfStack++;
			}
			else
			{
				printf("\nQueue�� ������ �ʰ��Ǿ����ϴ�.");
				RearIndexOfStack = 0;
			}

			printf(" (Rear �ε����ѹ� : %d)", RearIndexOfStack);
			printf("\n");
		}
		else if (InputMenu == 2)
		{
			if (FrontIndexOfStack < 4)
			{
				int result = Queue[FrontIndexOfStack];
				printf("POP �� ���� : %d", result);
				Queue[FrontIndexOfStack] = 0;
				FrontIndexOfStack++;
			}
			else
			{
				printf("\n���̻� Queue������ �� ���� �������� �ʽ��ϴ�.");
				FrontIndexOfStack = 0;
			}

			printf(" (Front �ε����ѹ� : %d)", FrontIndexOfStack);
			printf("\n");
		}
		printf("-------------------------------------\n");
		printf("ť�� ���� : \n");
		for (int i = 0; i < 4; i++)
		{
			printf("[%d]", Queue[i]);
		}
		printf("\n");
		printf("-------------------------------------\n");
	}
}