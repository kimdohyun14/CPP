#include <stdio.h>

void SoSimpleFunc(void) {
	printf("I'm so simple");
}

int main() {
	int num = 20;
	void* ptr; // void ������ : �����̵� ���� �� �ִ� �ٱ��� ����

	ptr = &num; // num�� �ּ� �� ����
	printf("%p \n", ptr);

	ptr = SoSimpleFunc; // �Լ� SoSimpleFunc�� �ּ� �� ����
	printf("%p \n", ptr);
	return 0;
}

// void ������ ����
// ������ ���� �Ұ���.
// ���� �����̳� ������ �Ұ���.

// �ٸ�, �޸� ���� �Ҵ�� ���� ���谡 �ִ�.