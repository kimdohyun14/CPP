#include <stdio.h>

// �����͸� ������� �ϴ� ���� �� ���ҿ����� �����ϴ�.

int main() {

	int* ptr1 = 0x0010;
	double* ptr2 = 0x0010;

	printf("Origin : %p, %p \n", ptr1, ptr2);

	// �߿��� �� ptr1, ptr2 ��ü�� ���� �ٲ�� ���� �ƴϴ�.
	printf("%p, %p \n", ptr1 + 1, ptr2 + 1); // 4���� 8����
	printf("%p, %p \n", ptr1 + 2, ptr2 + 2); // 8���� 16����

	// �̹����� ������ ������ ����� �� ��ü�� �����Ű�� �����̴�.
	printf("Origin : %p, %p \n", ptr1, ptr2);
	ptr1++; // 4����
	ptr2++; // 8����
	printf("%p, %p \n", ptr1, ptr2);
	return 0;
}