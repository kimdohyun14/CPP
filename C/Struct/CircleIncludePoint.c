#include <stdio.h>

typedef struct point {
	int xpos;
	int ypos;
}Point;

typedef struct circle {
	Point cen;
	double rad;
}Circle;

void ShowCircleInfo(Circle* cptr) {
	printf("(%d, %d) \n", (cptr->cen).xpos, (cptr->cen).ypos);
	printf("radius: %g \n", cptr->rad);
}

int main() {
	Circle c1 = { {1,2}, 3.5 };
	Circle c2 = { 2, 4, 3.9 };
	Circle c3 = { 1 }; // �ʱ�ȭ���� ���� �Ϻ� ����� ���ؼ��� 0���� �ʱ�ȭ�� ����ȴ�.
	ShowCircleInfo(&c1);
	ShowCircleInfo(&c2);
	ShowCircleInfo(&c3);
	return 0;
}