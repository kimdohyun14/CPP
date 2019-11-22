#include <stdio.h>

// Call-by-reference ����
void Swap(int* ptr1, int* ptr2) {
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

// �ּ� ���� �����ϴ� ���·� ���ڸ� �ѱ�� �Ǹ� ������� ����ȴ�.
int main() {
	int num1 = 10, num2 = 20;
	printf("����Ǳ� �� num1 : %d, num2 : %d \n", num1, num2);
	Swap(&num1, &num2);
	printf("����� �� num1 : %d, num2 : %d \n", num1, num2);
	return 0;
}