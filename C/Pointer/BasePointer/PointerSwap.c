#include <stdio.h>

// �����͸� ���� �����ϴ� ����

int main() {
	int num1 = 10, num2 = 20;
	int* ptr1 = &num1;
	int* ptr2 = &num2;
	int* temp;

	(*ptr1) += 10;
	(*ptr2) -= 10;

	printf("����Ǳ� ��\n");
	printf("%d %d \n", *ptr1, *ptr2);

	// Swap ����
	temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;

	printf("����� ��\n");
	printf("%d %d \n", *ptr1, *ptr2);
	return 0;
}