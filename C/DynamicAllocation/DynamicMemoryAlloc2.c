#include <stdio.h>
#include <stdlib.h>

/* 
	사용자로부터 정수를 입력받는다. (-1이 입력될 때까지)
	프로그램 종료직전까지 입력받은 정수 전부를 순서대로 출력한다.
	중요한 점은 사용자가 몇 개의 정수를 입력할지 모른다는데 있다.
*/
int main() {
	int arrlen = 5; // 초기 배열의 길이를 5라고 하자.
	int idx = 0;
	int i;
	int* arr = (int*)malloc(sizeof(int) * arrlen);

	while (1) {
		printf("정수 입력(quit to -1): ");
		scanf("%d", &arr[idx]);

		if (arr[idx] == -1)
			break;

		if (arrlen == idx + 1) { // 배열의 확장성을 검사한다. (넘치는지)
			printf("메모리 확장한다.\n");
			arrlen += 3;
			arr = (int*)realloc(arr, sizeof(int) * arrlen);
		}
		idx++;
	}

	for (i = 0; i < idx; i++)
		printf("%d ", arr[i]);
	free(arr);
	return 0;
}