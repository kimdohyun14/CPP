#include <stdio.h>
#include <string.h>

// ���ڿ��� �����̴� �Լ� strcat, strncat

// strncpy �Լ��� �޸� strncat �Լ��� ���ڿ��� ���� �� ���ڸ� �ڵ����� �������ش�.
int main() {
	char str1[20] = "First~";
	char str2[20] = "Second";

	char str3[20] = "Simple num: ";
	char str4[20] = "1234567890";

	// case 1
	strcat(str1, str2);
	puts(str1);

	// case 2
	strncat(str3, str4, 7); // str4 ���ڿ� �� �ִ� 7���� str3�� �����̱�.
	puts(str3);
	return 0;
}