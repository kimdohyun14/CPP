#include <stdio.h>   // printf 함수 사용때문에
#include "stdiv2.h"  // Div 구조체 사용때문에
#include "intdiv2.h" // IntDiv 함수 사용때문에

int main() {
	Div val = IntDiv(5, 2);
	printf("몫: %d \n", val.quotient);
	printf("나머지: %d \n", val.remainder);
	return 0;
}