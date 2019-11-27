#include <stdio.h>

// 외부에 선언 및 정의되었다고 컴파일러에게 알려준다.
extern void Increment();
extern int GetNum();

int main() {
	printf("num: %d \n", GetNum());
	Increment();
	printf("num: %d \n", GetNum());
	Increment();
	printf("num: %d \n", GetNum());
	return 0;
}