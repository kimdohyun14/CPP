#include <stdio.h>

// �ؽ�Ʈ ������ + ���̳ʸ� ������ => �ϳ��� ���ڿ��� ���� ���Ͽ� �����Ѵ�.

int main() {
	char name[10];
	char sex;
	int age;

	FILE* fp = fopen("friend.txt", "wt");
	int i;

	if (fp == NULL) {
		puts("���Ͽ��� ����");
		return -1;
	}

	puts("���Ͽ��� ����!");
	for (i = 0; i < 3; i++) {
		printf("�̸� ���� ���� �� �Է�: ");
		scanf("%s %c %d", name, &sex, &age); // scanf�Լ��� ���� Ű�� �Է��� �о� ������ �ʰ� �Է¹��ۿ� ���ܵιǷ�
		getchar(); // ���ۿ� �����ִ� \n�� �Ҹ��ϱ� ���ؼ� getchar �Լ��� ȣ���Ѵ�.
		fprintf(fp, "%s %c %d", name, sex, age);
	}
	fclose(fp);
	return 0;
}