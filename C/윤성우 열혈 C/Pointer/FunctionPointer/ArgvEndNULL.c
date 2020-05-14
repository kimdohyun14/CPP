#include <stdio.h>

// 배열의 마지막에는 NULL이 삽입된다는 것을 알 수 있다.
int main(int argc, char* argv[]) {
	int i = 0;
	printf("전달된 문자열의 수 : %d \n", argc);

	while (argv[i] != NULL) {
		printf("%d번째 문자열: %s \n", i + 1, argv[i]);
		i++;
	}
	return 0;
}