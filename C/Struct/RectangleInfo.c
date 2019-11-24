#include <stdio.h>

typedef struct point {
	int xpos;
	int ypos;
}Point;

typedef struct rectangle {
	// 직사각형을 표현하기 위해서는 필요한 점의 개수는 2개
	Point ul; // 좌 상단
	Point lr; // 우 하단
}Rectangle;

void ShowRectangleArea(Rectangle rect) {
	printf("직사각형 넓이 : %d \n",
		(rect.lr.xpos - rect.ul.xpos) * (rect.lr.ypos - rect.ul.ypos));
}

void ShowRectangleLocation(Rectangle rect) {
	printf("좌 상단: (%d, %d) \n", rect.ul.xpos, rect.ul.ypos);
	printf("좌 하단: (%d, %d) \n", rect.ul.xpos, rect.lr.ypos);
	printf("우 상단: (%d, %d) \n", rect.lr.xpos, rect.ul.ypos);
	printf("우 하단: (%d, %d) \n", rect.lr.xpos, rect.lr.ypos);
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