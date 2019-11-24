#include <stdio.h>

typedef struct point {
	int xpos;
	int ypos;
}Point;

// Call-by-reference 형태
// 구조체의 포인터 변수도 매개변수로 선언된다.
void OrgSymTrans(Point* ptr) { // 원점 대칭
	ptr->xpos = (ptr->xpos) * -1;
	ptr->ypos = (ptr->ypos) * -1;
}

void ShowPosition(Point pos) {
	printf("(%d, %d) \n", pos.xpos, pos.ypos);
}

int main() {
	Point pos = { 7, -5 };
	OrgSymTrans(&pos); // pos의 값을 원점 대칭
	ShowPosition(pos);
	OrgSymTrans(&pos); // pos의 값을 원점 대칭
	ShowPosition(pos);
	return 0;
}