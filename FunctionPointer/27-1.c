#include <stdio.h>

void FuncOne(void)
{
	printf("FuncOne 함수가 호출되었다! \n");
}

void FuncTwo(void)
{
	printf("FuncTwo 함수가 호출되었다! \n");
}

int main()
{
	FuncOne();
	FuncTwo();
	printf("FuncOne의 주소 값 : %#x \n", FuncOne);
	printf("FuncTwo의 주소 값 : %#x \n", FuncTwo);
	return 0;
}