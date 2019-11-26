#include <stdio.h>
#define STRING_JOB(A, B) #A "의 직업은 " #B "입니다."

// 문자열 내에서 매크로의 매개변수 치환은 #연산자를 이용하는 것이다.

int main() {
	printf("%s \n", STRING_JOB(김도현, 프로그래머));
	printf("%s \n", STRING_JOB(방탄소년단, 아이돌));
	return 0;
}