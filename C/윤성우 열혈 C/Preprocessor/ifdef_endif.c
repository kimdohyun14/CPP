#include <stdio.h>
//#define ADD 1
#define MIN 0
//#define STAR -1

// #ifdef...#endif�� ��ũ�ΰ� ���ǵǾ����� �ڵ� �����̰�, �ƴϸ� �ڵ� ������ �Ѵ�.
// #ifndef...#endif�� ��ũ�ΰ� ���ǵ��� �ʾҴٸ� �ڵ� �����̰�, �ƴϸ� ������ �Ѵ�.

int main() {
	int num1, num2;
	printf("�� ���� ���� �Է� : ");
	scanf("%d %d", &num1, &num2);

#ifdef ADD // ��ũ�� ADD�� ���ǵǾ��ٸ�
	printf("%d + %d = %d \n", num1, num2, num1 + num2);
#endif

#ifdef MIN // ��ũ�� MIN�� ���ǵǾ��ٸ�
	printf("%d - %d = %d \n", num1, num2, num1 - num2);
#endif

#ifndef STAR // ��ũ�� STAR�� ���ǵ��� �ʾҴٸ�
	printf("**********************\n");
#endif

	return 0;
}