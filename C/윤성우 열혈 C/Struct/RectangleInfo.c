#include <stdio.h>

typedef struct point {
	int xpos;
	int ypos;
}Point;

typedef struct rectangle {
	// ���簢���� ǥ���ϱ� ���ؼ��� �ʿ��� ���� ������ 2��
	Point ul; // �� ���
	Point lr; // �� �ϴ�
}Rectangle;

void ShowRectangleArea(Rectangle rect) {
	printf("���簢�� ���� : %d \n",
		(rect.lr.xpos - rect.ul.xpos) * (rect.lr.ypos - rect.ul.ypos));
}

void ShowRectangleLocation(Rectangle rect) {
	printf("�� ���: (%d, %d) \n", rect.ul.xpos, rect.ul.ypos);
	printf("�� �ϴ�: (%d, %d) \n", rect.ul.xpos, rect.lr.ypos);
	printf("�� ���: (%d, %d) \n", rect.lr.xpos, rect.ul.ypos);
	printf("�� �ϴ�: (%d, %d) \n", rect.lr.xpos, rect.lr.ypos);
}

int main() {
	Rectangle rec1 = { {1,1}, {4,4} };
	Rectangle rec2 = { {0,0}, {7,5} };
	ShowRectangleArea(rec1);
	ShowRectangleLocation(rec1);
	ShowRectangleArea(rec2);
	ShowRectangleLocation(rec2);
	return 0;
}