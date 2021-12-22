#include <stdio.h>
#include <Windows.h>

int main()
{	
	//스택의 공간 총 4칸으로 설정
	int Stack[4] = { 0, };
	int IndexOfStack = 0;

	int InputMenu = 0;
	int InputNumber = 0;

	while (true)
	{
		printf("[1] PUSH / [2] POP \n");
		scanf_s("%d", &InputMenu);

		//1번을 누르면 PUSH
		if (InputMenu == 1)
		{
			printf("\nPUSH 선택, 넣을 숫자를 입력하세요. \n");
			scanf_s("%d", &InputNumber);

			printf("\n입력한 숫자 : %d", InputNumber);
			printf("\n");

			Stack[IndexOfStack] = InputNumber;
			if (IndexOfStack < 4)
			{
				IndexOfStack++;
			}
			//스택의 Index넘버가 4초과이면 공간이 다 찼다고 인식하고 더 이상 PUSH 불가
			else
			{
				printf("Stack의 공간이 초과되었습니다.\n");
			}
		}

		//2번을 누르면 POP
		else if (InputMenu == 2)
		{
			if (IndexOfStack > 0)
			{
				int result = Stack[IndexOfStack - 1];
				Stack[IndexOfStack - 1] = 0;
				printf("POP 된 값 : %d\n", result);
				IndexOfStack--;
			}
			//스택의 Index넘버가 0이면 더이상 값이 존재하지 않는다 인식하고 더 이상 POP 불가
			else
			{
				printf("더이상 Stack공간에 뺄 값이 존재하지 않습니다.\n");
			}
		}
		printf("-------------------------------------\n");
		printf("스택의 내용 : \n");

		//스택 내용 출력 
		for (int i = 0; i < 4; i++)
		{
			printf("[%d]", Stack[i]);
		}

		//현재 Index넘버 표시
		printf(" (현재 인덱스넘버 : %d) \n", IndexOfStack);
		printf("-------------------------------------");
		printf("\n\n");
	}
}