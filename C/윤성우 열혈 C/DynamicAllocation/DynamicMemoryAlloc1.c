#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �Է¹��� ���ڿ��� ������ ����ϱ�.
// I am a boy -> boy a am I

int main() {
	int maxlen, len, i;
	char* str;

	printf("���ڿ��� �ִ���� ���� �Է� : ");
	scanf("%d", &maxlen); // scanf�Լ��� \n�� �Է¹��ۿ� ����Ƿ�
	getchar(); // \n ������ ���� (�߿�)

	str = (char*)malloc(sizeof(char) * (maxlen + 1));
	printf("���ڿ��� �Է��ϼ��� : ");
	fgets(str, maxlen + 1, stdin); // -> ���ڿ� + \n + NULL���� ���·� �Է¹޴´�.
	str[strlen(str) - 1] = 0; // \n ������ �����ϰ� ���ڿ��� ���� �ǹ��ϴ� �ι��ڷ� ��ü�Ѵ�.
	len = strlen(str);

	for (i = len; i > 0; i--) {
		if (str[i] == ' ') { // ������ ������ �Ǹ�
			printf("%s ", &str[i + 1]); // ������ �տ��� ���� �ܾ �о���̰�
			str[i] = 0; // �о���̰� �� �� �� �κ��� �� ���ڷ� ��ü�ؼ� �̹� ��µ� �ܾ�� �����ϵ��� �Ѵ�.
		}
	}
	printf("%s", &str[0]);
	free(str);
	return 0;
}