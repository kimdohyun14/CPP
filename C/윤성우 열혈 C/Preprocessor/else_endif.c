#include <stdio.h>
#define HIT_NUM 5

// #if���� �߰������� #else�� ������ �� �ִ�.

int main() {
#if HIT_NUM==5 // #if�� ���� ������ ������ ��ũ���̱� ������ �񱳿����� �� �� �ִ�.
	puts("��ũ�� ��� HIT_NUM�� ���� 5�Դϴ�.");
#else
	puts("��ũ�� ��� HIT_NUM�� ���� 5�� �ƴմϴ�.");
#endif

	return 0;
}