#include <stdio.h>

// Call-by-reference�� ����������, swap�� ���� �ʴ� ���
void SwapIntPtr(int* p1, int* p2) {
	// p1�� p2�� ptr1�� ptr2���� ������ �����ϱ� ����
	int* temp = p1;
	p1 = p2;
	p2 = temp;
}

int main() {
	int num1 = 10, num2 = 20;
	int* ptr1 = &num1;
	int* ptr2 = &num2;
	printf("���� �� *ptr1 : %d , *ptr2 : %d \n", *ptr1, *ptr2);
	SwapIntPtr(ptr1, ptr2);
	printf("���� �� *ptr1 : %d , *ptr2 : %d \n", *ptr1, *ptr2);

	check(ptr1);
	printf("%d \n", *ptr1);
	return 0;
}