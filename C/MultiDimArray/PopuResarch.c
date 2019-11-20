#include <stdio.h>

// 핵심은 1차원 배열을 이용해서 구현할 수 있지만,
// 2차원적 모델의 문제를 해결하기 위해서는 2차원 배열을 선언하는 것이 바람직하다.

int main() {
	int villa[4][2];
	int popu, i, j;

	/* 가구별 거주인원 입력 받기 */
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 2; j++) {
			printf("%d층 %d호 인구수: ", i + 1, j + 1);
			scanf("%d", &villa[i][j]);
		}
	}

	/* 빌라의 층별 인구수 출력하기 */
	for (i = 0; i < 4; i++) {
		popu = 0;
		popu += villa[i][0];
		popu += villa[i][1];
		printf("%d층 인구수 : %d \n", i + 1, popu);
	}
	return 0;
}