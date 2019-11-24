#include <stdio.h>

struct point {
	int xpos;
	int ypos;
};

int main() {
	struct point arr[3]; // 구조체 배열의 선언
	int i;

	for (i = 0; i < 3; i++) {
		printf("점의 좌표 입력 : ");
		scanf("%d %d", &arr[i].xpos, &arr[i].ypos); // 구조체 배열에 접근 방법
	}

	for (i = 0; i < 3; i++)
		printf("(%d, %d) \n", arr[i].xpos, arr[i].ypos);
	return 0;
}