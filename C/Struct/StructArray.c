#include <stdio.h>

struct point {
	int xpos;
	int ypos;
};

int main() {
	struct point arr[3]; // ����ü �迭�� ����
	int i;

	for (i = 0; i < 3; i++) {
		printf("���� ��ǥ �Է� : ");
		scanf("%d %d", &arr[i].xpos, &arr[i].ypos); // ����ü �迭�� ���� ���
	}

	for (i = 0; i < 3; i++)
		printf("(%d, %d) \n", arr[i].xpos, arr[i].ypos);
	return 0;
}