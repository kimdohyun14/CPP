#include <stdio.h>

// ���ڿ��� �����ϴ� ������ �迭�� ���ؼ� ����.

int main() {
	char* strArr[3] = { "First", "Second", "Third" }; // ��� ������ ���ڿ��� �����Ѵ�.
	printf("%s \n", strArr[0]); // strArr[0] -> First\n ���ڿ��� ù ��° ������ �ּ� ���� �̿��ؼ� ���
	printf("%s \n", strArr[1]); // strArr[1] -> Second\n ���ڿ��� ù ��° ������ �ּ� ���� �̿��ؼ� ���
	printf("%s \n", strArr[2]); // strArr[2] -> Third\n ���ڿ��� ù ��° ������ �ּ� ���� �̿��ؼ� ���
	return 0;
}