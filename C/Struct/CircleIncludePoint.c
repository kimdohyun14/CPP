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
	Circle c3 = { 1 }; // 초기화하지 않은 일부 멤버에 대해서는 0으로 초기화가 진행된다.
	ShowCircleInfo(&c1);
	ShowCircleInfo(&c2);
	ShowCircleInfo(&c3);
	return 0;
}