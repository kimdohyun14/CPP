#include <stdio.h>

// Call-by-value ����
void Swap(int n1, int n2) {
	int temp = n1;
	n1 = n2;
	n2 = temp;
}


// �ܼ��� �Ű����� ���̿������� ���� ��ȭ�� �Ͼ�� ������ ����� ����.
int main() {
	int num1 = 10, num2 = 20;
	printf("����Ǳ� �� num1 : %d, num2 : %d \n", num1, num2);
	Swap(num1, num2);
	printf("����� �� num1 : %d, num2 : %d \n", num1, num2);
	return 0;
}