#include <stdio.h>

// 구조체 변수를 대상으로 가능한 연산
// 대입연산, &연산, sizeof연산이 있다.

typedef struct point {
	int xpos;
	int ypos;
}Point;

int main() {
	Point pos1 = { 1,2 };
	Point pos2;
	pos2 = pos1; // pos1의 멤버 대 pos2의 멤버간 복사가 진행된다.

	printf("크기 : %d \n", sizeof(pos1)); // pos1의 전체 크기 반환
	printf("(%d, %d) \n", pos1.xpos, pos1.ypos);
	printf("크기 : %d \n", sizeof(pos2)); // pos2의 전체 크기 반환
	printf("(%d, %d) \n", pos2.xpos, pos2.ypos);
	return 0;
}

// 구조체 변수간 대입연산의 결과로 멤버 대 멤버의 복사가 이뤄진다.