#include <stdio.h>

int main() {
	int arr[3] = { 1, 2, 3 };
	int* ptr = arr;
	printf("%d %d %d \n", *ptr, *(ptr + 1), *(ptr + 2)); // �̷��� ���·� ����� �����ϴ�.

	// ������ ���� ptr�� int�� �������̹Ƿ� ���� 1�� ������Ű��,
	// �����δ� 4�� �����ϰ� �ȴ�. double�� ��쿡�� 8�� ����.
	// �߿��� ���� arr[i] == *(arr + i) �� ���̴�.
	printf("%d \n", *ptr); ptr++;
	printf("%d \n", *ptr); ptr++;
	printf("%d \n", *ptr); ptr--;
	printf("%d \n", *ptr); ptr--;
	printf("%d \n", *ptr); 
	return 0;
}

// �߰������� �Ʒ��� ��������?
/*
	*(++ptr) = 20; // ptr�� ����� �� ��ü�� �����ϰ� �ǰ�
	*(ptr+1) = 20; // ptr�� ����� ���� ������� �ʰ� �ȴ�.
*/