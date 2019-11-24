#include <stdio.h>

typedef struct point {
	int xpos;
	int ypos;
}Point;

// 함수의 인자로 구조체 변수가 전달될 수 있다.
// 전달되는 구조체 변수의 값은 매개변수에 통째로 복사된다.
void ShowPosition(Point pos) {
	printf("(%d, %d) \n", pos.xpos, pos.ypos);
}

// 마찬가지로 구조체를 반환할 수 있다.
Point GetCurrentPosition() {
	Point cen;
	printf("Input current pos: ");
	scanf("%d %d", &cen.xpos, &cen.ypos);
	return cen;
}

int main() {
	Point curPos = GetCurrentPosition();
	ShowPosition(curPos);
	return 0;
}