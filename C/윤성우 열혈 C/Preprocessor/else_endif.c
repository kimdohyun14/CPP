#include <stdio.h>
#define HIT_NUM 5

// #if에는 추가적으로 #else를 삽입할 수 있다.

int main() {
#if HIT_NUM==5 // #if는 참과 거짓을 따지는 매크로이기 때문에 비교연산이 올 수 있다.
	puts("매크로 상수 HIT_NUM은 현재 5입니다.");
#else
	puts("매크로 상수 HIT_NUM은 현재 5가 아닙니다.");
#endif

	return 0;
}