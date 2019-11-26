#include <stdio.h>
#define ADD 1
#define MIN 0

// #if...#endif는 조건부 코드 삽입을 위한 지시자이며, 참이면 코드가 삽입되고 아니라면 삭제된다.

int main() {
	int num1, num2;
	printf("두 개의 정수 입력: ");
	scanf("%d %d", &num1, &num2);

#if ADD // ADD가 '참'이라면
	printf("%d + %d = %d \n", num1, num2, num1 + num2);
#endif

#if MIN // MIN가 '참'이라면
	printf("%d - %d = %d \n", num1, num2, num1 - num2);
#endif

	return 0;
}