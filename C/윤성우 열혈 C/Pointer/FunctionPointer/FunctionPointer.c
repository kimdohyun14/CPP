#include <stdio.h>

void SimpleAdder(int n1, int n2) {
	printf("%d + %d = %d \n", n1, n2, n1 + n2);
}

void ShowString(const char* str) {
	printf("%s \n", str);
}

int main() {
	char* str = "Function Pointer"; // 상수 형태의 문자열
	int num1 = 10, num2 = 20;

	// 반환형이 void, 2개의 int 매개변수를 가질 때
	// 다음과 같이 함수 포인터를 정의할 수 있다
	void (*fptr1)(int, int) = SimpleAdder;
	void (*fptr2)(char*) = ShowString;

	/* 함수 포인터 변수에 의한 호출 */
	fptr1(num1, num2);
	fptr2(str);
	return 0;
}