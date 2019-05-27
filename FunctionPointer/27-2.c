#include <stdio.h>

int SimpleAddOne(int num)
{
	return num + 1;
}

int AddTwoNumber(int n1, int n2)
{
	return n1 + n2;
}

int main(void)
{
	int(*fctPtrOne)(int);
	int(*fctPtrTwo)(int, int);

	fctPtrOne = SimpleAddOne;
	fctPtrTwo = AddTwoNumber;

	printf("10 + 1 = %d \n", fctPtrOne(10));
	printf("10 + 20 = %d \n\n", fctPtrTwo(10,20));

	printf("10 + 1 = %d \n", (*fctPtrOne)(10));
	printf("10 + 20 = %d \n\n", (*fctPtrTwo)(10, 20));
	return 0;
}