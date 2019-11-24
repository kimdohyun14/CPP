#include <stdio.h>

// 새로운 이름의 부여 typedef 선언
typedef int INT;
typedef int* PTR_INT;

typedef unsigned int UINT;
typedef unsigned int* PTR_UINT;

typedef unsigned char UCHAR;
typedef unsigned char* PTR_UCHAR;

int main() {
	INT num1 = 120; // int num1과 동일
	PTR_INT pnum1 = &num1; // int * pnum1과 동일

	UINT num2 = 190;
	PTR_UINT pnum2 = &num2;

	UCHAR ch = 'Z';
	PTR_UCHAR pch = &ch;

	printf("%d, %u, %c \n", *pnum1, *pnum2, *pch);
	return 0;
}