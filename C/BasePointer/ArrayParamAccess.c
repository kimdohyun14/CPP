#include <stdio.h>

// �Լ� �������� ���ڷ� ���޵� �迭�� ���̸� ����� �� ���� ������
// �Լ��� ȣ���� �� �̸� �迭�� ���̸� ����ؼ� ���ڷ� �Ѱ�����Ѵ�.
void ShowArrayElem(int* param, int len) {
	int i;
	for (i = 0; i < len; i++)
		printf("%d ", param[i]);
	printf("\n");
}

// �迭�� �ּ� ���� �̿��ؼ� �ش� �޸� ������ �����ؼ� �����͸� �����Ѵ�.
// �̴� �迭�� �ּ� ���� �˰��ִٸ� ��𼭵� �迭�� �����ؼ� ����� ���� �����ϰ� ���氡���ϴ�.
void AddArrayElem(int* param, int len, int add) {
	int i;
	for (i = 0; i < len; i++)
		param[i] += add;
}

int main() {
	int arr[3] = { 1,2,3 };
	AddArrayElem(arr, sizeof(arr) / sizeof(int), 1);
	ShowArrayElem(arr, sizeof(arr) / sizeof(int));
	return 0;
}