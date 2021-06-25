// prototype : 원형(원래 모양, 시제품)
// 함수들의 선언 순서 영향을 안받음.
// 한 눈에 어떤 동작(함수)들이 있는지 알 수 있다.

#include <cstdio>
/* 선언 부분, 함수 이름, 형, 매개변수만 적고 기능 구현은 안함 */
void walk(int distance);
void rotate(int angle);
void drawSquare();

int main() {
	drawSquare();
	return 0;
}

/* 정의 부분 */
// 걷기
void walk(int distance) {
	printf("%dcm를 걸었습니다.\n", distance);
}

// 돌기
void rotate(int angle) {
	printf("%d도 회전했습니다.\n", angle);
}

void drawSquare() {
	for (int i = 0; i < 4; i++) {
		walk(10);
		rotate(90);
	}
}