#include <stdio.h>

int main() {
	int ch;

	while (1) {
		ch = getchar(); // ���� �Է�
		if (ch == EOF) // EOF (End of File) ������ ���� ǥ��
			break;
		putchar(ch);  // ���� ���
	}
	return 0;
}

// ���� ���� Ż�� CTRL + Z