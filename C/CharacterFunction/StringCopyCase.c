#include <stdio.h>
#include <string.h>

// ���ڿ��� �����ϴ� �Լ��� strcpy, strncpy

int main() {
	char str1[20] = "1234567890";
	char str2[20];
	char str3[5];

	// case 1
	strcpy(str2, str1);
	puts(str2);

	// case 2
	// strncpy�� �ܼ��ϰ� ���ڿ��� ���縸 ����, �� ���ڰ� ���ԵǾ��ִ��� �˻縦 ���� �ʴ´�.
	strncpy(str3, str1, sizeof(str3)); 
	puts(str3);

	// case 3
	// �迭�� ���� ���̺��� �ϳ� ���� ���� �����ؼ� �� ���ڰ� ���Ե� ������ �����Ѵ�.
	strncpy(str3, str1, sizeof(str3) - 1);
	str3[sizeof(str3) - 1] = 0; // �� ���� ����(�ƽ�Ű �ڵ� �� 0)
	puts(str3);
	return 0;
}