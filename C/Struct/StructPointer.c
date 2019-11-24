#include <stdio.h>

struct point {
	int xpos;
	int ypos;
};

int main() {
	struct point pos1 = { 1,2 };
	struct point pos2 = { 100,200 };
	struct point* pptr = &pos1; // 구조체 변수 pos1의 주소 값 저장

	(*pptr).xpos += 4; // pptr->xpos와 의미가 동일하다.
	(*pptr).ypos += 5;
	printf("(%d, %d) \n", pptr->xpos, pptr->ypos);

	pptr = &pos2; // 가리키는 대상을 pos2로 변경
	pptr->xpos += 1; // (*pptr).xpos와 의미가 동일하다.
	pptr->ypos += 2; // pptr이 가리키는 변수의 멤버 ypos의 값을 2증가하는 의미
	printf("(%d, %d) \n", pptr->xpos, pptr->ypos);
	return 0;
}