#include <stdio.h>
#define ADD 1
#define MIN 0

// #if...#endif�� ���Ǻ� �ڵ� ������ ���� �������̸�, ���̸� �ڵ尡 ���Եǰ� �ƴ϶�� �����ȴ�.

int main() {
	int num1, num2;
	printf("�� ���� ���� �Է�: ");
	scanf("%d %d", &num1, &num2);

#if ADD // ADD�� '��'�̶��
	printf("%d + %d = %d \n", num1, num2, num1 + num2);
#endif

#if MIN // MIN�� '��'�̶��
	printf("%d - %d = %d \n", num1, num2, num1 - num2);
#endif

	return 0;
}