#include <stdio.h>
//#define STNUM(Y, S, P) YSP
//#define STNUM(Y, S, P) Y S P
//#define STNUM(Y ,S ,P) ((Y)*100000+(S)*1000+(P))
#define STNUM(Y, S, P) Y ## S ## P

// 매크로 ##연산자를 이용하면 필요한 형태대로 단순하게 결합하는 것이 가능하다.

int main() {
	printf("학번: %d \n", STNUM(10, 65, 175));
	printf("학번: %d \n", STNUM(10, 65, 075));
	return 0;
}