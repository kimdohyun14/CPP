// prototype : ����(���� ���, ����ǰ)
// �Լ����� ���� ���� ������ �ȹ���.
// �� ���� � ����(�Լ�)���� �ִ��� �� �� �ִ�.

#include <cstdio>
/* ���� �κ�, �Լ� �̸�, ��, �Ű������� ���� ��� ������ ���� */
void walk(int distance);
void rotate(int angle);
void drawSquare();

int main() {
	drawSquare();
	return 0;
}

/* ���� �κ� */
// �ȱ�
void walk(int distance) {
	printf("%dcm�� �ɾ����ϴ�.\n", distance);
}

// ����
void rotate(int angle) {
	printf("%d�� ȸ���߽��ϴ�.\n", angle);
}

void drawSquare() {
	for (int i = 0; i < 4; i++) {
		walk(10);
		rotate(90);
	}
}