#include <stdio.h>

void SoSimpleFunc(void) {
	printf("I'm so simple");
}

int main() {
	int num = 20;
	void* ptr; // void 포인터 : 무엇이든 담을 수 있는 바구니 역할

	ptr = &num; // num의 주소 값 저장
	printf("%p \n", ptr);

	ptr = SoSimpleFunc; // 함수 SoSimpleFunc의 주소 값 저장
	printf("%p \n", ptr);
	return 0;
}

// void 포인터 단점
// 포인터 연산 불가능.
// 값의 변경이나 참조도 불가능.

// 다만, 메모리 동적 할당과 깊은 관계가 있다.