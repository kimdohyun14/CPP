#include <stdio.h>

struct point {
	int xpos;
	int ypos;
};

struct person {
	char name[20];
	char phoneNum[20];
	int age;
};

// ����ü ������ �ʱ�ȭ�� ����� ���ÿ� �ʱ�ȭ�� �����ϴ�.
// �ʱ�ȭ �������� ���ڿ� ������ ���ؼ� strcpy�Լ��� ȣ������ �ʾƵ� �ʱ�ȭ�� �ȴٴ� ���̴�.
int main() {
	struct point pos = { 10,20 };
	struct person man = { "�赵��", "010-1234-5678", 25 };
	printf("%d %d \n", pos.xpos, pos.ypos);
	printf("%s %s %d \n", man.name, man.phoneNum, man.age);
	return 0;
}