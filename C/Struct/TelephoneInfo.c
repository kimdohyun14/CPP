#include <stdio.h>
#include <string.h>

// ����ü�� ����� �迭�� ����Ǹ� �迭�� ���ٹ����
// �����ͷ� ����Ǹ� �������� ���ٹ���� �̿��ϸ� �ȴ�.

struct person {
	char name[20];
	char phoneNum[20];
	int age;
};

int main() {
	struct person man1, man2;
	strcpy(man1.name, "�赵��");
	strcpy(man1.phoneNum, "010-1234-5678");
	man1.age = 25;

	printf("�̸� �Է� : "); scanf("%s", man2.name);
	printf("��ȭ��ȣ �Է� : "); scanf("%s", man2.phoneNum);
	printf("���� �Է� : "); scanf("%d", &man2.age);

	printf("�̸�: %s \n", man1.name);
	printf("��ȣ: %s \n", man1.phoneNum);
	printf("����: %d \n", man1.age);

	printf("�̸�: %s \n", man2.name);
	printf("��ȣ: %s \n", man2.phoneNum);
	printf("����: %d \n", man2.age);
	return 0;
}