#include <stdio.h>

struct person {
	char name[20];
	char phoneNum[20];
	int age;
};

// ����ü �迭 ���� �߰�ȣ ���ؼ� �ʱ�ȭ�� �����ϴ�.
int main() {
	struct person arr[3] = {
		{"�ٳ���","010-1234-5678", 21},  // ù ��° ��� �ʱ�ȭ
		{"���ݸ�", "123-4567-8901", 22}, // �� ��°
		{"������","134-587-3123", 23}    // �� ��°
	};

	int i;
	for (i = 0; i < 3; i++)
		printf("%s, %s, %d \n", arr[i].name, arr[i].phoneNum, arr[i].age);
	return 0;
}