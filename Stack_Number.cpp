#include <stdio.h>
#include <Windows.h>

int main()
{	
	//������ ���� �� 4ĭ���� ����
	int Stack[4] = { 0, };
	int IndexOfStack = 0;

	int InputMenu = 0;
	int InputNumber = 0;

	while (true)
	{
		printf("[1] PUSH / [2] POP \n");
		scanf_s("%d", &InputMenu);

		//1���� ������ PUSH
		if (InputMenu == 1)
		{
			printf("\nPUSH ����, ���� ���ڸ� �Է��ϼ���. \n");
			scanf_s("%d", &InputNumber);

			printf("\n�Է��� ���� : %d", InputNumber);
			printf("\n");

			Stack[IndexOfStack] = InputNumber;
			if (IndexOfStack < 4)
			{
				IndexOfStack++;
			}
			//������ Index�ѹ��� 4�ʰ��̸� ������ �� á�ٰ� �ν��ϰ� �� �̻� PUSH �Ұ�
			else
			{
				printf("Stack�� ������ �ʰ��Ǿ����ϴ�.\n");
			}
		}

		//2���� ������ POP
		else if (InputMenu == 2)
		{
			if (IndexOfStack > 0)
			{
				int result = Stack[IndexOfStack - 1];
				Stack[IndexOfStack - 1] = 0;
				printf("POP �� �� : %d\n", result);
				IndexOfStack--;
			}
			//������ Index�ѹ��� 0�̸� ���̻� ���� �������� �ʴ´� �ν��ϰ� �� �̻� POP �Ұ�
			else
			{
				printf("���̻� Stack������ �� ���� �������� �ʽ��ϴ�.\n");
			}
		}
		printf("-------------------------------------\n");
		printf("������ ���� : \n");

		//���� ���� ��� 
		for (int i = 0; i < 4; i++)
		{
			printf("[%d]", Stack[i]);
		}

		//���� Index�ѹ� ǥ��
		printf(" (���� �ε����ѹ� : %d) \n", IndexOfStack);
		printf("-------------------------------------");
		printf("\n\n");
	}
}