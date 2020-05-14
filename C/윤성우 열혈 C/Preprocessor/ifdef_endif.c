#include <stdio.h>
//#define ADD 1
#define MIN 0
//#define STAR -1

// #ifdef...#endif는 매크로가 정의되었으면 코드 삽입이고, 아니면 코드 삭제를 한다.
// #ifndef...#endif는 매크로가 정의되지 않았다면 코드 삽입이고, 아니면 삭제를 한다.

int main() {
	int num1, num2;
	printf("두 개의 정수 입력 : ");
	scanf("%d %d", &num1, &num2);

#ifdef ADD // 매크로 ADD가 정의되었다면
	printf("%d + %d = %d \n", num1, num2, num1 + num2);
#endif

#ifdef MIN // 매크로 MIN가 정의되었다면
	printf("%d - %d = %d \n", num1, num2, num1 - num2);
#endif

#ifndef STAR // 매크로 STAR가 정의되지 않았다면
	printf("**********************\n");
#endif

	return 0;
}