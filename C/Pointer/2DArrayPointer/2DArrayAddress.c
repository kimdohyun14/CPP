#include <stdio.h>

// 2차원 배열이름이 가리키는 것들

int main() {
	int arr2d[3][3];

	// 1행의 시작 주소
	printf("%d \n", arr2d);
	printf("%d \n", arr2d[0]);
	printf("%d \n\n", &arr2d[0][0]);

	// 2행
	printf("%d \n", arr2d[1]);
	printf("%d \n\n", &arr2d[1][0]);

	// 3행
	printf("%d \n", arr2d[2]);
	printf("%d \n\n", &arr2d[2][0]);

	// 중요한 점은
	// arr2d는 첫 번째 요소를 가리킨다. 동시에 배열 전체를 의미
	// arr2d[1]은 첫 번째 요소를 가리킨다. 그러나 1행만을 의미
	printf("sizeof(arr2d) : %d \n", sizeof(arr2d));
	printf("sizeof(arr2d[0]) : %d \n", sizeof(arr2d[0]));
	printf("sizeof(arr2d[1]) : %d \n", sizeof(arr2d[1]));
	printf("sizeof(arr2d[2]) : %d \n", sizeof(arr2d[2]));
	return 0;
}