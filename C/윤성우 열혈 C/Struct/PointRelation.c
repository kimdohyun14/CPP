#include <stdio.h>

struct point {
	int xpos;
	int ypos;
	struct point* ptr; // type형 구조체 변수의 멤버로 type형 포인터 변수를 가질 수 있다.
};

int main() {
	struct point pos1 = { 1,1 };
	struct point pos2 = { 2,2 };
	struct point pos3 = { 3,3 };

	pos1.ptr = &pos2; // pos1과 pos2를 연결
	pos2.ptr = &pos3; // pos2와 pos3을 연결
	pos3.ptr = &pos1; // pos3와 pos1을 연결

	printf("점의 연결관계는? \n");
	printf("(%d, %d)와 (%d, %d) 연결 \n",
		pos1.xpos, pos1.ypos, pos1.ptr->xpos, pos1.ptr->ypos);
	printf("(%d, %d)와 (%d, %d) 연결 \n",
		pos2.xpos, pos2.ypos, pos2.ptr->xpos, pos2.ptr->ypos);
	printf("(%d, %d)와 (%d, %d) 연결 \n",
		pos3.xpos, pos3.ypos, pos3.ptr->xpos, pos3.ptr->ypos);
	return 0;
}