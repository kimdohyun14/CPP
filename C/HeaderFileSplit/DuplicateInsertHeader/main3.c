#include <stdio.h>   // printf �Լ� ��붧����
#include "stdiv2.h"  // Div ����ü ��붧����
#include "intdiv2.h" // IntDiv �Լ� ��붧����

int main() {
	Div val = IntDiv(5, 2);
	printf("��: %d \n", val.quotient);
	printf("������: %d \n", val.remainder);
	return 0;
}